﻿#include "leetcode.hpp"

/* 33. 搜索旋转排序数组

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:
输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4

示例 2:
输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1
*/

int search(vector<int>& A, int val)
{
	int len = static_cast<int>(A.size());
	if (len == 0)
		return -1;
	int h = 0, i, k = len - 1;
	while (h < k) {
		i = (h + k) / 2;
		if (A[i] == val)
			return i;
		if (A[h] < A[i]) {
			if (A[h] <= val && val < A[i])
				k = i - 1;
			else
				h = i + 1;
		} else {
			if (A[i] < val && val <= A[k])
				h = i + 1;
			else
				k = i - 1;
		}
	}
	return A[h] == val ? h : -1;
}

int main()
{
	vector<int>
		a = {4, 5, 6, 7, 0, 1, 2},
		b = {3, 1};
	ToOut(search(a, 0));
	ToOut(search(a, 3));
	ToOut(search(b, 1));
}
