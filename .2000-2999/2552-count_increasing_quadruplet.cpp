﻿#include "leetcode.hpp"

/* 2552. 统计上升四元组

给你一个长度为 n 下标从 0 开始的整数数组 nums ，它包含 1 到 n 的所有数字，请你返回上升四元组的数目。

如果一个四元组 (i, j, k, l) 满足以下条件，我们称它是上升的：

0 <= i < j < k < l < n 且
nums[i] < nums[k] < nums[j] < nums[l] 。

示例 1：
输入：nums = [1,3,2,4,5]
输出：2
解释：
- 当 i = 0 ，j = 1 ，k = 2 且 l = 3 时，有 nums[i] < nums[k] < nums[j] < nums[l] 。
- 当 i = 0 ，j = 1 ，k = 2 且 l = 4 时，有 nums[i] < nums[k] < nums[j] < nums[l] 。
没有其他的四元组，所以我们返回 2 。

示例 2：
输入：nums = [1,2,3,4]
输出：0
解释：只存在一个四元组 i = 0 ，j = 1 ，k = 2 ，l = 3 ，但是 nums[j] < nums[k] ，所以我们返回 0 。

提示：
  4 <= nums.length <= 4000
  1 <= nums[i] <= nums.length
  nums 中所有数字 互不相同 ，nums 是一个排列。
*/

// https://leetcode.cn/problems/count-increasing-quadruplets/solutions/2080632/you-ji-qiao-de-mei-ju-yu-chu-li-pythonja-exja/
// 抄的
long long countQuadruplets(vector<int> const& A)
{
	long long cnt4 = 0;
	int n = static_cast<int>(A.size());
	vector<int> cnt3(n);
	for (int l = 2; l < n; l++) {
		int cnt2 = 0;
		for (int j = 0; j < l; j++) {
			if (A[j] < A[l]) {
				// 3 < 4
				cnt4 += cnt3[j];
				// 把 j 当作 i，把 l 当作 k，现在 nums[i] < nums[k]，即 1 < 2
				cnt2++;
			} else {
				// 把 l 当作 k，现在 nums[j] > nums[k]，即 3 > 2
				cnt3[j] += cnt2;
			}
		}
	}
	return cnt4;
}

int main()
{
	ToOut(countQuadruplets({1, 3, 2, 4, 5}));
	ToOut(countQuadruplets({1, 2, 3, 4}));
}
