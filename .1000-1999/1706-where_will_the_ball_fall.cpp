﻿#include "leetcode.hpp"

/* 1706. 球会落何处

用一个大小为 m x n 的二维网格 grid 表示一个箱子。
你有 n 颗球。箱子的顶部和底部都是开着的。

箱子中的每个单元格都有一个对角线挡板，跨过单元格的两个角，可以将球导向左侧或者右侧。
  将球导向右侧的挡板跨过左上角和右下角，在网格中用 1 表示。
  将球导向左侧的挡板跨过右上角和左下角，在网格中用 -1 表示。

在箱子每一列的顶端各放一颗球。
每颗球都可能卡在箱子里或从底部掉出来。
如果球恰好卡在两块挡板之间的 "V" 形图案，或者被一块挡导向到箱子的任意一侧边上，就会卡住。

返回一个大小为 n 的数组 answer ，其中 answer[i] 是球放在顶部的第 i 列后从底部掉出来的那一列对应的下标，如果球卡在盒子里，则返回 -1 。

示例 1：
https://assets.leetcode.com/uploads/2019/09/26/ball.jpg
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/12/26/ball.jpg
输入：grid = [[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]
输出：[1,-1,-1,-1,-1]
解释：示例如图：
b0 球开始放在第 0 列上，最终从箱子底部第 1 列掉出。
b1 球开始放在第 1 列上，会卡在第 2、3 列和第 1 行之间的 "V" 形里。
b2 球开始放在第 2 列上，会卡在第 2、3 列和第 0 行之间的 "V" 形里。
b3 球开始放在第 3 列上，会卡在第 2、3 列和第 0 行之间的 "V" 形里。
b4 球开始放在第 4 列上，会卡在第 2、3 列和第 1 行之间的 "V" 形里。

示例 2：
输入：grid = [[-1]]
输出：[-1]
解释：球被卡在箱子左侧边上。

提示：
  m == grid.length
  n == grid[i].length
  1 <= m, n <= 100
  grid[i][j] 为 1 或 -1
*/

vector<int> findBall(vector<vector<int>>& grid)
{
	int rows = static_cast<int>(grid.size());
	int cols = static_cast<int>(grid[0].size());
	vector<int> pre(cols), cur(cols);
	for (int w = 0; w < cols; ++w)
		cur[w] = w;
	for (int h = 0; h < rows; ++h) {
		int* ptr = grid[h].data();
		pre.swap(cur);
		for (int w = 0; w < cols; ++w) {
			int x = pre[w];
			if (x < 0) {
				cur[w] = pre[w];
				continue;
			}
			if (ptr[x] > 0) {
				if (x == cols - 1 || ptr[x + 1] < 0)
					cur[w] = -1;
				else
					cur[w] = x + 1;
			} else {
				if (x == 0 || ptr[x - 1] > 0)
					cur[w] = -1;
				else
					cur[w] = x - 1;
			}
		}
	}
	return cur;
}

int main()
{
}
