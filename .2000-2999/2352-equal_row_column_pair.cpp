﻿#include "leetcode.hpp"

/* 2352. 相等行列对

给你一个下标从 0 开始、大小为 n x n 的整数矩阵 grid ，返回满足 Ri 行和 Cj 列相等的行列对 (Ri, Cj) 的数目。

如果行和列以相同的顺序包含相同的元素（即相等的数组），则认为二者是相等的。

示例 1：
输入：grid = [[3,2,1],[1,7,6],[2,7,7]]
输出：1
解释：存在一对相等行列对：
- (第 2 行，第 1 列)：[2,7,7]

示例 2：
输入：grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
输出：3
解释：存在三对相等行列对：
- (第 0 行，第 0 列)：[3,1,2,2]
- (第 2 行, 第 2 列)：[2,4,2,2]
- (第 3 行, 第 2 列)：[2,4,2,2]

提示：
  n == grid.length == grid[i].length
  1 <= n <= 200
  1 <= grid[i][j] <= 10^5
*/

int equalPairs(vector<vector<int>> const& grid)
{
	int n = static_cast<int>(grid.size());
	vector<uint64_t> row(n), col(n);
	uint64_t const mod = UINT64_MAX / 100009;
	for (int h = 0; h < n; ++h)
		for (int w = 0; w < n; ++w) {
			uint64_t val = grid[h][w];
			row[h] = (row[h] * 100007 + val) % mod;
			col[w] = (col[w] * 100007 + val) % mod;
		}
	int ans = 0;
	// 赌一把
	for (int h = 0; h < n; ++h)
		for (int w = 0; w < n; ++w)
			ans += row[h] == col[w];
	return ans;
}

int main()
{
	vector<vector<int>>
		g1 = {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}},
		g2 = {{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}};
	ToOut(equalPairs(g1));
	ToOut(equalPairs(g2));
}
