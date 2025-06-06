﻿#include "leetcode.hpp"

/* 2427. 公因子的数目

给你两个正整数 a 和 b ，返回 a 和 b 的 公 因子的数目。

如果 x 可以同时整除 a 和 b ，则认为 x 是 a 和 b 的一个 公因子 。

示例 1：
输入：a = 12, b = 6
输出：4
解释：12 和 6 的公因子是 1、2、3、6 。

示例 2：
输入：a = 25, b = 30
输出：2
解释：25 和 30 的公因子是 1、5 。

提示：
  1 <= a, b <= 1000
*/

int commonFactors(int a, int b)
{
	if (a < b)
		std::swap(a, b);
	int ans = 0;
	int limit = static_cast<int>(sqrt(b + 1));
	for (int i = 1; i <= limit; ++i) {
		int k = b / i;
		if (i * k == b) {
			if (a % i == 0)
				++ans;
			if (i < k && a % k == 0)
				++ans;
		}
	}
	return ans;
}

int main()
{
	ToOut(commonFactors(12, 6));
	ToOut(commonFactors(25, 30));
	ToOut(commonFactors(32, 408));
}
