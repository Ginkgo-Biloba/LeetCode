﻿#include "leetcode.hpp"

/* 2164. 对奇偶下标分别排序

给你一个下标从 0 开始的整数数组 nums 。根据下述规则重排 nums 中的值：
  按 非递增 顺序排列 nums 奇数下标 上的所有值。
      举个例子，如果排序前 nums = [4,1,2,3] ，对奇数下标的值排序后变为 [4,3,2,1] 。
      奇数下标 1 和 3 的值按照非递增顺序重排。
  按 非递减 顺序排列 nums 偶数下标 上的所有值。
      举个例子，如果排序前 nums = [4,1,2,3] ，对偶数下标的值排序后变为 [2,1,4,3] 。
      偶数下标 0 和 2 的值按照非递减顺序重排。

返回重排 nums 的值之后形成的数组。

示例 1：
输入：nums = [4,1,2,3]
输出：[2,3,4,1]
解释：
首先，按非递增顺序重排奇数下标（1 和 3）的值。
所以，nums 从 [4,1,2,3] 变为 [4,3,2,1] 。
然后，按非递减顺序重排偶数下标（0 和 2）的值。
所以，nums 从 [4,1,2,3] 变为 [2,3,4,1] 。
因此，重排之后形成的数组是 [2,3,4,1] 。

示例 2：
输入：nums = [2,1]
输出：[2,1]
解释：
由于只有一个奇数下标和一个偶数下标，所以不会发生重排。
形成的结果数组是 [2,1] ，和初始数组一样。

提示：
  1 <= nums.length <= 100
  1 <= nums[i] <= 100
*/

vector<int> sortEvenOdd(vector<int>& A)
{
	size_t len = A.size();
	vector<int> odd, even;
	for (size_t i = 0; i < len; i += 2) {
		even.push_back(A[i + 0]);
		if (i + 1 < len)
			odd.push_back(-A[i + 1]);
	}
	sort(even.begin(), even.end());
	sort(odd.begin(), odd.end());
	for (size_t i = 0; i < A.size(); i += 2) {
		A[i + 0] = even[i / 2];
		if (i + 1 < len)
			A[i + 1] = -odd[i / 2];
	}
	return std::move(A);
}

int main() { }
