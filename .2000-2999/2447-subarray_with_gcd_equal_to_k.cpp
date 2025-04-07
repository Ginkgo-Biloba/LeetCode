﻿#include "leetcode.hpp"

/* 2447. 最大公因数等于 K 的子数组数目

给你一个整数数组 nums 和一个整数 k ，请你统计并返回 nums 的子数组中元素的最大公因数等于 k 的子数组数目。

子数组 是数组中一个连续的非空序列。

数组的最大公因数 是能整除数组中所有元素的最大整数。

示例 1：
输入：nums = [9,3,1,2,6,3], k = 3
输出：4
解释：nums 的子数组中，以 3 作为最大公因数的子数组如下：
- [9,3,1,2,6,3]
- [9,3,1,2,6,3]
- [9,3,1,2,6,3]
- [9,3,1,2,6,3]

示例 2：
输入：nums = [4], k = 7
输出：0
解释：不存在以 7 作为最大公因数的子数组。

提示：
  1 <= nums.length <= 1000
  1 <= nums[i], k <= 10^9
*/

int gcd(int a, int b)
{
	while (b) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int subarrayGCD(
	vector<int> const& A, int k)
{
	int ans = 0;
	int len = static_cast<int>(A.size());
	for (int i = 0; i < len; ++i) {
		int val = A[i];
		for (int t = i; t < len; ++t) {
			if (val % k) break;
			val = gcd(val, A[t]);
			if (val == k) ++ans;
		}
	}
	return ans;
}

int main()
{
	ToOut(subarrayGCD({9, 3, 1, 2, 6, 3}, 3));
	ToOut(subarrayGCD({4}, 7));
}
