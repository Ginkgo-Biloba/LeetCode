#include "leetcode.hpp"

/* 2133. 检查是否每一行每一列都包含全部整数

对一个大小为 n x n 的矩阵而言，如果其每一行和每一列都包含从 1 到 n 的 全部 整数（含 1 和 n），则认为该矩阵是一个 有效 矩阵。

给你一个大小为 n x n 的整数矩阵 matrix ，请你判断矩阵是否为一个有效矩阵：如果是，返回 true ；否则，返回 false 。

示例 1：
https://assets.leetcode.com/uploads/2021/12/21/example1drawio.png
输入：matrix = [[1,2,3],[3,1,2],[2,3,1]]
输出：true
解释：在此例中，n = 3 ，每一行和每一列都包含数字 1、2、3 。
因此，返回 true 。

示例 2：
https://assets.leetcode.com/uploads/2021/12/21/example2drawio.png
输入：matrix = [[1,1,1],[1,2,3],[1,2,3]]
输出：false
解释：在此例中，n = 3 ，但第一行和第一列不包含数字 2 和 3 。
因此，返回 false 。

提示：
  n == matrix.length == matrix[i].length
  1 <= n <= 100
  1 <= matrix[i][j] <= n
*/

bool checkValid(vector<vector<int>>& matrix)
{
	int n = static_cast<int>(matrix.size());
	vector<array<char, 112>> col(n);
	memset(col.data(), 0, n * sizeof(col[0]));
	for (int h = 0; h < n; ++h) {
		char row[112] = {0};
		for (int w = 0; w < n; ++w) {
			int val = matrix[h][w] - 1;
			row[val] = 1;
			col[w][val] = 1;
		}
		for (int w = 0; w < n; ++w) {
			if (row[w] == 0)
				return false;
		}
	}
	for (int w = 0; w < n; ++w)
		for (int i = 0; i < n; ++i) {
			if (col[w][i] == 0)
				return false;
		}
	return true;
}

int main() { }
