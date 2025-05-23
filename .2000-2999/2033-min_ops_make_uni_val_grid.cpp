﻿#include "leetcode.hpp"

/* 2033. 获取单值网格的最小操作数

给你一个大小为 m x n 的二维整数网格 grid 和一个整数 x 。每一次操作，你可以对 grid 中的任一元素 加 x 或 减 x 。

单值网格 是全部元素都相等的网格。

返回使网格化为单值网格所需的 最小 操作数。
如果不能，返回 -1 。

示例 1：
https://assets.leetcode.com/uploads/2021/09/21/gridtxt.png
输入：grid = [[2,4],[6,8]], x = 2
输出：4
解释：可以执行下述操作使所有元素都等于 4 ：
- 2 加 x 一次。
- 6 减 x 一次。
- 8 减 x 两次。
共计 4 次操作。

示例 2：
https://assets.leetcode.com/uploads/2021/09/21/gridtxt-1.png
输入：grid = [[1,5],[2,3]], x = 1
输出：5
解释：可以使所有元素都等于 3 。

示例 3：
https://assets.leetcode.com/uploads/2021/09/21/gridtxt-2.png
输入：grid = [[1,2],[3,4]], x = 2
输出：-1
解释：无法使所有元素相等。

提示：
  m == grid.length
  n == grid[i].length
  1 <= m, n <= 10^5
  1 <= m * n <= 10^5
  1 <= x, grid[i][j] <= 10^4
*/

int minOperations(vector<vector<int>>& grid, int x)
{
	vector<int> A;
	for (vector<int>& row : grid)
		for (int i : row)
			A.push_back(i);
	sort(A.begin(), A.end());
	int sum = 0;
	int mid = A[A.size() / 2];
	for (int i : A) {
		int d = abs(mid - i);
		int op = d / x;
		if (op * x != d)
			return -1;
		sum += op;
	}
	return sum;
}

int main() { }
