#include "leetcode.hpp"

/* 2328. 网格图中递增路径的数目

给你一个 m x n 的整数网格图 grid ，你可以从一个格子移动到 4 个方向相邻的任意一个格子。

请你返回在网格图中从 任意 格子出发，达到 任意 格子，且路径中的数字是 严格递增 的路径数目。
由于答案可能会很大，请将结果对 10^9 + 7 取余 后返回。

如果两条路径中访问过的格子不是完全相同的，那么它们视为两条不同的路径。

示例 1：
https://assets.leetcode.com/uploads/2022/05/10/griddrawio-4.png
输入：grid = [[1,1],[3,4]]
输出：8
解释：严格递增路径包括：
- 长度为 1 的路径：[1]，[1]，[3]，[4] 。
- 长度为 2 的路径：[1 -> 3]，[1 -> 4]，[3 -> 4] 。
- 长度为 3 的路径：[1 -> 3 -> 4] 。
路径数目为 4 + 3 + 1 = 8 。

示例 2：
输入：grid = [[1],[2]]
输出：3
解释：严格递增路径包括：
- 长度为 1 的路径：[1]，[2] 。
- 长度为 2 的路径：[1 -> 2] 。
路径数目为 2 + 1 = 3 。

提示：
  m == grid.length
  n == grid[i].length
  1 <= m, n <= 1000
  1 <= m * n <= 10^5
  1 <= grid[i][j] <= 10^5
*/

int countPaths(vector<vector<int>>& grid)
{
	struct Point {
		int y, x;
	};
	int rows = static_cast<int>(grid.size());
	int cols = static_cast<int>(grid[0].size());
	vector<Point> index(rows * cols);
	for (int h = 0, i = 0; h < rows; ++h)
		for (int w = 0; w < cols; ++w, ++i)
			index[i] = Point {h, w};
	std::sort(index.begin(), index.end(),
		[&grid](Point& a, Point& b) -> bool {
			return grid[a.y][a.x] < grid[b.y][b.x];
		});
	int const dirs[] = {-1, 0, 1, 0, -1};
	int const mod = static_cast<int>(1e9 + 7);
	vector<int> dst(rows * cols, 1);
	for (Point p : index) {
		int f = p.y * cols + p.x;
		for (int d = 0; d < 4; ++d) {
			int y = p.y + dirs[d];
			int x = p.x + dirs[d + 1];
			if (static_cast<unsigned>(y) < static_cast<unsigned>(rows)
				&& static_cast<unsigned>(x) < static_cast<unsigned>(cols)
				&& grid[p.y][p.x] < grid[y][x]) {
				int t = y * cols + x;
				dst[t] = (dst[t] + dst[f]) % mod;
			}
		}
	}
	int ans = 0;
	for (int d : dst)
		ans = (ans + d) % mod;
	return ans;
}

int main()
{
	vector<vector<int>>
		g1 = {{1, 1}, {3, 4}},
		g2 = {{1}, {2}};
	ToOut(countPaths(g1));
	ToOut(countPaths(g2));
}
