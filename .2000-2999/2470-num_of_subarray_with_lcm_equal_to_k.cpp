﻿#include "leetcode.hpp"

/* 2470. 最小公倍数等于 K 的子数组数目

给你一个整数数组 nums 和一个整数 k ，请你统计并返回 nums 的 子数组 中满足 元素最小公倍数为 k 的子数组数目。

子数组 是数组中一个连续非空的元素序列。

数组的最小公倍数 是可被所有数组元素整除的最小正整数。

示例 1 ：
输入：nums = [3,6,2,7,1], k = 6
输出：4
解释：以 6 为最小公倍数的子数组是：
- [3,6,2,7,1]
- [3,6,2,7,1]
- [3,6,2,7,1]
- [3,6,2,7,1]

示例 2 ：
输入：nums = [3], k = 2
输出：0
解释：不存在以 2 为最小公倍数的子数组。

提示：
  1 <= nums.length <= 1000
  1 <= nums[i], k <= 1000
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

int subarrayLCM(vector<int> const& A, int k)
{
	int n = static_cast<int>(A.size());
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int val = 1;
		for (int t = i; t < n; ++t) {
			val = val / gcd(val, A[t]) * A[t];
			if (k % val) break;
			ans += val == k;
		}
	}
	return ans;
}

int main()
{
	ToOut(subarrayLCM({3, 6, 2, 7, 1}, 6));
	ToOut(subarrayLCM({3}, 2));
}
