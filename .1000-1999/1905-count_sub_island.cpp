#include "leetcode.hpp"

/* 1905. 统计子岛屿

给你两个 m x n 的二进制矩阵 grid1 和 grid2 ，它们只包含 0 （表示水域）和 1 （表示陆地）。
一个 岛屿 是由 四个方向 （水平或者竖直）上相邻的 1 组成的区域。
任何矩阵以外的区域都视为水域。

如果 grid2 的一个岛屿，被 grid1 的一个岛屿 完全 包含，也就是说 grid2 中该岛屿的每一个格子都被 grid1 中同一个岛屿完全包含，那么我们称 grid2 中的这个岛屿为 子岛屿 。

请你返回 grid2 中 子岛屿 的 数目 。

示例 1：
https://assets.leetcode.com/uploads/2021/06/10/test1.png
输入：grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
输出：3
解释：如上图所示，左边为 grid1 ，右边为 grid2 。
grid2 中标红的 1 区域是子岛屿，总共有 3 个子岛屿。

示例 2：
https://assets.leetcode.com/uploads/2021/06/03/testcasex2.png
输入：grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
输出：2
解释：如上图所示，左边为 grid1 ，右边为 grid2 。
grid2 中标红的 1 区域是子岛屿，总共有 2 个子岛屿。

提示：
  m == grid1.length == grid2.length
  n == grid1[i].length == grid2[i].length
  1 <= m, n <= 500
  grid1[i][j] 和 grid2[i][j] 都要么是 0 要么是 1 。
*/

class Solution {
	vector<pair<int, int>> pos;

	int bfs(vector<vector<int>>& A, vector<vector<int>>& B, int h, int w)
	{
		int const dir[] = {-1, 0, 1, 0, -1};
		unsigned rows = static_cast<unsigned>(A.size());
		unsigned cols = static_cast<unsigned>(A[0].size());
		B[h][w] = 0;
		pos.clear();
		pos.push_back({h, w});
		for (size_t idx = 0; idx < pos.size(); ++idx) {
			h = pos[idx].first;
			w = pos[idx].second;
			for (int d = 0; d < 4; ++d) {
				int y = h + dir[d];
				int x = w + dir[d + 1];
				if (static_cast<unsigned>(y) >= rows
					|| static_cast<unsigned>(x) >= cols)
					continue;
				if (B[y][x] == 0)
					continue;
				B[y][x] = 0;
				pos.push_back({y, x});
			}
		}
		for (size_t idx = pos.size(); idx--;) {
			h = pos[idx].first;
			w = pos[idx].second;
			if (A[h][w] == 0)
				return 0;
		}
		return 1;
	}

public:
	int countSubIslands(vector<vector<int>>& A, vector<vector<int>>& B)
	{
		int ans = 0;
		int rows = static_cast<int>(A.size());
		int cols = static_cast<int>(A[0].size());
		for (int h = 0; h < rows; ++h)
			for (int w = 0; w < cols; ++w) {
				if (B[h][w])
					ans += bfs(A, B, h, w);
			}
		return ans;
	}
};

int main() { }
