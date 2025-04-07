#include "leetcode.hpp"

/* 2414. 最长的字母序连续子字符串的长度

字母序连续字符串 是由字母表中连续字母组成的字符串。
换句话说，字符串 "abcdefghijklmnopqrstuvwxyz" 的任意子字符串都是 字母序连续字符串 。

例如，"abc" 是一个字母序连续字符串，而 "acb" 和 "za" 不是。

给你一个仅由小写英文字母组成的字符串 s ，返回其 最长 的 字母序连续子字符串 的长度。

示例 1：
输入：s = "abacaba"
输出：2
解释：共有 4 个不同的字母序连续子字符串 "a"、"b"、"c" 和 "ab" 。
"ab" 是最长的字母序连续子字符串。

示例 2：
输入：s = "abcde"
输出：5
解释："abcde" 是最长的字母序连续子字符串。

提示：
  1 <= s.length <= 10^5
  s 由小写英文字母组
*/

int longestContinuousSubstring(string s)
{
	int cur = 1, ans = 1;
	for (size_t i = 1, end = s.size(); i < end; ++i) {
		if (s[i - 1] + 1 == s[i]) {
			++cur;
			ans = max(ans, cur);
		} else
			cur = 1;
	}
	return ans;
}

int main()
{
	ToOut(longestContinuousSubstring("abacaba"));
	ToOut(longestContinuousSubstring("abcde"));
}
