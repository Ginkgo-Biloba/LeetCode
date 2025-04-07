#include "leetcode.hpp"

/* 1840. 最高建筑高度

在一座城市里，你需要建 n 栋新的建筑。
这些新的建筑会从 1 到 n 编号排成一列。

这座城市对这些新建筑有一些规定：
  每栋建筑的高度必须是一个非负整数。
  第一栋建筑的高度 必须 是 0 。
  任意两栋相邻建筑的高度差 不能超过 1 。

除此以外，某些建筑还有额外的最高高度限制。
这些限制会以二维整数数组 restrictions 的形式给出，其中 restrictions[i] = [idi, maxHeighti] ，表示建筑 idi 的高度 不能超过 maxHeighti 。

题目保证每栋建筑在 restrictions 中 至多出现一次 ，同时建筑 1 不会 出现在 restrictions 中。

请你返回 最高 建筑能达到的 最高高度 。

示例 1：
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/04/25/ic236-q4-ex1-1.png
输入：n = 5, restrictions = [[2,1],[4,1]]
输出：2
解释：上图中的绿色区域为每栋建筑被允许的最高高度。
我们可以使建筑高度分别为 [0,1,2,1,2] ，最高建筑的高度为 2 。

示例 2：
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/04/25/ic236-q4-ex2.png
输入：n = 6, restrictions = []
输出：5
解释：上图中的绿色区域为每栋建筑被允许的最高高度。
我们可以使建筑高度分别为 [0,1,2,3,4,5] ，最高建筑的高度为 5 。

示例 3：
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/04/25/ic236-q4-ex3.png
输入：n = 10, restrictions = [[5,3],[2,5],[7,4],[10,3]]
输出：5
解释：上图中的绿色区域为每栋建筑被允许的最高高度。
我们可以使建筑高度分别为 [0,1,2,3,3,4,4,5,4,3] ，最高建筑的高度为 5 。

提示：
  2 <= n <= 10^9
  0 <= restrictions.length <= min(n - 1, 10^5)
  2 <= idi <= n
  idi 是 唯一的 。
  0 <= maxHeighti <= 10^9
*/

// https://leetcode.com/problems/maximum-building-height/discuss/1175269/C%2B%2B-with-picture-2-passes
// 抄的
int build(vector<vector<int>>& R, int beg, int end, int dir)
{
	int ans = 0;
	for (int i = beg; i != end; i += dir) {
		int a = R[i][1], b = R[i + dir][1];
		int h = a + abs(R[i][0] - R[i + dir][0]);
		if (h > b)
			h = b + (h - b) / 2;
		ans = max(ans, h);
		R[i + dir][1] = min(h, b);
	}
	return ans;
}

int maxBuilding(int n, vector<vector<int>>& R)
{
	R.push_back({1, 0});
	R.push_back({n, n - 1});
	sort(R.begin(), R.end());
	int len = static_cast<int>(R.size());
	int a = build(R, 0, len - 1, +1);
	int b = build(R, len - 1, 0, -1);
	return min(a, b);
}

int main()
{
	vector<vector<int>>
		a = {{2, 1}, {4, 1}},
		b,
		c = {{5, 3}, {2, 5}, {7, 4}, {10, 3}};
	ToOut(maxBuilding(5, a));
	ToOut(maxBuilding(6, b));
	ToOut(maxBuilding(10, c));
}
