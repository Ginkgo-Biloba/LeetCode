﻿#include "leetcode.hpp"

/* 1317. 将整数转换为两个无零整数的和

「无零整数」是十进制表示中 不含任何 0 的正整数。

给你一个整数 n，请你返回一个 由两个整数组成的列表 [A, B]，满足：
  A 和 B 都是无零整数
  A + B = n

题目数据保证至少有一个有效的解决方案。

如果存在多个有效解决方案，你可以返回其中任意一个。

示例 1：
输入：n = 2
输出：[1,1]
解释：A = 1, B = 1. A + B = n 并且 A 和 B 的十进制表示形式都不包含任何 0 。

示例 2：
输入：n = 11
输出：[2,9]

示例 3：
输入：n = 10000
输出：[1,9999]

示例 4：
输入：n = 69
输出：[1,68]

示例 5：
输入：n = 1010
输出：[11,999]

提示：
  2 <= n <= 10^4
*/

bool no0(int x)
{
	do {
		if (x % 10 == 0)
			return false;
		x /= 10;
	} while (x);
	return true;
}

vector<int> getNoZeroIntegers(int n)
{
	vector<int> v;
	v.resize(2);
	for (v[1] = n / 2; v[1] < n; ++(v[1])) {
		v[0] = n - v[1];
		if (no0(v[0]) && no0(v[1]))
			break;
	}
	return v;
}

int main()
{
	ToOut(getNoZeroIntegers(2));
	ToOut(getNoZeroIntegers(11));
	ToOut(getNoZeroIntegers(10000));
	ToOut(getNoZeroIntegers(69));
	ToOut(getNoZeroIntegers(1010));
}
