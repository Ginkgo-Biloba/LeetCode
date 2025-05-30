﻿#include "leetcode.hpp"

/* 747. 至少是其他数字两倍的最大数

在一个给定的数组nums中，总是存在一个最大元素。
查找数组中的最大元素是否至少是数组中每个其他数字的两倍。
如果是，则返回最大元素的索引，否则返回-1。

示例 1:
输入: nums = [3, 6, 1, 0]
输出: 1
解释: 6是最大的整数, 对于数组中的其他整数,
6大于数组中其他元素的两倍。6的索引是1, 所以我们返回1.


示例 2:
输入: nums = [1, 2, 3, 4]
输出: -1
解释: 4没有超过3的两倍大, 所以我们返回 -1.

提示:
  nums 的长度范围在[1, 50].
  每个 nums[i] 的整数范围在 [0, 100]。
*/

int dominantIndex(vector<int>& nums)
{
	int v0 = -1, v1 = -1, idx = -1;
	int len = static_cast<int>(nums.size());
	for (int i = 0; i < len; ++i) {
		if (nums[i] > v1) {
			v0 = v1;
			v1 = nums[i];
			idx = i;
		} else if (nums[i] > v0)
			v0 = nums[i];
	}
	return v0 * 2 <= v1 ? idx : -1;
}

int main()
{
	vector<int> n1 = {3, 6, 1, 0};
	vector<int> n2 = {1, 2, 3, 4};
	ToOut(dominantIndex(n1));
	ToOut(dominantIndex(n2));
}
