﻿#include "leetcode.hpp"

/* 2366. 将数组排序的最少替换次数

给你一个下标从 0 开始的整数数组 nums 。
每次操作中，你可以将数组中任何一个元素替换为 任意两个 和为该元素的数字。

比方说，nums = [5,6,7] 。一次操作中，我们可以将 nums[1] 替换成 2 和 4 ，将 nums 转变成 [5,2,4,7] 。

请你执行上述操作，将数组变成元素按 非递减 顺序排列的数组，并返回所需的最少操作次数。

示例 1：
输入：nums = [3,9,3]
输出：2
解释：以下是将数组变成非递减顺序的步骤：
- [3,9,3] ，将9 变成 3 和 6 ，得到数组 [3,3,6,3]
- [3,3,6,3] ，将 6 变成 3 和 3 ，得到数组 [3,3,3,3,3]
总共需要 2 步将数组变成非递减有序，所以我们返回 2 。

示例 2：
输入：nums = [1,2,3,4,5]
输出：0
解释：数组已经是非递减顺序，所以我们返回 0 。

提示：
  1 <= nums.length <= 10^5
  1 <= nums[i] <= 10^9
*/

long long minimumReplacement(vector<int> const& nums)
{
	int n = static_cast<int>(nums.size());
	long long ret = 0;
	int val = INT_MAX;
	for (int i = n - 1; i >= 0; --i) {
		if (nums[i] > val) {
			int d = (nums[i] + val - 1) / val;
			val = nums[i] / d;
			ret += d - 1;
		} else
			val = nums[i];
	}
	return ret;
}

int main()
{
	ToOut(minimumReplacement({3, 9, 3}));
	ToOut(minimumReplacement({1, 2, 3, 4, 5}));
	ToOut(minimumReplacement({12, 9, 7, 6, 17, 19, 21}));
}
