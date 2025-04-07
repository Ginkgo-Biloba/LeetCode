#include "leetcode.hpp"

/* 2132. 用邮票贴满网格图

给你一个 m x n 的二进制矩阵 grid ，每个格子要么为 0 （空）要么为 1 （被占据）。

给你邮票的尺寸为 stampHeight x stampWidth 。
我们想将邮票贴进二进制矩阵中，且满足以下 限制 和 要求 ：

  覆盖所有 空 格子。
  不覆盖任何 被占据 的格子。
  我们可以放入任意数目的邮票。
  邮票可以相互有 重叠 部分。
  邮票不允许 旋转 。
  邮票必须完全在矩阵 内 。

如果在满足上述要求的前提下，可以放入邮票，请返回 true ，否则返回 false 。

示例 1：
https://assets.leetcode.com/uploads/2021/11/03/ex1.png
输入：grid = [[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0]], stampHeight = 4, stampWidth = 3
输出：true
解释：我们放入两个有重叠部分的邮票（图中标号为 1 和 2），它们能覆盖所有与空格子。

示例 2：
https://assets.leetcode.com/uploads/2021/11/03/ex2.png
输入：grid = [[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]], stampHeight = 2, stampWidth = 2
输出：false
解释：没办法放入邮票覆盖所有的空格子，且邮票不超出网格图以外。

提示：
  m == grid.length
  n == grid[r].length
  1 <= m, n <= 10^5
  1 <= m * n <= 2 * 10^5
  grid[r][c] 要么是 0 ，要么是 1 。
  1 <= stampHeight, stampWidth <= 10^5
*/

bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth)
{
	int rows = static_cast<int>(grid.size());
	int cols = static_cast<int>(grid[0].size());
	int step = cols + 1;
	vector<int> sum((rows + 1) * step);
	vector<int> dif((rows + 1) * step);
#define at(h, w) ((h) * step + (w))

	for (int h = 0; h < rows; ++h) {
		int line = 0;
		for (int w = 0; w < cols; ++w) {
			line += grid[h][w];
			sum[at(h + 1, w + 1)] = sum[at(h, w + 1)] + line;
		}
	}
	for (int h = 0; h < rows; ++h)
		for (int w = 0; w < cols; ++w) {
			if (grid[h][w])
				continue;
			int x = w + stampWidth;
			int y = h + stampHeight;
			if (x > cols || y > rows)
				continue;
			if (sum[at(y, x)] - sum[at(y, w)] - sum[at(h, x)] + sum[at(h, w)])
				continue;
			dif[at(h, w)] += 1;
			dif[at(h, x)] -= 1;
			dif[at(y, w)] -= 1;
			dif[at(y, x)] += 1;
		}

	vector<int> pre(cols + 1), cur(cols + 1);
	for (int h = 0; h < rows; ++h) {
		for (int w = 0; w < cols; ++w) {
			cur[w + 1] = cur[w] + pre[w + 1] - pre[w] + dif[at(h, w)];
			if (cur[w + 1] == 0 && grid[h][w] == 0)
				return false;
		}
		pre.swap(cur);
	}
	return true;
}

int main()
{
}
