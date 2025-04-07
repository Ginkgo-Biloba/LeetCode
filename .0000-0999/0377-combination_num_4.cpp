﻿#include "leetcode.hpp"

/* 377. 组合总和 Ⅳ

给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。

示例:

nums = [1, 2, 3]
target = 4

所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

请注意，顺序不同的序列被视作不同的组合。
因此输出为 7。

进阶：
如果给定的数组中含有负数会怎么样？
问题会产生什么变化？
我们需要在题目中添加什么限制来允许负数的出现？
*/

// https://leetcode.com/problems/combination-sum-iv/discuss/85036/1ms-Java-DP-Solution-with-Detailed-Explanation
// 抄的
int combinationSum4(vector<int>& nums, int target)
{
	size_t len = nums.size();
	vector<unsigned> dp(target + 1, 0);
	dp[0] = 1;
	if (target == 0) return 1;

	std::sort(nums.begin(), nums.end());
	for (int i = 1; i <= target; ++i)
		for (size_t k = 0; k < len; ++k) {
			if (nums[k] <= i)
				dp[i] += dp[i - nums[k]];
			else
				break;
		}

	return dp.back();
}

int main()
{
	vector<int> nums = {3, 33, 333};
	ToOut(combinationSum4(nums, 999));
}
