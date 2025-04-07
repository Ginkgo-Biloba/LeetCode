﻿#include "leetcode.hpp"

/* 2334. 元素值大于变化阈值的子数组

给你一个整数数组 nums 和一个整数 threshold 。

找到长度为 k 的 nums 子数组，满足数组中 每个 元素都 大于 threshold / k 。

请你返回满足要求的 任意 子数组的 大小 。如果没有这样的子数组，返回 -1 。

子数组 是数组中一段连续非空的元素序列。

示例 1：
输入：nums = [1,3,4,3,1], threshold = 6
输出：3
解释：子数组 [3,4,3] 大小为 3 ，每个元素都大于 6 / 3 = 2 。
注意这是唯一合法的子数组。

示例 2：
输入：nums = [6,5,6,5,8], threshold = 7
输出：1
解释：子数组 [8] 大小为 1 ，且 8 > 7 / 1 = 7 。所以返回 1 。
注意子数组 [6,5] 大小为 2 ，每个元素都大于 7 / 2 = 3.5 。
类似的，子数组 [6,5,6] ，[6,5,6,5] ，[6,5,6,5,8] 都是符合条件的子数组。
所以返回 2, 3, 4 和 5 都可以。

提示：
  1 <= nums.length <= 10^5
  1 <= nums[i], threshold <= 10^9
*/

int validSubarraySize(vector<int>& nums, int threshold)
{
	nums.insert(nums.begin(), -1);
	nums.push_back(-1);
	int n = static_cast<int>(nums.size());
	vector<int> Q = {0};
	for (int i = 1; i < n; ++i) {
		while (nums.at(Q.back()) > nums[i]) {
			int height = nums.at(Q.back());
			Q.pop_back();
			int width = i - Q.back() - 1;
			if (height > threshold / width)
				return width;
		}
		Q.push_back(i);
	}
	return -1;
}

int main()
{
	vector<int> n1 = {1, 3, 4, 3, 1}, n2 = {6, 5, 6, 5, 8};
	ToOut(validSubarraySize(n1, 6));
	ToOut(validSubarraySize(n2, 7));
}
