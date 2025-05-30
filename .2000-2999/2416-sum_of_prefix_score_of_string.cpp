﻿#include "leetcode.hpp"

/* 2416. 字符串的前缀分数和

给你一个长度为 n 的数组 words ，该数组由 非空 字符串组成。

定义字符串 term 的 分数 等于以 term 作为 前缀 的 words[i] 的数目。

例如，如果 words = ["a", "ab", "abc", "cab"] ，那么 "ab" 的分数是 2 ，因为 "ab" 是 "ab" 和 "abc" 的一个前缀。

返回一个长度为 n 的数组 answer ，其中 answer[i] 是 words[i] 的每个非空前缀的分数 总和 。

注意：字符串视作它自身的一个前缀。

示例 1：
输入：words = ["abc","ab","bc","b"]
输出：[5,4,3,2]
解释：对应每个字符串的答案如下：
- "abc" 有 3 个前缀："a"、"ab" 和 "abc" 。
- 2 个字符串的前缀为 "a" ，2 个字符串的前缀为 "ab" ，1 个字符串的前缀为 "abc" 。
总计 answer[0] = 2 + 2 + 1 = 5 。
- "ab" 有 2 个前缀："a" 和 "ab" 。
- 2 个字符串的前缀为 "a" ，2 个字符串的前缀为 "ab" 。
总计 answer[1] = 2 + 2 = 4 。
- "bc" 有 2 个前缀："b" 和 "bc" 。
- 2 个字符串的前缀为 "b" ，1 个字符串的前缀为 "bc" 。
总计 answer[2] = 2 + 1 = 3 。
- "b" 有 1 个前缀："b"。
- 2 个字符串的前缀为 "b" 。
总计 answer[3] = 2 。

示例 2：
输入：words = ["abcd"]
输出：[4]
解释：
"abcd" 有 4 个前缀 "a"、"ab"、"abc" 和 "abcd"。
每个前缀的分数都是 1 ，总计 answer[0] = 1 + 1 + 1 + 1 = 4 。

提示：
  1 <= words.length <= 1000
  1 <= words[i].length <= 1000
  words[i] 由小写英文字母组成
*/

class Solution {
	struct Node {
		int count;
		int child[26];
	};

	int index;
	vector<Node> buffer;

	void insert(string const& s)
	{
		int node = 0;
		for (size_t i = 0; i < s.size(); ++i) {
			int x = s[i] - 'a';
			if (buffer[node].child[x] == 0) {
				int t = ++index;
				buffer[node].child[x] = t;
				memset(&buffer[t], 0, sizeof(buffer[t]));
			}
			node = buffer[node].child[x];
			buffer[node].count += 1;
		}
	}

	int query(string const& s)
	{
		int node = 0, sum = 0;
		for (size_t i = 0; i < s.size(); ++i) {
			int x = s[i] - 'a';
			node = buffer[node].child[x];
			sum += buffer[node].count;
		}
		return sum;
	}

public:
	vector<int> sumPrefixScores(vector<string> const& words)
	{
		buffer.resize(1001 * 1001);
		memset(buffer.data(), 0, sizeof(buffer[0]));
		index = 0;
		for (size_t i = 0; i < words.size(); ++i)
			insert(words[i]);
		vector<int> ans(words.size());
		for (size_t i = 0; i < words.size(); ++i)
			ans[i] = query(words[i]);
		return ans;
	}
};

int main()
{
	vector<string>
		w1 = {"abc", "ab", "bc", "b"},
		w2 = {"abcd"};
	Solution s;
	ToOut(s.sumPrefixScores(w1));
	ToOut(s.sumPrefixScores(w2));
}
