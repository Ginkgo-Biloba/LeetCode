﻿#include "leetcode.hpp"

/* 741. 摘樱桃

一个N x N的网格(grid) 代表了一块樱桃地，每个格子由以下三种数字的一种来表示：
  0 表示这个格子是空的，所以你可以穿过它。
  1 表示这个格子里装着一个樱桃，你可以摘到樱桃然后穿过它。
  -1 表示这个格子里有荆棘，挡着你的路。

你的任务是在遵守下列规则的情况下，尽可能的摘到最多樱桃：
  从位置 (0, 0) 出发，最后到达 (N-1, N-1) ，只能向下或向右走，并且只能穿越有效的格子（即只可以穿过值为0或者1的格子）；
  当到达 (N-1, N-1) 后，你要继续走，直到返回到 (0, 0) ，只能向上或向左走，并且只能穿越有效的格子；
  当你经过一个格子且这个格子包含一个樱桃时，你将摘到樱桃并且这个格子会变成空的（值变为0）；
  如果在 (0, 0) 和 (N-1, N-1) 之间不存在一条可经过的路径，则没有任何一个樱桃能被摘到。

示例 1:
输入: grid =
[[0, 1, -1],
 [1, 0, -1],
 [1, 1,  1]]
输出: 5
解释：
玩家从（0,0）点出发，经过了向下走，向下走，向右走，向右走，到达了点(2, 2)。
在这趟单程中，总共摘到了4颗樱桃，矩阵变成了[[0,1,-1],[0,0,-1],[0,0,0]]。
接着，这名玩家向左走，向上走，向上走，向左走，返回了起始点，又摘到了1颗樱桃。
在旅程中，总共摘到了5颗樱桃，这是可以摘到的最大值了。

说明:
  grid 是一个 N * N 的二维数组，N的取值范围是1 <= N <= 50。
  每一个 grid[i][j] 都是集合 {-1, 0, 1}其中的一个数。
  可以保证起点 grid[0][0] 和终点 grid[N-1][N-1] 的值都不会是 -1。
*/

/* 想像成两个人从左上往右下角走
对于第 M 步，每个人的行数加列数之和肯定是 M
每个人行数定了，列数就也定下来了
两个人总共摘到的樱桃数量是 dp
如果不是荆棘，每个人等于上面或者左边的，如果有重复，只算一次
两个人的位置的组合为 dp 的数量，以对角线为单位向前更新
*/

// https://leetcode.com/problems/cherry-pickup/discuss/109903/Step-by-step-guidance-of-the-O(N3)-time-and-O(N2)-space-solution
// 抄的
int cherryPickup(vector<vector<int>> const& grid)
{
	unsigned N = static_cast<int>(grid.size());
	int M = 2 * N - 1;
	vector<int> dp(N * N);
	auto at = [N](int y, int x) -> int { return y * N + x; };

	dp[at(0, 0)] = grid[0][0];
	for (int n = 1; n < M; ++n)
		for (int i = N - 1; i >= 0; --i)
			for (int p = N - 1; p >= 0; --p) {
				int j = n - i, q = n - p;
				if (static_cast<unsigned>(j) >= N
					|| static_cast<unsigned>(q) >= N
					|| grid[i][j] < 0
					|| grid[p][q] < 0) {
					dp[at(i, p)] = -1;
					continue;
				}

				int v = dp[at(i, p)];
				if (i > 0) v = std::max(v, dp[at(i - 1, p)]);
				if (p > 0) v = std::max(v, dp[at(i, p - 1)]);
				if (i > 0 && p > 0) v = std::max(v, dp[at(i - 1, p - 1)]);
				if (v >= 0) {
					v += grid[i][j];
					if (i != p)
						v += grid[p][q];
				}
				dp[at(i, p)] = v;
			}
	M = dp.back(); // dp[at(N-1, N-1)]
	return std::max(M, 0);
}

int main()
{
	vector<vector<int>> grid = {
		{0, 1, -1},
		{1, 0, -1},
		{1, 1, 1},
	};
	ToOut(cherryPickup(grid));
}
