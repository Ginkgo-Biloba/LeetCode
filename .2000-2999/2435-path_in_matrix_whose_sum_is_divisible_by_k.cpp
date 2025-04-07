#include "leetcode.hpp"

/* 2435. 矩阵中和能被 K 整除的路径

给你一个下标从 0 开始的 m x n 整数矩阵 grid 和一个整数 k 。
你从起点 (0, 0) 出发，每一步只能往 下 或者往 右 ，你想要到达终点 (m - 1, n - 1) 。

请你返回路径和能被 k 整除的路径数目，由于答案可能很大，返回答案对 10^9 + 7 取余 的结果。

示例 1：
https://assets.leetcode.com/uploads/2022/08/13/image-20220813183124-1.png
输入：grid = [[5,2,4],[3,0,5],[0,7,2]], k = 3
输出：2
解释：有两条路径满足路径上元素的和能被 k 整除。
第一条路径为上图中用红色标注的路径，和为 5 + 2 + 4 + 5 + 2 = 18 ，能被 3 整除。
第二条路径为上图中用蓝色标注的路径，和为 5 + 3 + 0 + 5 + 2 = 15 ，能被 3 整除。

示例 2：
https://assets.leetcode.com/uploads/2022/08/17/image-20220817112930-3.png
输入：grid = [[0,0]], k = 5
输出：1
解释：红色标注的路径和为 0 + 0 = 0 ，能被 5 整除。

示例 3：
https://assets.leetcode.com/uploads/2022/08/12/image-20220812224605-3.png
输入：grid = [[7,3,4,9],[2,3,6,2],[2,3,7,0]], k = 1
输出：10
解释：每个数字都能被 1 整除，所以每一条路径的和都能被 k 整除。

提示：
  m == grid.length
  n == grid[i].length
  1 <= m, n <= 5 * 10^4
  1 <= m * n <= 5 * 10^4
  0 <= grid[i][j] <= 100
  1 <= k <= 50
*/

int numberOfPaths(vector<vector<int>> const& grid, int k)
{
	int rows = static_cast<int>(grid.size());
	int cols = static_cast<int>(grid[0].size());
	int const mod = static_cast<int>(1e9 + 7);
	Matrix<unsigned> pre(cols, k), cur(cols, k);
	for (int h = 0; h < rows; ++h) {
		std::swap(pre, cur);
		memset(cur.buffer.data(), 0, sizeof(int) * cur.buffer.size());
		if (h == 0)
			cur(0, grid[0][0] % k) = 1;
		for (int w = 0; w < cols; ++w) {
			int val = grid[h][w];
			if (h > 0)
				for (int i = 0; i < k; ++i)
					cur(w, (i + val) % k) += pre(w, i);
			if (w > 0)
				for (int i = 0; i < k; ++i)
					cur(w, (i + val) % k) += cur(w - 1, i);
			for (int i = 0; i < k; ++i)
				cur(w, i) %= mod;
		}
	}
	return static_cast<int>(cur(cols - 1, 0));
}

int main()
{
	ToOut(numberOfPaths({{5, 2, 4}, {3, 0, 5}, {0, 7, 2}}, 3));
	ToOut(numberOfPaths({{0, 0}}, 5));
	ToOut(numberOfPaths({{7, 3, 4, 9}, {2, 3, 6, 2}, {2, 3, 7, 0}}, 1));
}
