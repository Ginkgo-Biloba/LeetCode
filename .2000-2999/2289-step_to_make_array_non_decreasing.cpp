#include "leetcode.hpp"

/* 2289. 使数组按非递减顺序排列

给你一个下标从 0 开始的整数数组 nums 。
在一步操作中，移除所有满足 nums[i - 1] > nums[i] 的 nums[i] ，其中 0 < i < nums.length 。

重复执行步骤，直到 nums 变为 非递减 数组，返回所需执行的操作数。

示例 1：
输入：nums = [5,3,4,4,7,3,6,11,8,5,11]
输出：3
解释：执行下述几个步骤：
- 步骤 1 ：[5,3,4,4,7,3,6,11,8,5,11] 变为 [5,4,4,7,6,11,11]
- 步骤 2 ：[5,4,4,7,6,11,11] 变为 [5,4,7,11,11]
- 步骤 3 ：[5,4,7,11,11] 变为 [5,7,11,11]
[5,7,11,11] 是一个非递减数组，因此，返回 3 。

示例 2：
输入：nums = [4,5,7,7,13]
输出：0
解释：nums 已经是一个非递减数组，因此，返回 0 。

提示：
  1 <= nums.length <= 10^5
  1 <= nums[i] <= 10^9
*/

int totalSteps(vector<int> const& nums)
{
	int ans = 0;
	vector<array<int, 2>> Q;
	for (int val : nums) {
		int step = 0;
		while (!Q.empty() && Q.back()[0] <= val) {
			step = max(step, Q.back()[1]);
			Q.pop_back();
		}
		step = Q.empty() ? 0 : step + 1;
		ans = max(ans, step);
		Q.push_back({val, step});
	}
	return ans;
}

int main()
{
	ToOut(totalSteps({5, 3, 4, 4, 7, 3, 6, 11, 8, 5, 11}));
	ToOut(totalSteps({4, 5, 7, 7, 13}));
	ToOut(totalSteps({14, 5, 7, 7, 13}));
	ToOut(totalSteps({10, 1, 2, 3, 4, 5, 6, 1, 2, 3}));
	ToOut(totalSteps({1, 1, 1}));
}
