﻿#include "leetcode.hpp"

/* 367. 有效的完全平方数

给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。

说明：不要使用任何内置的库函数，如  sqrt。

示例 1：
输入：16
输出：True

示例 2：
输入：14
输出：False
*/

// 整形牛顿法，参见题目 69
bool isPerfectSquare(int num)
{
	unsigned x = USHRT_MAX;
	unsigned y = num;
	while (x * x > y)
		x = (x + y / x) / 2;
	return x * x == y;
}

int main()
{
	ToOut(isPerfectSquare(15));
	ToOut(isPerfectSquare(16));
	ToOut(isPerfectSquare(17));
}
