﻿#include "leetcode.hpp"

/* 2131. 连接两字母单词得到的最长回文串

给你一个字符串数组 words 。
words 中每个元素都是一个包含 两个 小写英文字母的单词。

请你从 words 中选择一些元素并按 任意顺序 连接它们，并得到一个 尽可能长的回文串 。
每个元素 至多 只能使用一次。

请你返回你能得到的最长回文串的 长度 。
如果没办法得到任何一个回文串，请你返回 0 。

回文串 指的是从前往后和从后往前读一样的字符串。

示例 1：
输入：words = ["lc","cl","gg"]
输出：6
解释：一个最长的回文串为 "lc" + "gg" + "cl" = "lcggcl" ，长度为 6 。
"clgglc" 是另一个可以得到的最长回文串。

示例 2：
输入：words = ["ab","ty","yt","lc","cl","ab"]
输出：8
解释：最长回文串是 "ty" + "lc" + "cl" + "yt" = "tylcclyt" ，长度为 8 。
"lcyttycl" 是另一个可以得到的最长回文串。

示例 3：
输入：words = ["cc","ll","xx"]
输出：2
解释：最长回文串是 "cc" ，长度为 2 。
"ll" 是另一个可以得到的最长回文串。"xx" 也是。

提示：
  1 <= words.length <= 10^5
  words[i].length == 2
  words[i] 仅包含小写英文字母。
*/

int longestPalindrome(vector<string> const& words)
{
	int ret = 0;
	int C[26 * 26] = {0};
	for (string const& w : words)
		if (w[0] >= w[1])
			C[(w[0] - 'a') * 26 + (w[1] - 'a')] += 1;
	for (string const& w : words) {
		if (w[0] > w[1])
			continue;
		int f = (w[0] - 'a') * 26 + (w[1] - 'a');
		int t = (w[1] - 'a') * 26 + (w[0] - 'a');
		if (C[t] > (f == t ? 1 : 0)) {
			C[f] -= 1;
			C[t] -= 1;
			ret += 4;
		}
	}
	for (int i = 0; i < 26; ++i)
		if (C[i * 26 + i]) {
			ret += 2;
			break;
		}
	return ret;
}

int main()
{
	ToOut(longestPalindrome({"lc", "cl", "gg"}));
	ToOut(longestPalindrome({"ab", "ty", "yt", "lc", "cl", "ab"}));
	ToOut(longestPalindrome({"cc", "ll", "xx"}));
	ToOut(longestPalindrome({"dd", "aa", "bb", "dd", "aa", "dd", "bb", "dd", "aa", "cc", "bb", "cc", "dd", "cc"}));
}
