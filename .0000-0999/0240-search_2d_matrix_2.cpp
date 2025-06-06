﻿#include "leetcode.hpp"

/* 240. 搜索二维矩阵 II

编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。
该矩阵具有以下特性：
  每行的元素从左到右升序排列。
  每列的元素从上到下升序排列。

示例:

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

给定 target = 5，返回 true。
给定 target = 20，返回 false。
*/

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	int rows = static_cast<int>(matrix.size());
	if (rows == 0) return false;
	int cols = static_cast<int>(matrix[0].size());
	if (cols < 0) return false;
	int h = 0, w = cols - 1;
	while (h < rows && w >= 0) {
		if (matrix[h][w] == target)
			return true;
		if (matrix[h][w] < target)
			++h;
		else
			--w;
	}
	return false;
}

int main()
{
}
