﻿#include "leetcode.hpp"

/* 2370. 最长理想子序列

给你一个由小写字母组成的字符串 s ，和一个整数 k 。
如果满足下述条件，则可以将字符串 t 视作是 理想字符串 ：

  t 是字符串 s 的一个子序列。
  t 中每两个 相邻 字母在字母表中位次的绝对差值小于或等于 k 。

返回 最长 理想字符串的长度。

字符串的子序列同样是一个字符串，并且子序列还满足：可以经由其他字符串删除某些字符（也可以不删除）但不改变剩余字符的顺序得到。

注意：字母表顺序不会循环。例如，'a' 和 'z' 在字母表中位次的绝对差值是 25 ，而不是 1 。

示例 1：
输入：s = "acfgbd", k = 2
输出：4
解释：最长理想字符串是 "acbd" 。该字符串长度为 4 ，所以返回 4 。
注意 "acfgbd" 不是理想字符串，因为 'c' 和 'f' 的字母表位次差值为 3 。

示例 2：
输入：s = "abcd", k = 3
输出：4
解释：最长理想字符串是 "abcd" ，该字符串长度为 4 ，所以返回 4 。

提示：
  1 <= s.length <= 10^5
  0 <= k <= 25
  s 由小写英文字母组成
*/

int longestIdealString(string s, int k)
{
	int len[128];
	memset(len, 0, sizeof(len));
	for (int b : s) {
		int val = 0;
		for (int a = 'a'; a <= 'z'; ++a)
			if (abs(a - b) <= k)
				val = max(val, len[a]);
		len[b] = val + 1;
	}
	for (int i = 'a'; i <= 'z'; ++i)
		len[0] = max(len[0], len[i]);
	return len[0];
}

int main()
{
	ToOut(longestIdealString("acfgbd", 2));
	ToOut(longestIdealString("abcd", 3));
}
