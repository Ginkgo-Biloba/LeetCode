﻿#include "leetcode.hpp"

/* 2658. 网格图中鱼的最大数目

给你一个下标从 0 开始大小为 m x n 的二维整数数组 grid ，其中下标在 (r, c) 处的整数表示：
  如果 grid[r][c] = 0 ，那么它是一块 陆地 。
  如果 grid[r][c] > 0 ，那么它是一块 水域 ，且包含 grid[r][c] 条鱼。

一位渔夫可以从任意 水域 格子 (r, c) 出发，然后执行以下操作任意次：
  捕捞格子 (r, c) 处所有的鱼，或者
  移动到相邻的 水域 格子。
请你返回渔夫最优策略下， 最多 可以捕捞多少条鱼。如果没有水域格子，请你返回 0 。

格子 (r, c) 相邻 的格子为 (r, c + 1) ，(r, c - 1) ，(r + 1, c) 和 (r - 1, c) ，前提是相邻格子在网格图内。

示例 1：
https://assets.leetcode.com/uploads/2023/03/29/example.png
输入：grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
输出：7
解释：渔夫可以从格子 (1,3) 出发，捕捞 3 条鱼，然后移动到格子 (2,3) ，捕捞 4 条鱼。

示例 2：
https://assets.leetcode.com/uploads/2023/03/29/example2.png
输入：grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
输出：1
解释：渔夫可以从格子 (0,0) 或者 (3,3) ，捕捞 1 条鱼。

提示：
  m == grid.length
  n == grid[i].length
  1 <= m, n <= 10
  0 <= grid[i][j] <= 10
*/

int findMaxFish(vector<vector<int>> const& grid)
{
	int const dirs[] = {-1, 0, 1, 0, -1};
	int rows = static_cast<int>(grid.size());
	int cols = static_cast<int>(grid[0].size());
	int ans = 0;
	vector<array<int, 2>> Q;
	vector<uint8_t> vis(rows * cols, 0);
	for (int h = 0; h < rows; ++h)
		for (int w = 0; w < cols; ++w) {
			vis[h * cols + w] = 1;
			if (grid[h][w] == 0)
				continue;
			int val = 0;
			Q.push_back({h, w});
			for (size_t i = 0; i < Q.size(); ++i) {
				auto f = Q[i];
				val += grid[f[0]][f[1]];
				for (int d = 0; d < 4; ++d) {
					int y = f[0] + dirs[d];
					int x = f[1] + dirs[d + 1];
					if (static_cast<unsigned>(y) < static_cast<unsigned>(rows)
						&& static_cast<unsigned>(x) < static_cast<unsigned>(cols)
						&& grid[y][x] > 0 && !vis[y * cols + x]) {
						vis[y * cols + x] = 1;
						Q.push_back({y, x});
					}
				}
			}
			Q.clear();
			ans = max(ans, val);
		}
	return ans;
}

int main()
{
	ToOut(findMaxFish({
		{0, 2, 1, 0},
		{4, 0, 0, 3},
		{1, 0, 0, 4},
		{0, 3, 2, 0},
	}));
	ToOut(findMaxFish({
		{1, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 1},
	}));
}
