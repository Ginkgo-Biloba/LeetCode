#include "leetcode.hpp"

/* 2577. 在网格图中访问一个格子的最少时间

给你一个 m x n 的矩阵 grid ，每个元素都为 非负 整数，其中 grid[row][col] 表示可以访问格子 (row, col) 的 最早 时间。
也就是说当你访问格子 (row, col) 时，最少已经经过的时间为 grid[row][col] 。

你从 最左上角 出发，出发时刻为 0 ，你必须一直移动到上下左右相邻四个格子中的 任意 一个格子（即不能停留在格子上）。每次移动都需要花费 1 单位时间。

请你返回 最早 到达右下角格子的时间，如果你无法到达右下角的格子，请你返回 -1 。

示例 1：
https://assets.leetcode.com/uploads/2023/02/14/yetgriddrawio-8.png
输入：grid = [[0,1,3,2],[5,1,2,5],[4,3,8,6]]
输出：7
解释：一条可行的路径为：
- 时刻 t = 0 ，我们在格子 (0,0) 。
- 时刻 t = 1 ，我们移动到格子 (0,1) ，可以移动的原因是 grid[0][1] <= 1 。
- 时刻 t = 2 ，我们移动到格子 (1,1) ，可以移动的原因是 grid[1][1] <= 2 。
- 时刻 t = 3 ，我们移动到格子 (1,2) ，可以移动的原因是 grid[1][2] <= 3 。
- 时刻 t = 4 ，我们移动到格子 (1,1) ，可以移动的原因是 grid[1][1] <= 4 。
- 时刻 t = 5 ，我们移动到格子 (1,2) ，可以移动的原因是 grid[1][2] <= 5 。
- 时刻 t = 6 ，我们移动到格子 (1,3) ，可以移动的原因是 grid[1][3] <= 6 。
- 时刻 t = 7 ，我们移动到格子 (2,3) ，可以移动的原因是 grid[2][3] <= 7 。
最终到达时刻为 7 。这是最早可以到达的时间。

示例 2：
https://assets.leetcode.com/uploads/2023/02/14/yetgriddrawio-9.png
输入：grid = [[0,2,4],[3,2,1],[1,0,4]]
输出：-1
解释：没法从左上角按题目规定走到右下角。

提示：
  m == grid.length
  n == grid[i].length
  2 <= m, n <= 1000
  4 <= m * n <= 10^5
  0 <= grid[i][j] <= 10^5
  grid[0][0] == 0
*/

int minimumTime(vector<vector<int>> const& grid)
{
	int const dirs[] = {-1, 0, 1, 0, -1};
	int rows = static_cast<int>(grid.size());
	int cols = static_cast<int>(grid[0].size());
	if (grid[0][1] > 1 && grid[1][0] > 1)
		return -1;
	string visit;
	vector<array<int, 3>> Q;
	int L = rows + cols - 2, R = INT_MAX / 2;
	while (L < R) {
		bool done = false;
		int mid = (L + R) / 2;
		Q.clear();
		if (grid[rows - 1][cols - 1] <= mid) {
			Q.push_back({rows - 1, cols - 1, mid});
			visit.assign(rows * cols, '0');
			visit[rows * cols - 1] = '1';
		}
		for (size_t i = 0; !done && i < Q.size(); ++i) {
			array<int, 3> f = Q[i];
			for (int d = 0; d < 4; ++d) {
				int h = f[0] + dirs[d];
				int w = f[1] + dirs[d + 1];
				if (static_cast<unsigned>(h) >= static_cast<unsigned>(rows)
					|| static_cast<unsigned>(w) >= static_cast<unsigned>(cols)
					|| visit[h * cols + w] == '1')
					continue;
				visit[h * cols + w] = '1';
				if (f[2] > grid[h][w]) {
					Q.push_back({h, w, f[2] - 1});
					if (h == 0 && w == 0)
						done = true;
				}
			}
		}
		if (done)
			R = mid;
		else
			L = mid + 1;
	}
	return L + ((L + rows + cols) & 1);
}

int main()
{
	ToOut(minimumTime(vector<vector<int>> {{0, 1, 3, 2}, {5, 1, 2, 5}, {4, 3, 8, 6}}));
	ToOut(minimumTime(vector<vector<int>> {{0, 2, 4}, {3, 2, 1}, {1, 0, 4}}));
}
