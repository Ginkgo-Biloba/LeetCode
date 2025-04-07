#include "leetcode.hpp"

/* 1914. 循环轮转矩阵

给你一个大小为 m x n 的整数矩阵 grid​​​ ，其中 m 和 n 都是 偶数 ；另给你一个整数 k 。

矩阵由若干层组成，如下图所示，每种颜色代表一层：
https://assets.leetcode.com/uploads/2021/06/10/ringofgrid.png

矩阵的循环轮转是通过分别循环轮转矩阵中的每一层完成的。
在对某一层进行一次循环旋转操作时，层中的每一个元素将会取代其 逆时针 方向的相邻元素。轮转示例如下：
https://assets.leetcode.com/uploads/2021/06/22/explanation_grid.jpg

返回执行 k 次循环轮转操作后的矩阵。

示例 1：
https://assets.leetcode.com/uploads/2021/06/19/rod2.png
输入：grid = [[40,10],[30,20]], k = 1
输出：[[10,20],[40,30]]
解释：上图展示了矩阵在执行循环轮转操作时每一步的状态。

示例 2：
https://assets.leetcode.com/uploads/2021/06/10/ringofgrid5.png
https://assets.leetcode.com/uploads/2021/06/10/ringofgrid6.png
https://assets.leetcode.com/uploads/2021/06/10/ringofgrid7.png
输入：grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2
输出：[[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]
解释：上图展示了矩阵在执行循环轮转操作时每一步的状态。

提示：
  m == grid.length
  n == grid[i].length
  2 <= m, n <= 50
  m 和 n 都是 偶数
  1 <= grid[i][j] <= 5000
  1 <= k <= 10^9
*/

vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k)
{
	vector<array<int, 2>> pos;
	vector<int> val;
	int const dir[] = {0, 1, 0, -1, 0};
	int rows = static_cast<int>(grid.size());
	int cols = static_cast<int>(grid[0].size());
	int loop = min(rows, cols) / 2;
	for (int rc = 0; rc < loop; ++rc) {
		int h = rc, w = rc, d = 0;
		pos.clear();
		val.clear();
		do {
			pos.push_back({h, w});
			val.push_back(grid[h][w]);
			int y = h + dir[d];
			int x = w + dir[d + 1];
			// printf("%d, %d, %d\n", h, w, d);
			if (y < rc || y >= rows - rc
				|| x < rc || x >= cols - rc) {
				d += 1;
				y = h + dir[d];
				x = w + dir[d + 1];
			}
			h = y;
			w = x;
		} while (h != rc || w != rc);
		int n = static_cast<int>(pos.size());
		int p = k % n;
		for (int i = 0; i < n; ++i) {
			d = (i + p) % n;
			grid[pos[d][0]][pos[i][1]] = val[i];
		}
		// printf("===============\n");
	}
	return std::move(grid);
}

int main() { }
