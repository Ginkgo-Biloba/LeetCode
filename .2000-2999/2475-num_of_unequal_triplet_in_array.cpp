﻿#include "leetcode.hpp"

/* 2475. 数组中不等三元组的数目

给你一个下标从 0 开始的正整数数组 nums 。
请你找出并统计满足下述条件的三元组 (i, j, k) 的数目：

0 <= i < j < k < nums.length
nums[i]、nums[j] 和 nums[k] 两两不同 。
换句话说：nums[i] != nums[j]、nums[i] != nums[k] 且 nums[j] != nums[k] 。
返回满足上述条件三元组的数目。

示例 1：
输入：nums = [4,4,2,4,3]
输出：3
解释：下面列出的三元组均满足题目条件：
- (0, 2, 4) 因为 4 != 2 != 3
- (1, 2, 4) 因为 4 != 2 != 3
- (2, 3, 4) 因为 2 != 4 != 3
共计 3 个三元组，返回 3 。
注意 (2, 0, 4) 不是有效的三元组，因为 2 > 0 。

示例 2：
输入：nums = [1,1,1,1,1]
输出：0
解释：不存在满足条件的三元组，所以返回 0 。

提示：
  3 <= nums.length <= 100
  1 <= nums[i] <= 1000
*/

int unequalTriplets(vector<int> A)
{
	int n = static_cast<int>(A.size());
	int ans = 0;
	std::sort(A.begin(), A.end());
	for (int i = 0, k = 1; k < n;) {
		if (A[i] == A[k])
			++k;
		else {
			ans += i * (k - i) * (n - k);
			i = k;
		}
	}
	return ans;
}

int main()
{
	ToOut(unequalTriplets({4, 4, 2, 4, 3}));
	ToOut(unequalTriplets({1, 1, 1, 1, 1}));
}
