﻿#include "leetcode.hpp"

/* 744. 寻找比目标字母大的最小字母

给定一个只包含小写字母的有序数组letters 和一个目标字母 target，寻找有序数组里面比目标字母大的最小字母。

数组里字母的顺序是循环的。举个例子，如果目标字母target = 'z' 并且有序数组为 letters = ['a', 'b']，则答案返回 'a'。

示例:

输入:
letters = ["c", "f", "j"]
target = "a"
输出: "c"

输入:
letters = ["c", "f", "j"]
target = "c"
输出: "f"

输入:
letters = ["c", "f", "j"]
target = "d"
输出: "f"

输入:
letters = ["c", "f", "j"]
target = "g"
输出: "j"

输入:
letters = ["c", "f", "j"]
target = "j"
输出: "c"

输入:
letters = ["c", "f", "j"]
target = "k"
输出: "c"

注:
  letters长度范围在[2, 10000]区间内。
  letters 仅由小写字母组成，最少包含两个不同的字母。
  目标字母target 是一个小写字母。
*/

char nextGreatestLetter(vector<char>& letters, char target)
{
	int hist[26];
	memset(hist, 0, sizeof(hist));
	for (char c : letters)
		++(hist[c - 'a']);
	int t = target - 'a';
	int tend = t + 26;
	for (++t; t < tend; ++t) {
		if (hist[t % 26])
			break;
	}
	return static_cast<char>((t % 26) + 'a');
}

int main()
{
}
