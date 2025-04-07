﻿#include "leetcode.hpp"

/* 2444. 统计定界子数组的数目

给你一个整数数组 nums 和两个整数 minK 以及 maxK 。

nums 的定界子数组是满足下述条件的一个子数组：
  子数组中的 最小值 等于 minK 。
  子数组中的 最大值 等于 maxK 。
  返回定界子数组的数目。

子数组是数组中的一个连续部分。

示例 1：
输入：nums = [1,3,5,2,7,5], minK = 1, maxK = 5
输出：2
解释：定界子数组是 [1,3,5] 和 [1,3,5,2] 。

示例 2：
输入：nums = [1,1,1,1], minK = 1, maxK = 1
输出：10
解释：nums 的每个子数组都是一个定界子数组。共有 10 个子数组。

提示：
  2 <= nums.length <= 10^5
  1 <= nums[i], minK, maxK <= 10^6
*/

long long countSubarrays(vector<int> const& A, int minK, int maxK)
{
	long long ans = 0;
	int len = static_cast<int>(A.size());
	int minidx = -1, maxidx = -1, sindex = 0;
	for (int i = 0; i < len; ++i) {
		if (A[i] == minK)
			minidx = i;
		if (A[i] == maxK)
			maxidx = i;
		if (A[i] < minK || A[i] > maxK) {
			sindex = i + 1;
			minidx = maxidx = -1;
		}
		if (minidx != -1 && maxidx != -1)
			ans += min(minidx, maxidx) - sindex + 1;
	}
	return ans;
}

int main()
{
	ToOut(countSubarrays({1, 3, 5, 2, 7, 5}, 1, 5));
	ToOut(countSubarrays({1, 1, 1, 1}, 1, 1));
}
