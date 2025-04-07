#include "leetcode.hpp"

/* 2290. 到达角落需要移除障碍物的最小数目

给你一个下标从 0 开始的二维整数数组 grid ，数组大小为 m x n 。
每个单元格都是两个值之一：
  0 表示一个 空 单元格，
  1 表示一个可以移除的 障碍物 。

你可以向上、下、左、右移动，从一个空单元格移动到另一个空单元格。

现在你需要从左上角 (0, 0) 移动到右下角 (m - 1, n - 1) ，返回需要移除的障碍物的 最小 数目。

示例 1：
https://assets.leetcode.com/uploads/2022/04/06/example1drawio-1.png
输入：grid = [[0,1,1],[1,1,0],[1,1,0]]
输出：2
解释：可以移除位于 (0, 1) 和 (0, 2) 的障碍物来创建从 (0, 0) 到 (2, 2) 的路径。
可以证明我们至少需要移除两个障碍物，所以返回 2 。
注意，可能存在其他方式来移除 2 个障碍物，创建出可行的路径。

示例 2：
https://assets.leetcode.com/uploads/2022/04/06/example1drawio.png
输入：grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]]
输出：0
解释：不移除任何障碍物就能从 (0, 0) 到 (2, 4) ，所以返回 0 。

提示：
  m == grid.length
  n == grid[i].length
  1 <= m, n <= 10^5
  2 <= m * n <= 10^5
  grid[i][j] 为 0 或 1
  grid[0][0] == grid[m - 1][n - 1] == 0
*/

int minimumObstacles(vector<vector<int>> const& grid)
{
	int const dirs[] = {-1, 0, 1, 0, -1};
	int rows = static_cast<int>(grid.size());
	int cols = static_cast<int>(grid[0].size());
	vector<int> distance(rows * cols, rows + cols);
	using elem = pair<int, int>;
	priority_queue<elem, vector<elem>, std::greater<elem>> Q;
	distance[0] = 0;
	Q.push({0, 0});
	while (!Q.empty()) {
		int u = Q.top().first, q = Q.top().second;
		Q.pop();
		if (u > distance[q])
			continue;
		int h = q / cols, w = q % cols;
		for (int d = 0; d < 4; ++d) {
			int y = h + dirs[d];
			int x = w + dirs[d + 1];
			if (static_cast<unsigned>(y) < static_cast<unsigned>(rows)
				&& static_cast<unsigned>(x) < static_cast<unsigned>(cols)) {
				int t = y * cols + x;
				int v = u + grid[y][x];
				if (v < distance[t]) {
					distance[t] = v;
					Q.push({v, t});
				}
			}
		}
	}
	return distance.back();
}

int main()
{
	vector<vector<int>>
		g1 = {{0, 1, 1}, {1, 1, 0}, {1, 1, 0}},
		g2 = {{0, 1, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 0, 1, 0}},
		g3 = {{0, 0, 1, 1, 1, 1, 0, 0, 0, 1}, {0, 1, 1, 1, 1, 1, 1, 0, 1, 1}, {1, 1, 0, 1, 1, 1, 1, 0, 1, 0}, {0, 0, 1, 1, 1, 1, 0, 0, 1, 1}, {1, 0, 1, 0, 0, 0, 1, 1, 1, 0}};
	ToOut(minimumObstacles(g1));
	ToOut(minimumObstacles(g2));
	ToOut(minimumObstacles(g3));
}
