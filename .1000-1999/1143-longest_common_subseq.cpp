﻿#include "leetcode.hpp"

/* 1143. 最长公共子序列

给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列。

一个字符串的 子序列 是指这样一个新的字符串：
它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。

例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。

若这两个字符串没有公共子序列，则返回 0。

示例 1:
输入：text1 = "abcde", text2 = "ace"
输出：3
解释：最长公共子序列是 "ace"，它的长度为 3。

示例 2:
输入：text1 = "abc", text2 = "abc"
输出：3
解释：最长公共子序列是 "abc"，它的长度为 3。

示例 3:
输入：text1 = "abc", text2 = "def"
输出：0
解释：两个字符串没有公共子序列，返回 0。

提示:
  1 <= text1.length <= 1000
  1 <= text2.length <= 1000
  输入的字符串只含有小写英文字符。
*/

int longestCommonSubsequence(string A, string B)
{
	if (A.length() > B.length())
		A.swap(B);
	int a = static_cast<int>(A.size());
	int b = static_cast<int>(B.size());
	vector<int> dp(b + 1), buf(b + 1);
	for (int i = 1; i <= a; ++i) {
		for (int k = 1; k <= b; ++k) {
			if (A[i - 1] == B[k - 1])
				buf[k] = dp[k - 1] + 1;
			else
				buf[k] = max(dp[k], buf[k - 1]);
		}
		buf.swap(dp);
	}
	return dp[b];
}

int main()
{
	ToOut(longestCommonSubsequence("abcde", "ace"));
	ToOut(longestCommonSubsequence("abc", "abc"));
	ToOut(longestCommonSubsequence("abc", "def"));
	ToOut(longestCommonSubsequence("ezupkr", "ubmrapg"));
}
