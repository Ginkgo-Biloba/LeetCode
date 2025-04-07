#include "leetcode.hpp"

/* 2482. 行和列中一和零的差值

给你一个下标从 0 开始的 m x n 二进制矩阵 grid 。

我们按照如下过程，定义一个下标从 0 开始的 m x n 差值矩阵 diff ：

令第 i 行一的数目为 onesRowi 。
令第 j 列一的数目为 onesColj 。
令第 i 行零的数目为 zerosRowi 。
令第 j 列零的数目为 zerosColj 。
diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj
请你返回差值矩阵 diff 。

示例 1：
https://assets.leetcode.com/uploads/2022/11/06/image-20221106171729-5.png
输入：grid = [[0,1,1],[1,0,1],[0,0,1]]
输出：[[0,0,4],[0,0,4],[-2,-2,2]]
解释：
- diff[0][0] = onesRow0 + onesCol0 - zerosRow0 - zerosCol0 = 2 + 1 - 1 - 2 = 0
- diff[0][1] = onesRow0 + onesCol1 - zerosRow0 - zerosCol1 = 2 + 1 - 1 - 2 = 0
- diff[0][2] = onesRow0 + onesCol2 - zerosRow0 - zerosCol2 = 2 + 3 - 1 - 0 = 4
- diff[1][0] = onesRow1 + onesCol0 - zerosRow1 - zerosCol0 = 2 + 1 - 1 - 2 = 0
- diff[1][1] = onesRow1 + onesCol1 - zerosRow1 - zerosCol1 = 2 + 1 - 1 - 2 = 0
- diff[1][2] = onesRow1 + onesCol2 - zerosRow1 - zerosCol2 = 2 + 3 - 1 - 0 = 4
- diff[2][0] = onesRow2 + onesCol0 - zerosRow2 - zerosCol0 = 1 + 1 - 2 - 2 = -2
- diff[2][1] = onesRow2 + onesCol1 - zerosRow2 - zerosCol1 = 1 + 1 - 2 - 2 = -2
- diff[2][2] = onesRow2 + onesCol2 - zerosRow2 - zerosCol2 = 1 + 3 - 2 - 0 = 2

示例 2：
https://assets.leetcode.com/uploads/2022/11/06/image-20221106171747-6.png
输入：grid = [[1,1,1],[1,1,1]]
输出：[[5,5,5],[5,5,5]]
解释：
- diff[0][0] = onesRow0 + onesCol0 - zerosRow0 - zerosCol0 = 3 + 2 - 0 - 0 = 5
- diff[0][1] = onesRow0 + onesCol1 - zerosRow0 - zerosCol1 = 3 + 2 - 0 - 0 = 5
- diff[0][2] = onesRow0 + onesCol2 - zerosRow0 - zerosCol2 = 3 + 2 - 0 - 0 = 5
- diff[1][0] = onesRow1 + onesCol0 - zerosRow1 - zerosCol0 = 3 + 2 - 0 - 0 = 5
- diff[1][1] = onesRow1 + onesCol1 - zerosRow1 - zerosCol1 = 3 + 2 - 0 - 0 = 5
- diff[1][2] = onesRow1 + onesCol2 - zerosRow1 - zerosCol2 = 3 + 2 - 0 - 0 = 5


提示：
  m == grid.length
  n == grid[i].length
  1 <= m, n <= 10^5
  1 <= m * n <= 10^5
  grid[i][j] 要么是 0 ，要么是 1 。
*/

vector<vector<int>> onesMinusZeros(vector<vector<int>> const& grid)
{
	int rows = static_cast<int>(grid.size());
	int cols = static_cast<int>(grid[0].size());
	vector<int> R(rows), C(cols);
	for (int h = 0; h < rows; ++h) {
		int const* ptr = grid[h].data();
		for (int w = 0; w < cols; ++w) {
			R[h] += ptr[w];
			C[w] += ptr[w];
		}
	}
	vector<vector<int>> ans(rows, vector<int>(cols));
	for (int h = 0; h < rows; ++h)
		for (int w = 0; w < cols; ++w) {
			ans[h][w] = 2 * (R[h] + C[w]) - (rows + cols);
		}
	return ans;
}

int main()
{
	ToOut(onesMinusZeros({{0, 1, 1}, {1, 0, 1}, {0, 0, 1}}));
	ToOut(onesMinusZeros({{1, 1, 1}, {1, 1, 1}}));
}
