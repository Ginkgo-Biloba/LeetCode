﻿#include "leetcode.hpp"

/* 1513. 仅含 1 的子串数

给你一个二进制字符串 s（仅由 '0' 和 '1' 组成的字符串）。

返回所有字符都为 1 的子字符串的数目。

由于答案可能很大，请你将它对 10^9 + 7 取模后返回。

示例 1：
输入：s = "0110111"
输出：9
解释：共有 9 个子字符串仅由 '1' 组成
"1" -> 5 次
"11" -> 3 次
"111" -> 1 次

示例 2：
输入：s = "101"
输出：2
解释：子字符串 "1" 在 s 中共出现 2 次

示例 3：
输入：s = "111111"
输出：21
解释：每个子字符串都仅由 '1' 组成

示例 4：
输入：s = "000"
输出：0

提示：
  s[i] == '0' 或 s[i] == '1'
  1 <= s.length <= 10^5
*/

int numSub(string s)
{
	int const MOD = static_cast<int>(1e9 + 7);
	int len = static_cast<int>(s.size());
	int ans = 0, pre = -1;
	for (int i = 0; i < len; ++i) {
		if (s[i] == '1')
			ans = (ans + i - pre) % MOD;
		else
			pre = i;
	}
	return ans;
}

int main()
{
}
