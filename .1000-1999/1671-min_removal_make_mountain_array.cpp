﻿#include "leetcode.hpp"

/* 1671. 得到山形数组的最少删除次数

我们定义 arr 是 山形数组 当且仅当它满足：
  arr.length >= 3
  存在某个下标 i （从 0 开始） 满足 0 < i < arr.length - 1 且：
    arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
    arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

给你整数数组 nums​ ，请你返回将 nums 变成 山形状数组 的​ 最少 删除次数。

示例 1：
输入：nums = [1,3,1]
输出：0
解释：数组本身就是山形数组，所以我们不需要删除任何元素。

示例 2：
输入：nums = [2,1,1,5,6,2,3,1]
输出：3
解释：一种方法是将下标为 0，1 和 5 的元素删除，剩余元素为 [1,5,6,3,1] ，是山形数组。

示例 3：
输入：nums = [4,3,2,1,1,2,3,1]
输出：4

提示：
输入：nums = [1,2,3,4,4,3,2,1]
输出：1

提示：
  3 <= nums.length <= 1000
  1 <= nums[i] <= 10^9
  题目保证 nums 删除一些元素后一定能得到山形数组。
*/

int minimumMountainRemovals(vector<int>& A)
{
	int n = static_cast<int>(A.size());
	int m = 0;
	vector<int> L(n), R(n), S;
	S.reserve(n);
	for (int i = 0; i < n; ++i) {
		auto it = lower_bound(S.begin(), S.end(), A[i]);
		if (it == S.end())
			S.push_back(A[i]);
		else
			*it = A[i];
		L[i] = static_cast<int>(it - S.begin());
	}
	S.clear();
	for (int i = n - 1; i >= 0; --i) {
		auto it = lower_bound(S.begin(), S.end(), A[i]);
		if (it == S.end())
			S.push_back(A[i]);
		else
			*it = A[i];
		R[i] = static_cast<int>(it - S.begin());
	}
	for (int i = 1; i < n - 1; ++i)
		m = max(m, L[i] + R[i] + 1);
	return n - m;
}

int main()
{
}
