#include "leetcode.hpp"

/* 2617. 网格图中最少访问的格子数

给你一个下标从 0 开始的 m x n 整数矩阵 grid 。
你一开始的位置在 左上角 格子 (0, 0) 。

当你在格子 (i, j) 的时候，你可以移动到以下格子之一：
  满足 j < k <= grid[i][j] + j 的格子 (i, k) （向右移动），或者
  满足 i < k <= grid[i][j] + i 的格子 (k, j) （向下移动）。

请你返回到达 右下角 格子 (m - 1, n - 1) 需要经过的最少移动格子数，如果无法到达右下角格子，请你返回 -1 。

示例 1：
https://assets.leetcode.com/uploads/2023/01/25/ex1.png
输入：grid = [[3,4,2,1],[4,2,3,1],[2,1,0,0],[2,4,0,0]]
输出：4
解释：上图展示了到达右下角格子经过的 4 个格子。

示例 2：
https://assets.leetcode.com/uploads/2023/01/25/ex2.png
输入：grid = [[3,4,2,1],[4,2,1,1],[2,1,1,0],[3,4,1,0]]
输出：3
解释：上图展示了到达右下角格子经过的 3 个格子。

示例 3：
https://assets.leetcode.com/uploads/2023/01/26/ex3.png
输入：grid = [[2,1,0],[1,0,0]]
输出：-1
解释：无法到达右下角格子。

提示：
  m == grid.length
  n == grid[i].length
  1 <= m, n <= 10^5
  1 <= m * n <= 10^5
  0 <= grid[i][j] < m * n
  grid[m - 1][n - 1] == 0
*/

// https://leetcode.cn/problems/minimum-number-of-visited-clls-in-a-grid/solutions/2701302/python3javacgo-yi-ti-yi-jie-you-xian-dui-vbqu/
// 抄的
int minimumVisitedCells(vector<vector<int>> const& grid)
{
	using pii = pair<int, int>;
	using GPQ = priority_queue<pii, vector<pii>, std::greater<pii>>;
	int rows = static_cast<int>(grid.size());
	int cols = static_cast<int>(grid[0].size());
	vector<vector<int>> D(rows, vector<int>(cols, -1));
	vector<GPQ> R(rows), C(cols);
	D[0][0] = 1;
	for (int h = 0; h < rows; ++h) {
		for (int w = 0; w < cols; ++w) {
			while (!R[h].empty()
				&& grid[h][R[h].top().second] + R[h].top().second < w)
				R[h].pop();

			if (!R[h].empty()
				&& (D[h][w] == -1 || R[h].top().first + 1 < D[h][w]))
				D[h][w] = R[h].top().first + 1;

			while (!C[w].empty()
				&& grid[C[w].top().second][w] + C[w].top().second < h)
				C[w].pop();

			if (!C[w].empty()
				&& (D[h][w] == -1 || C[w].top().first + 1 < D[h][w]))
				D[h][w] = C[w].top().first + 1;

			if (D[h][w] != -1) {
				R[h].emplace(D[h][w], w);
				C[w].emplace(D[h][w], h);
			}
		}
	}
	return D[rows - 1][cols - 1];
}

int main()
{
	ToOut(minimumVisitedCells({
		{3, 4, 2, 1},
		{4, 2, 3, 1},
		{2, 1, 0, 0},
		{2, 4, 0, 0},
	}));
	ToOut(minimumVisitedCells({
		{3, 4, 2, 1},
		{4, 2, 1, 1},
		{2, 1, 1, 0},
		{3, 4, 1, 0},
	}));
	ToOut(minimumVisitedCells({{2, 1, 0}, {1, 0, 0}}));
}
