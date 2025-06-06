﻿#include "leetcode.hpp"

/* 523. 连续的子数组和

给定一个包含非负数的数组和一个目标整数 k，编写一个函数来判断该数组是否含有连续的子数组，其大小至少为 2，总和为 k 的倍数，即总和为 n*k，其中 n 也是一个整数。

示例 1:
输入: [23,2,4,6,7], k = 6
输出: True
解释: [2,4] 是一个大小为 2 的子数组，并且和为 6。

示例 2:
输入: [23,2,6,4,7], k = 6
输出: True
解释: [23,2,6,4,7]是大小为 5 的子数组，并且和为 42。

说明:
    数组的长度不会超过10,000。
    你可以认为所有数字总和在 32 位有符号整数范围内。
*/

// https://leetcode.com/problems/continuous-subarray-sum/discuss/99506/Concise-C%2B%2B-solution-use-set-instead-of-map
// 抄的
bool checkSubarraySum(vector<int>& nums, int k)
{
	int const len = static_cast<int>(nums.size());
	unordered_set<int> modk;
	int sum = 0, prev = 0;
	for (int i = 0; i < len; ++i) {
		sum += nums[i];
		int m = (k ? (sum % k) : sum);
		if (modk.find(m) != modk.end())
			return true;
		modk.insert(prev);
		prev = m;
	}
	return false;
}

int main()
{
	vector<int> nums = {23, 2, 4, 6, 7};
	ToOut(checkSubarraySum(nums, 6));
}
