﻿#include "leetcode.hpp"

/* 1289. 下降路径最小和  II

给你一个整数方阵 arr ，定义「非零偏移下降路径」为：
  从 arr 数组中的每一行选择一个数字，且按顺序选出来的数字中，相邻数字不在原数组的同一列。

请你返回非零偏移下降路径数字和的最小值。

示例 1：
输入：arr = [[1,2,3],[4,5,6],[7,8,9]]
输出：13
解释：
所有非零偏移下降路径包括：
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
下降路径中数字和最小的是 [1,5,7] ，所以答案是 13 。

提示：
  1 <= arr.length == arr[i].length <= 200
  -99 <= arr[i][j] <= 99
*/

int minFallingPathSum(vector<vector<int>>& A)
{
	int val = INT_MAX;
	int len = static_cast<int>(A.size());
	for (int h = 1; h < len; ++h) {
		int i0 = 0, i1 = 1;
		int* B = A[h - 1].data();
		if (B[0] > B[1])
			std::swap(i0, i1);
		for (int w = 2; w < len; ++w) {
			if (B[w] <= B[i0]) {
				i1 = i0;
				i0 = w;
			} else if (B[w] <= B[i1])
				i1 = w;
		}
		for (int w = 0; w < len; ++w)
			A[h][w] += (w == i0 ? B[i1] : B[i0]);
	}
	for (int w = 0; w < len; ++w)
		val = min(val, A[len - 1][w]);
	return val;
}

int main()
{
}
