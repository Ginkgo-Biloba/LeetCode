#include "leetcode.hpp"

/* 2272. 最大波动的子字符串

字符串的 波动 定义为子字符串中出现次数 最多 的字符次数与出现次数 最少 的字符次数之差。

给你一个字符串 s ，它只包含小写英文字母。
请你返回 s 里所有 子字符串的 最大波动 值。

子字符串 是一个字符串的一段连续字符序列。

示例 1：
输入：s = "aababbb"
输出：3
解释：
所有可能的波动值和它们对应的子字符串如以下所示：
- 波动值为 0 的子字符串："a" ，"aa" ，"ab" ，"abab" ，"aababb" ，"ba" ，"b" ，"bb" 和 "bbb" 。
- 波动值为 1 的子字符串："aab" ，"aba" ，"abb" ，"aabab" ，"ababb" ，"aababbb" 和 "bab" 。
- 波动值为 2 的子字符串："aaba" ，"ababbb" ，"abbb" 和 "babb" 。
- 波动值为 3 的子字符串 "babbb" 。
所以，最大可能波动值为 3 。

示例 2：
输入：s = "abcde"
输出：0
解释：
s 中没有字母出现超过 1 次，所以 s 中每个子字符串的波动值都是 0 。

提示：
  1 <= s.length <= 10^4
  s  只包含小写英文字母。
*/

// https://leetcode.cn/problems/substring-with-largest-variance/solutions/1494890/by-endlesscheng-5775/
// 抄的
int largestVariance(string s)
{
	int ans = 0;
	int diff[26][26] = {}, diff_with_b[26][26];
	memset(diff_with_b, 0x80, sizeof(diff_with_b));
	for (int ch : s) {
		ch -= 'a';
		for (int i = 0; i < 26; ++i) {
			if (i == ch) continue;
			++diff[ch][i]; // a=ch, b=i
			++diff_with_b[ch][i];
			diff_with_b[i][ch] = --diff[i][ch]; // a=i, b=ch
			diff[i][ch] = max(diff[i][ch], 0);
			ans = max(ans, max(diff_with_b[ch][i], diff_with_b[i][ch]));
		}
	}
	return ans;
}

int main()
{
	ToOut(largestVariance("aababbb"));
	ToOut(largestVariance("abcde"));
}
