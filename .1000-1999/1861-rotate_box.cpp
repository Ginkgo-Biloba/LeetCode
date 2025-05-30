﻿#include "leetcode.hpp"

/* 1861. 旋转盒子

给你一个 m x n 的字符矩阵 box ，它表示一个箱子的侧视图。
箱子的每一个格子可能为：
    '#' 表示石头
    '*' 表示固定的障碍物
    '.' 表示空位置

这个箱子被 顺时针旋转 90 度 ，由于重力原因，部分石头的位置会发生改变。每个石头会垂直掉落，直到它遇到障碍物，另一个石头或者箱子的底部。
重力 不会 影响障碍物的位置，同时箱子旋转不会产生惯性 ，也就是说石头的水平位置不会发生改变。

题目保证初始时 box 中的石头要么在一个障碍物上，要么在另一个石头上，要么在箱子的底部。

请你返回一个 n x m的矩阵，表示按照上述旋转后，箱子内的结果。

示例 1：
https://assets.leetcode.com/uploads/2021/04/08/rotatingtheboxleetcodewithstones.png
输入：box = [
  ["#",".","#"]
]
输出：[
  ["."],
  ["#"],
  ["#"]
]

示例 2：
https://assets.leetcode.com/uploads/2021/04/08/rotatingtheboxleetcode2withstones.png
输入：box = [
  ["#",".","*","."],
  ["#","#","*","."]
]
输出：[
  ["#","."],
  ["#","#"],
  ["*","*"],
  [".","."]
]

示例 3：
https://assets.leetcode.com/uploads/2021/04/08/rotatingtheboxleetcode3withstone.png
输入：box = [
  ["#","#","*",".","*","."],
  ["#","#","#","*",".","."],
  ["#","#","#",".","#","."]
]
输出：[
  [".","#","#"],
  [".","#","#"],
  ["#","#","*"],
  ["#","*","."],
  ["#",".","*"],
  ["#",".","."]
]

提示：
  m == box.length
  n == box[i].length
  1 <= m, n <= 500
  box[i][j] 只可能是 '#' ，'*' 或者 '.' 。
*/

vector<vector<char>> rotateTheBox(vector<vector<char>>& A)
{
	int rows = static_cast<int>(A.size());
	int cols = static_cast<int>(A[0].size());
	vector<vector<char>> B(rows);
	for (int h = 0; h < rows; ++h) {
		int w = cols - 1, q = cols - 1;
		B[h].resize(cols, '.');
		for (; w >= 0; --w) {
			if (A[h][w] == '.')
				continue;
			else if (A[h][w] == '*') {
				B[h][w] = A[h][w];
				q = w - 1;
			} else {
				B[h][q] = A[h][w];
				q = q - 1;
			}
		}
	}
	vector<vector<char>> C(cols);
	for (int h = 0; h < cols; ++h)
		for (int w = 0; w < rows; ++w)
			C[h].push_back(B[rows - 1 - w][h]);
	return C;
}

int main()
{
}
