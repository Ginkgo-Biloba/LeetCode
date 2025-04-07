﻿#include "leetcode.hpp"

/* 3. 无重复字符的最长子串

给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:
输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/

int lengthOfLongestSubstring(string s)
{
	int len = static_cast<int>(s.length());
	int b[128] = {0};
	int h = 0, i = 0, ans = 0;
	for (; i < len; ++i) {
		if (b[static_cast<int>(s[i])]) {
			ans = max(ans, i - h);
			while (s[h] != s[i]) {
				b[static_cast<int>(s[h])] = 0;
				++h;
			}
			++h;
		} else
			b[static_cast<int>(s[i])] = 1;
	}
	ans = max(ans, len - h);
	return ans;
}

int main()
{
	ToOut(lengthOfLongestSubstring("abcabcbb"));
	ToOut(lengthOfLongestSubstring("bbbbb"));
	ToOut(lengthOfLongestSubstring("pwwkew"));
	ToOut(lengthOfLongestSubstring(""));
}
