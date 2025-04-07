#include "leetcode.hpp"

/* 2608. 图中的最短环

现有一个含 n 个顶点的 双向 图，每个顶点按从 0 到 n - 1 标记。
图中的边由二维整数数组 edges 表示，其中 edges[i] = [ui, vi] 表示顶点 ui 和 vi 之间存在一条边。每对顶点最多通过一条边连接，并且不存在与自身相连的顶点。

返回图中 最短 环的长度。如果不存在环，则返回 -1 。

环 是指以同一节点开始和结束，并且路径中的每条边仅使用一次。

示例 1：
https://assets.leetcode.com/uploads/2023/01/04/cropped.png
输入：n = 7, edges = [[0,1],[1,2],[2,0],[3,4],[4,5],[5,6],[6,3]]
输出：3
解释：长度最小的循环是：0 -> 1 -> 2 -> 0

示例 2：
https://assets.leetcode.com/uploads/2023/01/04/croppedagin.png
输入：n = 4, edges = [[0,1],[0,2]]
输出：-1
解释：图中不存在循环

提示：
  2 <= n <= 1000
  1 <= edges.length <= 1000
  edges[i].length == 2
  0 <= ui, vi < n
  ui != vi
  不存在重复的边
*/

int findShortestCycle(int n,
	vector<vector<int>> const& edges)
{
	vector<vector<int>> adj(n);
	for (auto const& edge : edges) {
		adj[edge[0]].push_back(edge[1]);
		adj[edge[1]].push_back(edge[0]);
	}
	int ans = INT_MAX;
	vector<int> D(n);
	vector<pair<int, int>> Q;
	for (int i = 0; i < n; ++i) {
		if (D[i] == -2)
			continue;
		Q.assign({{i, -1}});
		for (int k = 0; k < n; ++k)
			if (D[k] != -2) D[k] = -1;
		D[i] = 0;
		bool haveCycle = false;
		for (size_t k = 0; k < Q.size(); ++k) {
			int f = Q[k].first, par = Q[k].second;
			for (int t : adj[f]) {
				if (D[t] == -1) {
					D[t] = D[f] + 1;
					Q.push_back({t, f});
				} else if (t != par) {
					ans = min(ans, D[f] + D[t] + 1);
					haveCycle = true;
				}
			}
		}
		// 如果找不到环，说明所有跟它相连的点都没环，标记后直接跳过
		if (!haveCycle)
			for (auto& q : Q)
				D[q.first] = -2;
	}
	return ans == INT_MAX ? -1 : ans;
}

int main()
{
	ToOut(findShortestCycle(7,
		{{0, 1}, {1, 2}, {2, 0}, {3, 4}, {4, 5}, {5, 6}, {6, 3}}));
	ToOut(findShortestCycle(4, {{0, 1}, {0, 2}}));
}
