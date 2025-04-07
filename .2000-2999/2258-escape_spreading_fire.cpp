#include "leetcode.hpp"

/* 2258. 逃离火灾

给你一个下标从 0 开始大小为 m x n 的二维整数数组 grid ，它表示一个网格图。
每个格子为下面 3 个值之一：

  0 表示草地。
  1 表示着火的格子。
  2 表示一座墙，你跟火都不能通过这个格子。

一开始你在最左上角的格子 (0, 0) ，你想要到达最右下角的安全屋格子 (m - 1, n - 1) 。
每一分钟，你可以移动到 相邻 的草地格子。
每次你移动 之后 ，着火的格子会扩散到所有不是墙的 相邻 格子。

请你返回你在初始位置可以停留的 最多 分钟数，且停留完这段时间后你还能安全到达安全屋。
如果无法实现，请你返回 -1 。
如果不管你在初始位置停留多久，你 总是 能到达安全屋，请你返回 10^9 。

注意，如果你到达安全屋后，火马上到了安全屋，这视为你能够安全到达安全屋。

如果两个格子有共同边，那么它们为 相邻 格子。

示例 1：
https://assets.leetcode.com/uploads/2022/03/10/ex1new.jpg
输入：grid = [[0,2,0,0,0,0,0],[0,0,0,2,2,1,0],[0,2,0,0,1,2,0],[0,0,2,2,2,0,2],[0,0,0,0,0,0,0]]
输出：3
解释：上图展示了你在初始位置停留 3 分钟后的情形。
你仍然可以安全到达安全屋。
停留超过 3 分钟会让你无法安全到达安全屋。

示例 2：
https://assets.leetcode.com/uploads/2022/03/10/ex2new2.jpg
输入：grid = [[0,0,0,0],[0,1,2,0],[0,2,0,0]]
输出：-1
解释：上图展示了你马上开始朝安全屋移动的情形。
火会蔓延到你可以移动的所有格子，所以无法安全到达安全屋。
所以返回 -1 。

示例 3：
https://assets.leetcode.com/uploads/2022/03/10/ex3new.jpg
输入：grid = [[0,0,0],[2,2,0],[1,2,0]]
输出：1000000000
解释：上图展示了初始网格图。
注意，由于火被墙围了起来，所以无论如何你都能安全到达安全屋。
所以返回 10^9 。

提示：
  m == grid.length
  n == grid[i].length
  2 <= m, n <= 300
  4 <= m * n <= 2 * 10^4
  grid[i][j] 是 0 ，1 或者 2 。
  grid[0][0] == grid[m - 1][n - 1] == 0
*/

// https://leetcode.cn/problems/escape-the-spreading-fire/solutions/1460794/er-fen-bfspythonjavacgo-by-endlesscheng-ypp1/
class Solution {
	typedef std::array<int, 3> elem;
	enum { INF = static_cast<int>(1e9) };

	elem bfs(vector<vector<int>> const& grid, vector<int>& Q)
	{
		int const dirs[] = {-1, 0, 1, 0, -1};

		int rows = static_cast<int>(grid.size());
		int cols = static_cast<int>(grid[0].size());
		vector<int> step(rows * cols, INF);
		for (int f : Q)
			step[f] = 0;
		for (size_t i = 0; i < Q.size(); ++i) {
			int f = Q[i];
			int x = f % cols, y = f / cols;
			for (int d = 0; d < 4; ++d) {
				int h = y + dirs[d];
				int w = x + dirs[d + 1];
				int t = h * cols + w;
				if (static_cast<unsigned>(h) < static_cast<unsigned>(rows)
					&& static_cast<unsigned>(w) < static_cast<unsigned>(cols)
					&& step[t] == INF && grid[h][w] == 0) {
					Q.push_back(t);
					step[t] = step[f] + 1;
				}
			}
		}
		int last = rows * cols - 1;
		return {step[last], step[last - 1], step[last - cols]};
	}

public:
	int maximumMinutes(vector<vector<int>> const& grid)
	{
		int rows = static_cast<int>(grid.size());
		int cols = static_cast<int>(grid[0].size());

		vector<int> Q = {0};
		elem mine = bfs(grid, Q);
		// 人无法到安全屋
		if (mine[0] == INF) return -1;

		Q.clear();
		for (int h = 0; h < rows; ++h)
			for (int w = 0; w < cols; ++w)
				if (grid[h][w] == 1)
					Q.push_back(h * cols + w);
		elem fire = bfs(grid, Q);
		// 火无法到安全屋
		if (fire[0] == INF) return INF;

		int d = fire[0] - mine[0];
		// 火比人先到安全屋
		if (d < 0) return -1;
		// 安全屋左边或上面相邻格子，人比火先到
		if ((mine[1] != INF && mine[1] + d < fire[1])
			|| (mine[2] != INF && mine[2] + d < fire[2]))
			return d;
		else
			return d - 1;
	}
};

int main()
{
	vector<vector<int>>
		g1 = {{0, 2, 0, 0, 0, 0, 0}, {0, 0, 0, 2, 2, 1, 0}, {0, 2, 0, 0, 1, 2, 0}, {0, 0, 2, 2, 2, 0, 2}, {0, 0, 0, 0, 0, 0, 0}},
		g2 = {{0, 0, 0, 0}, {0, 1, 2, 0}, {0, 2, 0, 0}},
		g3 = {{0, 0, 0}, {2, 2, 0}, {1, 2, 0}};
	Solution s;
	ToOut(s.maximumMinutes(g1));
	ToOut(s.maximumMinutes(g2));
	ToOut(s.maximumMinutes(g3));
}
