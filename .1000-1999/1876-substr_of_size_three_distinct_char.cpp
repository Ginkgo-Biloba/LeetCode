﻿#include "leetcode.hpp"

/* 1876. 长度为三且各字符不同的子字符串

如果一个字符串不含有任何重复字符，我们称这个字符串为 好 字符串。

给你一个字符串 s ，请你返回 s 中长度为 3 的 好子字符串 的数量。

注意，如果相同的好子字符串出现多次，每一次都应该被记入答案之中

子字符串 是一个字符串中连续的字符序列。

示例 1：
输入：s = "xyzzaz"
输出：1
解释：总共有 4 个长度为 3 的子字符串："xyz"，"yzz"，"zza" 和 "zaz" 。
唯一的长度为 3 的好子字符串是 "xyz" 。

示例 2：
输入：s = "aababcabc"
输出：4
解释：总共有 7 个长度为 3 的子字符串："aab"，"aba"，"bab"，"abc"，"bca"，"cab" 和 "abc" 。
好子字符串包括 "abc"，"bca"，"cab" 和 "abc" 。

提示：
  1 <= s.length <= 100
  s​​​​​​ 只包含小写英文字母。
*/

int countGoodSubstrings(string s)
{
	int n = static_cast<int>(s.size());
	int t = 0;
	for (int i = 2; i < n; ++i) {
		if (s[i - 1] == s[i]) {
			++i;
			continue;
		}
		t += (s[i - 2] != s[i]) && (s[i - 2] != s[i - 1]);
	}
	return t;
}

int main()
{
}
