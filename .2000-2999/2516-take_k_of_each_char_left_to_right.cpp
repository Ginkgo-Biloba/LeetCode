﻿#include "leetcode.hpp"

/* 2516. 每种字符至少取 K 个

给你一个由字符 'a'、'b'、'c' 组成的字符串 s 和一个非负整数 k 。
每分钟，你可以选择取走 s 最左侧 还是 最右侧 的那个字符。

你必须取走每种字符 至少 k 个，返回需要的 最少 分钟数；如果无法取到，则返回 -1 。

示例 1：
输入：s = "aabaaaacaabc", k = 2
输出：8
解释：
从 s 的左侧取三个字符，现在共取到两个字符 'a' 、一个字符 'b' 。
从 s 的右侧取五个字符，现在共取到四个字符 'a' 、两个字符 'b' 和两个字符 'c' 。
共需要 3 + 5 = 8 分钟。
可以证明需要的最少分钟数是 8 。

示例 2：
输入：s = "a", k = 1
输出：-1
解释：无法取到一个字符 'b' 或者 'c'，所以返回 -1 。

提示：
  1 <= s.length <= 10^5
  s 仅由字母 'a'、'b'、'c' 组成
  0 <= k <= s.length
*/

int takeCharacters(string s, int k)
{
	int n = static_cast<int>(s.size());
	int count[3] {};
	for (int i : s)
		count[i - 'a'] += 1;
	if (count[0] < k || count[1] < k || count[2] < k)
		return -1;

	int h = 0, i = 0;
	for (; i < n; ++i) {
		int x = s[i] - 'a';
		count[x] -= 1;
		if (count[0] < k || count[1] < k || count[2] < k)
			count[s[h++] - 'a'] += 1;
	}
	return n - (i - h);
}

int main()
{
	ToOut(takeCharacters("aabaaaacaabc", 2));
	ToOut(takeCharacters("a", 1));
}
