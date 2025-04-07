﻿#include "leetcode.hpp"

/* 409. 最长回文串

给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。

在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。

注意:
假设字符串的长度不会超过 1010。

示例 1:
输入:
"abccccdd"
输出:
7

解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
*/

int longestPalindrome(string const& str)
{
	int const len = static_cast<int>(str.size());
	if (len == 0)
		return 0;
	int hist[128], ans = 0;
	memset(hist, 0, sizeof(hist));
	for (int i = 0; i < len; ++i)
		++(hist[(int)str[i]]);

	for (int c = 'a'; c <= 'z'; ++c)
		ans += hist[c] & ~1;
	for (int c = 'A'; c <= 'Z'; ++c)
		ans += hist[c] & ~1;
	if (ans < len) ++ans;
	return ans;
}

int main()
{
	ToOut(longestPalindrome("abccccdd"));
}
