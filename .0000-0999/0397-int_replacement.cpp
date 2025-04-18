﻿#include "leetcode.hpp"

/* 397. 整数替换

给定一个正整数 n，你可以做如下操作：
1. 如果 n 是偶数，则用 n / 2替换 n。
2. 如果 n 是奇数，则可以用 n + 1或n - 1替换 n。
n 变为 1 所需的最小替换次数是多少？

示例 1:
输入:
8
输出:
3
解释:
8 -> 4 -> 2 -> 1

示例 2:
输入:
7
输出:
4
解释:
7 -> 8 -> 4 -> 2 -> 1
或
7 -> 6 -> 3 -> 2 -> 1
*/

// 抄的，3 真是够了
int integerReplacement(int _n)
{
	int ans = 0;
	uint32_t u = _n;

	for (; u != 1; ++ans) {
		if (u & 1) {
			if (u > 4 && (u & 3) == 3)
				u += 1;
			else
				u -= 1;
		} else
			u >>= 1;
	}
	return ans;
}

int main()
{
	ToOut(integerReplacement(100000000));
}
