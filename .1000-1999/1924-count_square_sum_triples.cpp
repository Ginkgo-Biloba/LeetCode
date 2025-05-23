﻿#include "leetcode.hpp"

/* 1925. 统计平方和三元组的数目

一个 平方和三元组 (a,b,c) 指的是满足 a^2 + b^2 = c^2 的 整数 三元组 a，b 和 c 。

给你一个整数 n ，请你返回满足 1 <= a, b, c <= n 的 平方和三元组 的数目。

示例 1：
输入：n = 5
输出：2
解释：平方和三元组为 (3,4,5) 和 (4,3,5) 。

示例 2：
输入：n = 10
输出：4
解释：平方和三元组为 (3,4,5)，(4,3,5)，(6,8,10) 和 (8,6,10) 。

提示：
  1 <= n <= 250
*/

int countTriples(int n)
{
	int ans = 0;
	for (int a = 1; a <= n; ++a)
		for (int b = 1; b <= n; ++b) {
			int s = a * a + b * b;
			int c = (int)sqrt(s);
			ans += (c <= n) && (c * c == s);
		}
	return ans;
}

int main() { }
