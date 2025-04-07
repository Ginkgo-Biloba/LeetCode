#include "leetcode.hpp"

/* 2503. 矩阵查询可获得的最大分数

给你一个大小为 m x n 的整数矩阵 grid 和一个大小为 k 的数组 queries 。

找出一个大小为 k 的数组 answer ，且满足对于每个整数 queries[i] ，你从矩阵 左上角 单元格开始，重复以下过程：

如果 queries[i] 严格 大于你当前所处位置单元格，如果该单元格是第一次访问，则获得 1 分，并且你可以移动到所有 4 个方向（上、下、左、右）上任一 相邻 单元格。
否则，你不能获得任何分，并且结束这一过程。
在过程结束后，answer[i] 是你可以获得的最大分数。
注意，对于每个查询，你可以访问同一个单元格 多次 。

返回结果数组 answer 。

示例 1：
https://assets.leetcode.com/uploads/2022/10/19/yetgriddrawio.png
输入：grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
输出：[5,8,1]
解释：上图展示了每个查询中访问并获得分数的单元格。

示例 2：
https://assets.leetcode.com/uploads/2022/10/20/yetgriddrawio-2.png
输入：grid = [[5,2,1],[1,1,2]], queries = [3]
输出：[0]
解释：无法获得分数，因为左上角单元格的值大于等于 3 。

提示：
  m == grid.length
  n == grid[i].length
  2 <= m, n <= 1000
  4 <= m * n <= 10^5
  k == queries.length
  1 <= k <= 10^4
  1 <= grid[i][j], queries[i] <= 10^6
*/

vector<int> maxPoints(
	vector<vector<int>> const& grid, vector<int> const& queries)
{
	struct Point {
		int h, w, val;
		bool operator<(Point const& rhs) const { return val > rhs.val; }
	};

	int const dirs[] = {-1, 0, 1, 0, -1};
	int rows = static_cast<int>(grid.size());
	int cols = static_cast<int>(grid[0].size());
	vector<int> count(1000001);
	Matrix<int> need(rows, cols);
	need.buffer.assign(need.buffer.size(), INT_MAX);
	priority_queue<Point> Q;
	Q.push({0, 0, grid[0][0]});
	need(0, 0) = grid[0][0];
	while (!Q.empty()) {
		Point p = Q.top();
		Q.pop();
		if (p.val > need(p.h, p.w))
			continue;
		count[p.val] += 1;
		for (int d = 0; d < 4; ++d) {
			int y = p.h + dirs[d];
			int x = p.w + dirs[d + 1];
			if (static_cast<unsigned>(y) >= static_cast<unsigned>(rows)
				|| static_cast<unsigned>(x) >= static_cast<unsigned>(cols))
				continue;
			int v = max(p.val, grid[y][x]);
			if (v < need(y, x)) {
				need(y, x) = v;
				Q.push({y, x, v});
			}
		}
	}
	for (int i = 1; i < 1000001; ++i)
		count[i] += count[i - 1];
	vector<int> ans(queries.size());
	for (size_t i = 0; i < queries.size(); ++i)
		ans[i] = count[queries[i] - 1];
	return ans;
}

int main()
{
	ToOut(maxPoints({{1, 2, 3}, {2, 5, 7}, {3, 5, 1}}, {5, 6, 2}));
	ToOut(maxPoints({{5, 2, 1}, {1, 1, 2}}, {3}));
}
