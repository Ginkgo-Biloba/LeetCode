﻿#include "leetcode.hpp"

/* 1170. 比较字符串最小字母出现频次

我们来定义一个函数 f(s)，其中传入参数 s 是一个非空字符串；该函数的功能是统计 s 中（按字典序比较）最小字母的出现频次。

例如，若 s = "dcce"，那么 f(s) = 2，因为最小的字母是 "c"，它出现了 2 次。

现在，给你两个字符串数组待查表 queries 和词汇表 words，请你返回一个整数数组 answer 作为答案，其中每个 answer[i] 是满足 f(queries[i]) < f(W) 的词的数目，W 是词汇表 words 中的词。

示例 1：
输入：queries = ["cbd"], words = ["zaaaz"]
输出：[1]
解释：查询 f("cbd") = 1，而 f("zaaaz") = 3 所以 f("cbd") < f("zaaaz")。

示例 2：
输入：queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
输出：[1,2]
解释：第一个查询 f("bbb") < f("aaaa")，第二个查询 f("aaa") 和 f("aaaa") 都 > f("cc")。

提示：
  1 <= queries.length <= 2000
  1 <= words.length <= 2000
  1 <= queries[i].length, words[i].length <= 10
  queries[i][j], words[i][j] 都是小写英文字母
*/

class Solution {
	int f(string const& s)
	{
		int n = 0, x = 'z';
		for (char c : s) {
			if (c < x) {
				x = c;
				n = 0;
			}
			if (c == x)
				++n;
		}
		return n;
	}

public:
	vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words)
	{
		vector<int> Q, W;
		W.reserve(words.size());
		for (string const& s : words)
			W.push_back(f(s));
		sort(W.begin(), W.end());

		Q.reserve(queries.size());
		for (string const& s : queries) {
			int n = f(s);
			Q.push_back(static_cast<int>(W.end()
				- upper_bound(W.begin(), W.end(), n)));
		}
		return Q;
	}
};

int main() { }
