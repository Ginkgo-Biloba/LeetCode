﻿#include "leetcode.hpp"

/* 2645. 构造有效字符串的最少插入数

给你一个字符串 word ，你可以向其中任何位置插入 "a"、"b" 或 "c" 任意次，返回使 word 有效 需要插入的最少字母数。

如果字符串可以由 "abc" 串联多次得到，则认为该字符串 有效 。

示例 1：
输入：word = "b"
输出：2
解释：在 "b" 之前插入 "a" ，在 "b" 之后插入 "c" 可以得到有效字符串 "abc" 。

示例 2：
输入：word = "aaa"
输出：6
解释：在每个 "a" 之后依次插入 "b" 和 "c" 可以得到有效字符串 "abcabcabc" 。

示例 3：
输入：word = "abc"
输出：0
解释：word 已经是有效字符串，不需要进行修改。

提示：
  1 <= word.length <= 50
  word 仅由字母 "a"、"b" 和 "c" 组成。
*/

int addMinimum(string word)
{
	int ans = 1;
	int n = static_cast<int>(word.size());
	for (int i = 1; i < n; ++i)
		ans += word[i - 1] >= word[i];
	return ans * 3 - n;
}

int main()
{
	ToOut(addMinimum("b"));
	ToOut(addMinimum("aaa"));
	ToOut(addMinimum("abc"));
}
