﻿#include "leetcode.hpp"

/* 1312. 让字符串成为回文串的最少插入次数

给你一个字符串 s ，每一次操作你都可以在字符串的任意位置插入任意字符。

请你返回让 s 成为回文串的 最少操作次数 。

「回文串」是正读和反读都相同的字符串。

示例 1：
输入：s = "zzazz"
输出：0
解释：字符串 "zzazz" 已经是回文串了，所以不需要做任何插入操作。

示例 2：
输入：s = "mbadm"
输出：2
解释：字符串可变为 "mbdadbm" 或者 "mdbabdm" 。

示例 3：
输入：s = "leetcode"
输出：5
解释：插入 5 个字符后字符串变为 "leetcodocteel" 。

示例 4：
输入：s = "g"
输出：0

示例 5：
输入：s = "no"
输出：1

提示：
  1 <= s.length <= 500
  s 中所有字符都是小写字母。
*/

// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/discuss/470684/C++-Simple-DP-(Memoization)-and-Bottom-up-with-O(n)-Space
// 抄的
int minInsertions(string s)
{
	int size = static_cast<int>(s.size());
	vector<vector<int>> dp(size, vector<int>(size));
	for (int len = 2; len <= size; ++len)
		for (int h = 0; h <= size - len; ++h) {
			int i = h + len - 1;
			if (s[h] == s[i])
				dp[h][i] = dp[h + 1][i - 1];
			else
				dp[h][i] = 1 + min(dp[h + 1][i], dp[h][i - 1]);
		}
	return dp[0][size - 1];
}

int main()
{
	ToOut(minInsertions("zzazz"));
	ToOut(minInsertions("mbadm"));
	ToOut(minInsertions("leetcode"));
	ToOut(minInsertions("g"));
	ToOut(minInsertions("no"));
}
