#include "leetcode.hpp"

/* 2373. 矩阵中的局部最大值

给你一个大小为 n x n 的整数矩阵 grid 。

生成一个大小为 (n - 2) x (n - 2) 的整数矩阵  maxLocal ，并满足：

  maxLocal[i][j] 等于 grid 中以 i + 1 行和 j + 1 列为中心的 3 x 3 矩阵中的 最大值 。

换句话说，我们希望找出 grid 中每个 3 x 3 矩阵中的最大值。

返回生成的矩阵。

示例 1：
https://assets.leetcode.com/uploads/2022/06/21/ex1.png
输入：grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
输出：[[9,9],[8,6]]
解释：原矩阵和生成的矩阵如上图所示。
注意，生成的矩阵中，每个值都对应 grid 中一个相接的 3 x 3 矩阵的最大值。

示例 2：
https://assets.leetcode.com/uploads/2022/07/02/ex2new2.png
输入：grid = [[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]
输出：[[2,2,2],[2,2,2],[2,2,2]]
解释：注意，2 包含在 grid 中每个 3 x 3 的矩阵中。

提示：
  n == grid.length == grid[i].length
  3 <= n <= 100
  1 <= grid[i][j] <= 100
*/

vector<vector<int>> largestLocal(vector<vector<int>> const& src)
{
	int n = static_cast<int>(src.size());
	vector<vector<int>> dst(n - 2);
	for (int i = 0; i < n - 2; ++i)
		dst[i].resize(n - 2);
	vector<int> buffer(n * 3);
	int* D0 = buffer.data();
	int* D1 = D0 + n;
	int* D2 = D1 + n;
	for (int h = 0; h < n; ++h) {
		int const* S = src[h].data();
		for (int w = 2; w < n; ++w)
			D2[w - 2] = max(S[w - 2], max(S[w - 1], S[w]));
		if (h >= 2) {
			int* D = dst[h - 2].data();
			for (int w = 0; w < n - 2; ++w)
				D[w] = max(D0[w], max(D1[w], D2[w]));
		}
		int* tmp = D0;
		D0 = D1, D1 = D2, D2 = tmp;
	}
	return dst;
}

int main()
{
	vector<vector<int>>
		g1 = {
			{9, 9, 8, 1},
			{5, 6, 2, 6},
			{8, 2, 6, 4},
			{6, 2, 2, 2},
		},
		g2 = {
			{1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1},
			{1, 1, 2, 1, 1},
			{1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1},
		};
	ToOut(largestLocal(g1));
	ToOut(largestLocal(g2));
}
