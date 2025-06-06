﻿#include "leetcode.hpp"

/* 88. 合并两个有序数组

给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。

说明:
  初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
  你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。

示例:
输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3
输出: [1,2,2,3,5,6
*/

void merge(vector<int>& A, int a, vector<int>& B, int b)
{
	A.resize(a + b);
	int c = a + b - 1;
	for (--a, --b; a >= 0 && b >= 0; --c) {
		if (A[a] >= B[b]) {
			A[c] = A[a];
			--a;
		} else {
			A[c] = B[b];
			--b;
		}
	}
	// a >= 0 则不用管
	for (; b >= 0; --b, --c)
		A[c] = B[b];
}

int main()
{
}
