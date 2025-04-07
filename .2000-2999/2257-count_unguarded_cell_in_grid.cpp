#include "leetcode.hpp"

/* 2257. 统计网格图中没有被保卫的格子数

给你两个整数 m 和 n 表示一个下标从 0 开始的 m x n 网格图。
同时给你两个二维整数数组 guards 和 walls ，其中 guards[i] = [rowi, coli] 且 walls[j] = [rowj, colj] ，分别表示第 i 个警卫和第 j 座墙所在的位置。

一个警卫能看到 4 个坐标轴方向（即东、南、西、北）的 所有 格子，除非他们被一座墙或者另外一个警卫 挡住 了视线。
如果一个格子能被 至少 一个警卫看到，那么我们说这个格子被 保卫 了。

请你返回空格子中，有多少个格子是 没被保卫 的。

示例 1：
https://assets.leetcode.com/uploads/2022/03/10/example1drawio2.png
输入：m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls = [[0,1],[2,2],[1,4]]
输出：7
解释：上图中，被保卫和没有被保卫的格子分别用红色和绿色表示。
总共有 7 个没有被保卫的格子，所以我们返回 7 。

示例 2：
https://assets.leetcode.com/uploads/2022/03/10/example2drawio.png
输入：m = 3, n = 3, guards = [[1,1]], walls = [[0,1],[1,0],[2,1],[1,2]]
输出：4
解释：上图中，没有被保卫的格子用绿色表示。
总共有 4 个没有被保卫的格子，所以我们返回 4 。

提示：
  1 <= m, n <= 10^5
  2 <= m * n <= 10^5
  1 <= guards.length, walls.length <= 5 * 10^4
  2 <= guards.length + walls.length <= m * n
  guards[i].length == walls[j].length == 2
  0 <= rowi, rowj < m
  0 <= coli, colj < n
  guards 和 walls 中所有位置 互不相同 。
*/

int countUnguarded(int m, int n,
	vector<vector<int>>& guards, vector<vector<int>>& walls)
{
	vector<int8_t> GorW(m * n);
	vector<int> seen(m * n);
	for (auto& p : guards) {
		int i = p[0] * n + p[1];
		GorW[i] = -1;
		seen[i] = -1;
	}
	for (auto& p : walls) {
		int i = p[0] * n + p[1];
		GorW[i] = -2;
		seen[i] = -2;
	}
	vector<int> col(n);
	for (int y = 0; y < m; ++y) {
		int row = 0;
		int8_t const* G = GorW.data() + y * n;
		int* S = seen.data() + y * n;
		for (int x = 0; x < n; ++x) {
			if (G[x] == -1) {
				++row;
				++col[x];
			} else if (G[x] == -2) {
				row = 0;
				col[x] = 0;
			} else
				S[x] += row + col[x];
		}
	}
	col.assign(n, 0);
	for (int y = m; y--;) {
		int row = 0;
		int8_t const* G = GorW.data() + y * n;
		int* S = seen.data() + y * n;
		for (int x = n; x--;) {
			if (G[x] == -1) {
				++row;
				++col[x];
			} else if (G[x] == -2) {
				row = 0;
				col[x] = 0;
			} else
				S[x] += row + col[x];
		}
	}
	int ans = 0;
	for (int i : seen)
		ans += i == 0;
	return ans;
}

int main()
{
	vector<vector<int>>
		g1 = {{0, 0}, {1, 1}, {2, 3}},
		w1 = {{0, 1}, {2, 2}, {1, 4}},
		g2 = {{1, 1}},
		w2 = {{0, 1}, {1, 0}, {2, 1}, {1, 2}};
	ToOut(countUnguarded(4, 6, g1, w1));
	ToOut(countUnguarded(3, 3, g2, w2));
}
