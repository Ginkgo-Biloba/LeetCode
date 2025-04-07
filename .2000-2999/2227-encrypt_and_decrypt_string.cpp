#include "leetcode.hpp"

/* 2227. 加密解密字符串

给你一个字符数组 keys ，由若干 互不相同 的字符组成。
还有一个字符串数组 values ，内含若干长度为 2 的字符串。
另给你一个字符串数组 dictionary ，包含解密后所有允许的原字符串。
请你设计并实现一个支持加密及解密下标从 0 开始字符串的数据结构。

字符串 加密 按下述步骤进行：

  对字符串中的每个字符 c ，先从 keys 中找出满足 keys[i] == c 的下标 i 。
  在字符串中，用 values[i] 替换字符 c 。

请注意，如果 keys 中不存在字符串中的字符，则无法执行加密过程，返回空字符串 ""。

字符串 解密 按下述步骤进行：

  将字符串每相邻 2 个字符划分为一个子字符串，对于每个子字符串 s ，找出满足 values[i] == s 的一个下标 i 。如果存在多个有效的 i ，从中选择 任意 一个。这意味着一个字符串解密可能得到多个解密字符串。
  在字符串中，用 keys[i] 替换 s 。

实现 Encrypter 类：

  Encrypter(char[] keys, String[] values, String[] dictionary) 用 keys、values 和 dictionary 初始化 Encrypter 类。
  String encrypt(String word1) 按上述加密过程完成对 word1 的加密，并返回加密后的字符串。
  int decrypt(String word2) 统计并返回可以由 word2 解密得到且出现在 dictionary 中的字符串数目。

示例：
输入：
["Encrypter", "encrypt", "decrypt"]
[[['a', 'b', 'c', 'd'], ["ei", "zf", "ei", "am"], ["abcd", "acbd", "adbc", "badc", "dacb", "cadb", "cbda", "abad"]], ["abcd"], ["eizfeiam"]]
输出：
[null, "eizfeiam", 2]

解释：
Encrypter encrypter = new Encrypter(
  ['a', 'b', 'c', 'd'],
  ["ei", "zf", "ei", "am"],
  ["abcd", "acbd", "adbc", "badc", "dacb", "cadb", "cbda", "abad"]);
encrypter.encrypt("abcd"); // 返回 "eizfeiam"。
                           // 'a' 映射为 "ei"，'b' 映射为 "zf"，'c' 映射为 "ei"，'d' 映射为 "am"。
encrypter.decrypt("eizfeiam"); // return 2.
                              // "ei" 可以映射为 'a' 或 'c'，"zf" 映射为 'b'，"am" 映射为 'd'。
                              // 因此，解密后可以得到的字符串是 "abad"，"cbad"，"abcd" 和 "cbcd"。
                              // 其中 2 个字符串，"abad" 和 "abcd"，在 dictionary 中出现，所以答案是 2 。



提示：
  1 <= keys.length == values.length <= 26
  values[i].length == 2
  1 <= dictionary.length <= 100
  1 <= dictionary[i].length <= 100
  所有 keys[i] 和 dictionary[i] 互不相同
  1 <= word1.length <= 2000
  1 <= word2.length <= 200
  所有 word1[i] 都出现在 keys 中
  word2.length 是偶数
  keys、values[i]、dictionary[i]、word1 和 word2 只含小写英文字母
  至多调用 encrypt 和 decrypt 总计 200 次
*/

class Encrypter {
	struct Node {
		int leaf;
		int child[26];
	};

	int k2v[26];
	// 0 是根
	Node nodes[100 * 100 + 1];

public:
	Encrypter(vector<char> const& keys,
		vector<string> const& values, vector<string> const& dictionary)
	{
		memset(k2v, 0, sizeof(k2v));
		memset(nodes, 0, sizeof(nodes));
		for (size_t i = keys.size(); i--;) {
			int k = keys[i] - 'a';
			string v = values[i];
			k2v[k] = (v[0] << 8) | v[1];
		}

		int total = 0;
		for (string const& d : dictionary) {
			int nidx = 0;
			for (int i : d) {
				auto& node = nodes[nidx];
				if (node.child[i - 'a'] == 0)
					node.child[i - 'a'] = ++total;
				nidx = node.child[i - 'a'];
			}
			nodes[nidx].leaf += 1;
		}
	}

	string encrypt(string word)
	{
		string ans, empty;
		for (int w : word) {
			int v = k2v[w - 'a'];
			if (v == 0)
				return empty;
			ans.push_back(static_cast<char>(v >> 8));
			ans.push_back(static_cast<char>(v));
		}
		return ans;
	}

	int decrypt(string word)
	{
		vector<int> pre, cur;
		char Q[100 * 100 + 1] = {0};
		int n = static_cast<int>(word.size());
		cur.push_back(0);
		for (int i = 0; i < n; i += 2) {
			pre.swap(cur);
			cur.clear();
			int v = (word[i] << 8) | word[i + 1];
			for (int k = 0; k < 26; ++k) {
				if (k2v[k] != v)
					continue;
				for (int p : pre) {
					int c = nodes[p].child[k];
					if (c && !Q[c]) {
						Q[c] = 1;
						cur.push_back(c);
					}
				}
			}
		}
		int ans = 0;
		for (int i : cur)
			ans += nodes[i].leaf;
		return ans;
	}
};

int main()
{
	Encrypter e(
		{'a', 'b', 'c', 'd'},
		{"ei", "zf", "ei", "am"},
		{"abcd", "acbd", "adbc", "badc", "dacb", "cadb", "cbda", "abad"});
	ToOut(e.encrypt("abcd"));
	ToOut(e.decrypt("eizfeiam"));
}
