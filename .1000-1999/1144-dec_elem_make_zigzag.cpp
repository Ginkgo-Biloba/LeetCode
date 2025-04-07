﻿#include "leetcode.hpp"

/* 1144. 递减元素使数组呈锯齿状

给你一个整数数组 nums，每次 操作 会从中选择一个元素并 将该元素的值减少 1。

如果符合下列情况之一，则数组 A 就是 锯齿数组：
  每个偶数索引对应的元素都大于相邻的元素，即 A[0] > A[1] < A[2] > A[3] < A[4] > ...
  或者，每个奇数索引对应的元素都大于相邻的元素，即 A[0] < A[1] > A[2] < A[3] > A[4] < ...

返回将数组 nums 转换为锯齿数组所需的最小操作次数。

示例 1：
输入：nums = [1,2,3]
输出：2
解释：我们可以把 2 递减到 0，或把 3 递减到 1。

示例 2：
输入：nums = [9,6,1,6,2]
输出：4

提示：
  1 <= nums.length <= 1000
  1 <= nums[i] <= 1000
*/

// https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/discuss/350576/JavaC%2B%2BPython-Easy-and-concise
// 抄的
int movesToMakeZigzag(vector<int>& A)
{
	int len = static_cast<int>(A.size());
	int d[2] = {0, 0}, L, R;
	for (int i = 0; i < len; ++i) {
		L = i > 0 ? A[i - 1] : INT_MAX;
		R = i + 1 < len ? A[i + 1] : INT_MAX;
		d[i & 1] += max(0, A[i] - min(L, R) + 1);
	}
	return min(d[0], d[1]);
}

int main()
{
	vector<int>
		a = {1, 2, 3},
		b = {9, 6, 1, 6, 2};
	ToOut(movesToMakeZigzag(a));
	ToOut(movesToMakeZigzag(b));
}
