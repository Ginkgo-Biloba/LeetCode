﻿#include "leetcode.hpp"

/* 2606. 找到最大开销的子字符串

给你一个字符串 s ，一个字符 互不相同 的字符串 chars 和一个长度与 chars 相同的整数数组 vals 。

子字符串的开销 是一个子字符串中所有字符对应价值之和。空字符串的开销是 0 。

字符的价值 定义如下：
  如果字符不在字符串 chars 中，那么它的价值是它在字母表中的位置（下标从 1 开始）。
    比方说，'a' 的价值为 1 ，'b' 的价值为 2 ，以此类推，'z' 的价值为 26 。
  否则，如果这个字符在 chars 中的位置为 i ，那么它的价值就是 vals[i] 。

请你返回字符串 s 的所有子字符串中的最大开销。

示例 1：
输入：s = "adaa", chars = "d", vals = [-1000]
输出：2
解释：字符 "a" 和 "d" 的价值分别为 1 和 -1000 。
最大开销子字符串是 "aa" ，它的开销为 1 + 1 = 2 。
2 是最大开销。

示例 2：
输入：s = "abc", chars = "abc", vals = [-1,-1,-1]
输出：0
解释：字符 "a" ，"b" 和 "c" 的价值分别为 -1 ，-1 和 -1 。
最大开销子字符串是 "" ，它的开销为 0 。
0 是最大开销。

提示：
  1 <= s.length <= 10^5
  s 只包含小写英文字母。
  1 <= chars.length <= 26
  chars 只包含小写英文字母，且 互不相同 。
  vals.length == chars.length
  -1000 <= vals[i] <= 1000
*/

int maximumCostSubstring(string s,
	string chars, vector<int> const& vals)
{
	int costs[26];
	for (int i = 0; i < 26; ++i)
		costs[i] = i + 1;
	for (int i = static_cast<int>(chars.size()); i--;)
		costs[chars[i] - 'a'] = vals[i];
	int ans = 0, sum = 0;
	for (int i : s) {
		sum += costs[i - 'a'];
		sum = max(sum, 0);
		ans = max(ans, sum);
	}
	return ans;
}

int main()
{
	ToOut(maximumCostSubstring("adaa", "d", {-1000}));
	ToOut(maximumCostSubstring("abc", "abc", {-1, -1, -1}));
}
