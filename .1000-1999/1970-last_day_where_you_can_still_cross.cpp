#include "leetcode.hpp"

/* 1970. 你能穿过矩阵的最后一天

There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.

Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).

You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end grid any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).

Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.

给你一个下标从 1 开始的二进制矩阵，其中 0 表示陆地，1 表示水域。
同时给你 row 和 col 分别表示矩阵中行和列的数目。

一开始在第 0 天，整个 矩阵都是 陆地 。
但每一天都会有一块新陆地被 水 淹没变成水域。
给你一个下标从 1 开始的二维数组 cells ，其中 cells[i] = [ri, ci] 表示在第 i 天，第 ri 行 ci 列（下标都是从 1 开始）的陆地会变成 水域 （也就是 0 变成 1 ）。

你想知道从矩阵最 上面 一行走到最 下面 一行，且只经过陆地格子的 最后一天 是哪一天。
你可以从最上面一行的 任意 格子出发，到达最下面一行的 任意 格子。
你只能沿着 四个 基本方向移动（也就是上下左右）。

请返回只经过陆地格子能从最 上面 一行走到最 下面 一行的 最后一天 。

示例 1：
https://assets.leetcode.com/uploads/2021/07/27/1.png
输入：row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
输出：2
解释：上图描述了矩阵从第 0 天开始是如何变化的。
可以从最上面一行到最下面一行的最后一天是第 2 天。

示例 2：
https://assets.leetcode.com/uploads/2021/07/27/2.png
输入：row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
输出：1
解释：上图描述了矩阵从第 0 天开始是如何变化的。
可以从最上面一行到最下面一行的最后一天是第 1 天。

示例 3：
https://assets.leetcode.com/uploads/2021/07/27/3.png
输入：row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
输出：3
解释：上图描述了矩阵从第 0 天开始是如何变化的。
可以从最上面一行到最下面一行的最后一天是第 3 天。

提示：
  2 <= row, col <= 2 * 10^4
  4 <= row * col <= 2 * 10^4
  cells.length == row * col
  1 <= ri <= row
  1 <= ci <= col
  cells 中的所有格子坐标都是 唯一 的。
*/

class Solution {
	string matrix;
	int row, col;
	vector<vector<int>> cell;

	char& grid(int h, int w)
	{
		return matrix[h * col + w];
	}

	bool walk(int step)
	{
		int const dir[] = {-1, 0, 1, 0, -1};
		matrix.assign(row * col, 0);
		for (int i = step; i--;)
			grid(cell[i][0] - 1, cell[i][1] - 1) = 1;
		vector<array<int, 2>> pos;
		for (int w = 0; w < col; ++w)
			if (!grid(0, w)) {
				pos.push_back({0, w});
				grid(0, w) = 1;
			}
		for (size_t i = 0; i < pos.size(); ++i) {
			auto p = pos[i];
			for (int d = 0; d < 4; ++d) {
				int h = p[0] + dir[d];
				int w = p[1] + dir[d + 1];
				if (static_cast<unsigned>(h) >= static_cast<unsigned>(row))
					continue;
				if (static_cast<unsigned>(w) >= static_cast<unsigned>(col))
					continue;
				if (grid(h, w))
					continue;
				if (h == row - 1)
					return true;
				grid(h, w) = 1;
				pos.push_back({h, w});
			}
		}
		return false;
	}

public:
	int latestDayToCross(int _row, int _col, vector<vector<int>>& _cell)
	{
		row = _row;
		col = _col;
		cell.swap(_cell);
		int l = 0, r = row * col;
		while (l < r) {
			int m = (l + r) / 2;
			if (walk(m))
				l = m + 1;
			else
				r = m;
		}
		return r - 1;
	}
};

int main() { }
