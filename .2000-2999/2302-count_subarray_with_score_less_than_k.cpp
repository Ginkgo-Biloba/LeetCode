﻿#include "leetcode.hpp"

/* 2302. 统计得分小于 K 的子数组数目

一个数组的 分数 定义为数组之和 乘以 数组的长度。

  比方说，[1, 2, 3, 4, 5] 的分数为 (1 + 2 + 3 + 4 + 5) * 5 = 75 。

给你一个正整数数组 nums 和一个整数 k ，请你返回 nums 中分数 严格小于 k 的 非空整数子数组数目。

子数组 是数组中的一个连续元素序列。

示例 1：

输入：nums = [2,1,4,3,5], k = 10
输出：6
解释：
有 6 个子数组的分数小于 10 ：
- [2] 分数为 2 * 1 = 2 。
- [1] 分数为 1 * 1 = 1 。
- [4] 分数为 4 * 1 = 4 。
- [3] 分数为 3 * 1 = 3 。
- [5] 分数为 5 * 1 = 5 。
- [2,1] 分数为 (2 + 1) * 2 = 6 。
注意，子数组 [1,4] 和 [4,3,5] 不符合要求，因为它们的分数分别为 10 和 36，但我们要求子数组的分数严格小于 10 。

示例 2：

输入：nums = [1,1,1], k = 5
输出：5
解释：
除了 [1,1,1] 以外每个子数组分数都小于 5 。
[1,1,1] 分数为 (1 + 1 + 1) * 3 = 9 ，大于 5 。
所以总共有 5 个子数组得分小于 5 。

提示：
  1 <= nums.length <= 10^5
  1 <= nums[i] <= 10^5
  1 <= k <= 10^15
*/

long long countSubarrays1(vector<int> const& nums, long long k)
{
	int const n = static_cast<int>(nums.size());
	vector<long long> A(n + 1);
	for (int i = 0; i < n; ++i)
		A[i + 1] = A[i] + nums[i];
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		int lo = 0, hi = n - i;
		while (lo < hi) {
			int t = (lo + hi + 1) / 2;
			long long sum = A[i + t] - A[i];
			if (sum * t < k)
				lo = t;
			else
				hi = t - 1;
		}
		ans += lo;
	}
	return ans;
}

long long countSubarrays(vector<int> const& nums, long long k)
{
	int const n = static_cast<int>(nums.size());
	int h = 0, i = 0;
	long long ans = 0, sum = 0;
	for (; i < n; ++i) {
		sum += nums[i];
		for (; h <= i; ++h) {
			if (sum * (i - h + 1) < k)
				break;
			sum -= nums[h];
		}
		ans += i - h + 1;
	}
	return ans;
}

int main()
{
	ToOut(countSubarrays({2, 1, 4, 3, 5}, 10));
	ToOut(countSubarrays({1, 1, 1}, 5));
}
