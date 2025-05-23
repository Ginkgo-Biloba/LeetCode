﻿#include "leetcode.hpp"

/* 2384. 最大回文数字

给你一个仅由数字（0 - 9）组成的字符串 num 。

请你找出能够使用 num 中数字形成的 最大回文 整数，并以字符串形式返回。该整数不含 前导零 。

注意：
  你 无需 使用 num 中的所有数字，但你必须使用 至少 一个数字。
  数字可以重新排序。

示例 1：
输入：num = "444947137"
输出："7449447"
解释：
从 "444947137" 中选用数字 "4449477"，可以形成回文整数 "7449447" 。
可以证明 "7449447" 是能够形成的最大回文整数。

示例 2：
输入：num = "00009"
输出："9"
解释：
可以证明 "9" 能够形成的最大回文整数。
注意返回的整数不应含前导零。

提示：
  1 <= num.length <= 10^5
  num 由数字（0 - 9）组成
*/

string largestPalindromic(string num)
{
	int count[10] = {};
	for (int i : num)
		++count[i - '0'];
	string a;
	for (int i = 9; i >= 0; --i) {
		if (i == 0 && a.empty())
			break;
		for (; count[i] > 1; count[i] -= 2)
			a.push_back(static_cast<char>(i + '0'));
	}
	string b = a;
	std::reverse(b.begin(), b.end());
	for (int i = 9; i >= 0; --i)
		if (count[i] > 0) {
			a.push_back(static_cast<char>(i + '0'));
			break;
		}
	return a + b;
}

int main()
{
	ToOut(largestPalindromic("444947137"));
	ToOut(largestPalindromic("00009"));
	ToOut(largestPalindromic("00977"));
	ToOut(largestPalindromic("00"));
}
