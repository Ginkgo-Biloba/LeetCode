﻿#include "leetcode.hpp"

/* 645. 错误的集合

集合 S 包含从1到 n 的整数。
不幸的是，因为数据错误，导致集合里面某一个元素复制了成了集合里面的另外一个元素的值，导致集合丢失了一个整数并且有一个元素重复。
给定一个数组 nums 代表了集合 S 发生错误后的结果。
你的任务是首先寻找到重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。

示例 1:
输入: nums = [1,2,2,4]
输出: [2,3]

注意:
  给定数组的长度范围是 [2, 10000]。
  给定的数组是无序的。
*/

vector<int> findErrorNums(vector<int>& nums)
{
	vector<int> ans(2);
	int i, len = static_cast<int>(nums.size());
	for (i = 0; i < len; ++i) {
		if (nums[i] == i + 1)
			continue;
		do {
			int k = nums[i];
			if (nums[i] == nums[k - 1])
				break;
			std::swap(nums[i], nums[k - 1]);
		} while (nums[i] != i + 1);
	}
	for (i = 0; i < len; ++i)
		if (nums[i] != i + 1) {
			ans[0] = nums[i];
			ans[1] = i + 1;
		}
	return ans;
}

int main()
{
	vector<int> nums = {1, 2, 2, 4};
	ToOut(findErrorNums(nums));
}
