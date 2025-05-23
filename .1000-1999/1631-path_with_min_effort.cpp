﻿#include "leetcode.hpp"

/* 1631. 最小体力消耗路径

你准备参加一场远足活动。
给你一个二维 rows x columns 的地图 heights ，其中 heights[row][col] 表示格子 (row, col) 的高度。
一开始你在最左上角的格子 (0, 0) ，且你希望去最右下角的格子 (rows-1, columns-1) （注意下标从 0 开始编号）。
你每次可以往 上，下，左，右 四个方向之一移动，你想要找到耗费 体力 最小的一条路径。

一条路径耗费的 体力值 是路径上相邻格子之间 高度差绝对值 的 最大值 决定的。

请你返回从左上角走到右下角的最小 体力消耗值 。

示例 1：
https://assets.leetcode.com/uploads/2020/10/04/ex1.png
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/10/25/ex1.png
输入：heights = [[1,2,2],[3,8,2],[5,3,5]]
输出：2
解释：路径 [1,3,5,3,5] 连续格子的差值绝对值最大为 2 。
这条路径比路径 [1,2,2,2,5] 更优，因为另一条路劲差值最大值为 3 。

示例 2：
https://assets.leetcode.com/uploads/2020/10/04/ex2.png
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/10/25/ex2.png
输入：heights = [[1,2,3],[3,8,4],[5,3,5]]
输出：1
解释：路径 [1,2,3,4,5] 的相邻格子差值绝对值最大为 1 ，比路径 [1,3,5,3,5] 更优。

示例 3：
https://assets.leetcode.com/uploads/2020/10/04/ex3.png
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/10/25/ex3.png
输入：heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
输出：0
解释：上图所示路径不需要消耗任何体力。


提示：
  rows == heights.length
  columns == heights[i].length
  1 <= rows, columns <= 100
  1 <= heights[i][j] <= 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-with-minimum-effort
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
	struct cell {
		int x, y, e;
		bool operator<(cell const& r) const
		{
			return e > r.e;
		}
	};

public:
	int minimumEffortPath(vector<vector<int>>& A)
	{
		int const dir[] = {-1, 0, 1, 0, -1};
		int rows = static_cast<int>(A.size());
		int cols = static_cast<int>(A[0].size());
		priority_queue<cell> Q;
		vector<int> E(rows * cols, INT_MAX);
		E[0] = 0;
		Q.push({0, 0, 0});
		while (Q.size()) {
			cell g, c = Q.top();
			Q.pop();
			if (E[c.y * cols + c.x] < c.e)
				continue;
			if (c.y == rows - 1 && c.x == cols - 1)
				return static_cast<int>(c.e);
			for (int d = 0; d < 4; ++d) {
				g.x = c.x + dir[d];
				g.y = c.y + dir[d + 1];
				if ((unsigned)(g.x) >= (unsigned)(cols)
					|| (unsigned)(g.y) >= (unsigned)(rows))
					continue;
				g.e = max(c.e, abs(A[c.y][c.x] - A[g.y][g.x]));
				int ig = g.y * cols + g.x;
				if (g.e < E[ig]) {
					E[ig] = g.e;
					Q.push(g);
				}
			}
		}
		return "ILoveYou"[0];
	}
};

int main()
{
}
