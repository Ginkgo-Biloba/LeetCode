#include "leetcode.hpp"

/* 2157. 字符串分组

给你一个下标从 0 开始的字符串数组 words 。
每个字符串都只包含 小写英文字母 。
words 中任意一个子串中，每个字母都至多只出现一次。

如果通过以下操作之一，我们可以从 s1 的字母集合得到 s2 的字母集合，那么我们称这两个字符串为 关联的 ：
  往 s1 的字母集合中添加一个字母。
  从 s1 的字母集合中删去一个字母。
  将 s1 中的一个字母替换成另外任意一个字母（也可以替换为这个字母本身）。

数组 words 可以分为一个或者多个无交集的 组 。
如果一个字符串与另一个字符串关联，那么它们应当属于同一个组。

注意，你需要确保分好组后，一个组内的任一字符串与其他组的字符串都不关联。
可以证明在这个条件下，分组方案是唯一的。

请你返回一个长度为 2 的数组 ans ：
  ans[0] 是 words 分组后的 总组数 。
  ans[1] 是字符串数目最多的组所包含的字符串数目。

示例 1：
输入：words = ["a","b","ab","cde"]
输出：[2,3]
解释：
- words[0] 可以得到 words[1] （将 'a' 替换为 'b'）和 words[2] （添加 'b'）。所以 words[0] 与 words[1] 和 words[2] 关联。
- words[1] 可以得到 words[0] （将 'b' 替换为 'a'）和 words[2] （添加 'a'）。所以 words[1] 与 words[0] 和 words[2] 关联。
- words[2] 可以得到 words[0] （删去 'b'）和 words[1] （删去 'a'）。所以 words[2] 与 words[0] 和 words[1] 关联。
- words[3] 与 words 中其他字符串都不关联。
所以，words 可以分成 2 个组 ["a","b","ab"] 和 ["cde"] 。最大的组大小为 3 。

示例 2：
输入：words = ["a","ab","abc"]
输出：[1,3]
解释：
- words[0] 与 words[1] 关联。
- words[1] 与 words[0] 和 words[2] 关联。
- words[2] 与 words[1] 关联。
由于所有字符串与其他字符串都关联，所以它们全部在同一个组内。
所以最大的组大小为 3 。

提示：
  1 <= words.length <= 2 * 10^4
  1 <= words[i].length <= 26
  words[i] 只包含小写英文字母。
  words[i] 中每个字母最多只出现一次。
*/

class Solution {
	vector<int> Fb;
	unordered_map<int, int> uf, count;

	int find(int x)
	{
		int y = uf[x];
		if (uf[y] == y)
			return y;
		Fb.push_back(x);
		Fb.push_back(y);
		y = uf[y];
		while (uf[y] != y) {
			Fb.push_back(y);
			y = uf[y];
		}
		for (int i : Fb)
			uf[i] = y;
		Fb.clear();
		return y;
	}

	void connect(int x, int y)
	{
		x = find(x);
		y = find(y);
		uf[min(x, y)] = max(x, y);
	}

	void tryfind(int f, int t)
	{
		if (uf.find(t) != uf.end())
			connect(f, t);
	}

public:
	vector<int> groupStrings(vector<string> const& words)
	{
		uf.clear();
		count.clear();
		for (string const& w : words) {
			int m = 0;
			for (int i : w)
				m |= 1u << (i - 'a');
			count[m] += 1;
			uf[m] = m;
		}
		for (auto it : count) {
			for (int i = 0; i < 26; ++i) {
				int m = 1 << i;
				if (it.first & m) {
					// 去掉试试
					tryfind(it.first, it.first ^ m);
					// 换成别的没有的试试
					for (int j = 0; j < 26; ++j) {
						if (i == j)
							continue;
						if (it.first & (1 << j))
							continue;
						tryfind(it.first, (it.first ^ m) | (1 << j));
					}
				} else {
					// 没有就添加
					tryfind(it.first, it.first | m);
				}
			}
		}

		for (auto it : count) {
			int x = find(it.first);
			if (x != it.first)
				count[x] += it.second;
		}
		vector<int> R {0, 0};
		for (auto it : count) {
			if (it.first == uf[it.first])
				R[0] += 1;
			R[1] = max(R[1], it.second);
		}
		return R;
	}
};

int main()
{
	Solution s;
	ToOut(s.groupStrings({"a", "b", "ab", "cde"}));
	ToOut(s.groupStrings({"a", "ab", "abc"}));
}
