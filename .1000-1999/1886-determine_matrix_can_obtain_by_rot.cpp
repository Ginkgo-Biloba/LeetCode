﻿#include "leetcode.hpp"

/* 1886. 判断矩阵经轮转后是否一致

给你两个大小为 n x n 的二进制矩阵 mat 和 target 。
现 以 90 度顺时针轮转 矩阵 mat 中的元素 若干次 ，如果能够使 mat 与 target 一致，返回 true ；否则，返回 false 。

示例 1：
https://assets.leetcode.com/uploads/2021/05/20/grid3.png
输入：mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
输出：true
解释：顺时针轮转 90 度一次可以使 mat 和 target 一致。

示例 2：
https://assets.leetcode.com/uploads/2021/05/20/grid4.png
输入：mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
输出：false
解释：无法通过轮转矩阵中的元素使 equal 与 target 一致。

示例 3：
https://assets.leetcode.com/uploads/2021/05/26/grid4.png
输入：mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
输出：true
解释：顺时针轮转 90 度两次可以使 mat 和 target 一致。

提示：
  n == mat.length == target.length
  n == mat[i].length == target[i].length
  1 <= n <= 10
  mat[i][j] 和 target[i][j] 不是 0 就是 1
*/

bool findRotation(vector<vector<int>>& A, vector<vector<int>>& B)
{
	int n = static_cast<int>(A.size());
	int ok[4] = {1, 1, 1, 1};
	for (int h = 0; h < n; ++h)
		for (int w = 0; w < n; ++w) {
			int v = A[h][w];
			if (v != B[h][w]) ok[0] = 0;
			if (v != B[n - 1 - w][h]) ok[1] = 0;
			if (v != B[w][n - 1 - h]) ok[2] = 0;
			if (v != B[n - 1 - h][n - 1 - w]) ok[3] = 0;
		}
	return ok[0] || ok[1] || ok[2] || ok[3];
}

int main()
{
}
