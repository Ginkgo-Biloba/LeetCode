﻿#include "leetcode.hpp"

/* 890. 查找和替换模式

你有一个单词列表 words 和一个模式  pattern，你想知道 words 中的哪些单词与模式匹配。

如果存在字母的排列 p ，使得将模式中的每个字母 x 替换为 p(x) 之后，我们就得到了所需的单词，那么单词与模式是匹配的。

回想一下，字母的排列是从字母到字母的双射：每个字母映射到另一个字母，没有两个字母映射到同一个字母。

返回 words 中与给定模式匹配的单词列表。

你可以按任何顺序返回答案。

示例：
输入：words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
输出：["mee","aqq"]
解释：
"mee" 与模式匹配，因为存在排列 {a -> m, b -> e, ...}。
"ccc" 与模式不匹配，因为 {a -> c, b -> c, ...} 不是排列。
因为 a 和 b 映射到同一个字母。

提示：
  1 <= words.length <= 50
  1 <= pattern.length = words[i].length <= 20
*/

vector<string> findAndReplacePattern(vector<string>& words, string pattern)
{
	int F[256], *T = F + 128;
	vector<string> S;
	int i, len = static_cast<int>(pattern.size());

	for (string const& w : words) {
		memset(F, 0, sizeof(F));
		for (i = 0; i < len; ++i) {
			int f = w[i], t = pattern[i];
			if (F[f] == 0 && T[t] == 0) {
				F[f] = t;
				T[t] = f;
			} else if (F[f] != t || T[t] != f)
				break;
		}
		if (i == len)
			S.push_back(w);
	}

	return S;
}

int main()
{
	vector<string>
		a = {"abc", "deq", "mee", "aqq", "dkd", "ccc"};
	ToOut(findAndReplacePattern(a, "abb"));
}
