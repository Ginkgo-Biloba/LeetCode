﻿#include "leetcode.hpp"

/* 970. 强整数

给定两个正整数 x 和 y，如果某一整数等于 x^i + y^j，其中整数 i >= 0 且 j >= 0，那么我们认为该整数是一个强整数。

返回值小于或等于 bound 的所有强整数组成的列表。

你可以按任何顺序返回答案。在你的回答中，每个值最多出现一次。

示例 1：
输入：x = 2, y = 3, bound = 10
输出：[2,3,4,5,7,9,10]
解释：
2 = 2^0 + 3^0
3 = 2^1 + 3^0
4 = 2^0 + 3^1
5 = 2^1 + 3^1
7 = 2^2 + 3^1
9 = 2^3 + 3^0
10 = 2^0 + 3^2

示例 2：
输入：x = 3, y = 5, bound = 15
输出：[2,4,6,8,10,14]

提示：
  1 <= x <= 100
  1 <= y <= 100
  0 <= bound <= 10^6
*/

vector<int> powerfulIntegers(int x, int y, int bound)
{
	vector<int> xs, ys;
	vector<char> flag(bound + 1);
	int p;
	xs.push_back(1);
	ys.push_back(1);

	if (x != 1) {
		for (p = 1; p < bound; p *= x)
			xs.push_back(p);
	}
	if (y != 1) {
		for (p = 1; p < bound; p *= y)
			ys.push_back(p);
	}
	for (int ix : xs)
		for (int iy : ys) {
			p = ix + iy;
			if (p <= bound)
				flag[p] = 1;
			else
				break;
		}

	xs.clear();
	ys.clear();
	for (int i = 1; i <= bound; ++i) {
		if (flag[i])
			xs.push_back(i);
	}
	return xs;
}

int main()
{
	ToOut(powerfulIntegers(2, 3, 10));
	ToOut(powerfulIntegers(3, 5, 15));
}
