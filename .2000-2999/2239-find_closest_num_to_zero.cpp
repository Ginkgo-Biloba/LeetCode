﻿#include "leetcode.hpp"

/* 2239. 找到最接近 0 的数字

给你一个长度为 n 的整数数组 nums ，请你返回 nums 中最 接近 0 的数字。
如果有多个答案，请你返回它们中的 最大值 。

示例 1：
输入：nums = [-4,-2,1,4,8]
输出：1
解释：
-4 到 0 的距离为 |-4| = 4 。
-2 到 0 的距离为 |-2| = 2 。
1 到 0 的距离为 |1| = 1 。
4 到 0 的距离为 |4| = 4 。
8 到 0 的距离为 |8| = 8 。
所以，数组中距离 0 最近的数字为 1 。

示例 2：
输入：nums = [2,-1,1]
输出：1
解释：1 和 -1 都是距离 0 最近的数字，所以返回较大值 1 。

提示：
  1 <= n <= 1000
  -10^5 <= nums[i] <= 10^5
*/

int findClosestNumber(vector<int> const& nums)
{
	int d = INT_MAX, v = -INT_MAX;
	for (int i : nums) {
		int a = abs(i);
		if (a == d) {
			d = a;
			v = max(v, i);
		} else if (a < d) {
			d = a;
			v = i;
		}
	}
	return v;
}

int main()
{
	ToOut(findClosestNumber({-4, -2, 1, 4, 8}));
	ToOut(findClosestNumber({2, -1, 1}));
}
