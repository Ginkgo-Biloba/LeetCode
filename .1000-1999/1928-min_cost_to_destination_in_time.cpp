#include "leetcode.hpp"

/* 1928. 规定时间内到达终点的最小花费

一个国家有 n 个城市，城市编号为 0 到 n - 1 ，题目保证 所有城市 都由双向道路 连接在一起 。
道路由二维整数数组 edges 表示，其中 edges[i] = [xi, yi, timei] 表示城市 xi 和 yi 之间有一条双向道路，耗费时间为 timei 分钟。
两个城市之间可能会有多条耗费时间不同的道路，但是不会有道路两头连接着同一座城市。

每次经过一个城市时，你需要付通行费。
通行费用一个长度为 n 且下标从 0 开始的整数数组 passingFees 表示，其中 passingFees[j] 是你经过城市 j 需要支付的费用。

一开始，你在城市 0 ，你想要在 maxTime 分钟以内 （包含 maxTime 分钟）到达城市 n - 1 。
旅行的 费用 为你经过的所有城市 通行费之和 （包括 起点和终点城市的通行费）。

给你 maxTime，edges 和 passingFees ，请你返回完成旅行的 最小费用 ，如果无法在 maxTime 分钟以内完成旅行，请你返回 -1 。

示例 1：
https://assets.leetcode.com/uploads/2021/06/04/leetgraph1-1.png
输入：maxTime = 30, edges = [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees = [5,1,2,20,20,3]
输出：11
解释：最优路径为 0 -> 1 -> 2 -> 5 ，总共需要耗费 30 分钟，需要支付 11 的通行费。

示例 2：
https://assets.leetcode.com/uploads/2021/06/04/copy-of-leetgraph1-1.png
输入：maxTime = 29, edges = [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees = [5,1,2,20,20,3]
输出：48
解释：最优路径为 0 -> 3 -> 4 -> 5 ，总共需要耗费 26 分钟，需要支付 48 的通行费。
你不能选择路径 0 -> 1 -> 2 -> 5 ，因为这条路径耗费的时间太长。

示例 3：
输入：maxTime = 25, edges = [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees = [5,1,2,20,20,3]
输出：-1
解释：无法在 25 分钟以内从城市 0 到达城市 5 。

提示：
  1 <= maxTime <= 1000
  n == passingFees.length
  2 <= n <= 1000
  n - 1 <= edges.length <= 1000
  0 <= xi, yi <= n - 1
  1 <= timei <= 1000
  1 <= passingFees[j] <= 1000
  图中两个节点之间可能有多条路径。
  图中不含有自环。
*/

int minCost(int maxTime, vector<vector<int>>& edge, vector<int>& fee)
{
	using I3 = array<int, 3>;
	int n = static_cast<int>(fee.size());
	vector<vector<I3>> adj(n);
	vector<int> cost(n, INT_MAX), need(n, INT_MAX);
	for (vector<int>& e : edge) {
		adj[e[0]].push_back({e[1], e[2], fee[e[1]]});
		adj[e[1]].push_back({e[0], e[2], fee[e[0]]});
	}
	need[0] = 0;
	cost[0] = fee[0];

	priority_queue<I3, vector<I3>, std::greater<I3>> pq;
	pq.push({cost[0], need[0], 0});
	while (pq.size()) {
		auto elem = pq.top();
		int c = elem[0]; // cost
		int t = elem[1]; // time
		int v = elem[2]; // vertex
		pq.pop();
		if (v == n - 1)
			return c;
		for (auto& j : adj[v]) {
			if (t + j[1] > maxTime)
				continue;
			if (cost[j[0]] > c + j[2]) {
				cost[j[0]] = c + j[2];
				need[j[0]] = t + j[1];
				pq.push({cost[j[0]], need[j[0]], j[0]});
			} else if (need[j[0]] > t + j[1]) {
				need[j[0]] = t + j[1];
				pq.push({c + j[2], need[j[0]], j[0]});
			}
		}
	}

	return -1;
}

int main()
{
	vector<vector<int>>
		a = {{0, 1, 10}, {1, 2, 10}, {2, 5, 10}, {0, 3, 1}, {3, 4, 10}, {4, 5, 15}},
		c = {{1, 2, 4}, {2, 0, 9}, {3, 0, 4}, {0, 1, 9}, {4, 3, 10}, {4, 3, 8}, {3, 1, 2}, {2, 1, 9}, {0, 2, 1}, {4, 1, 2}};
	vector<int>
		b = {5, 1, 2, 20, 20, 3},
		d = {8, 5, 10, 4, 10};
	ToOut(minCost(30, a, b));
	ToOut(minCost(29, a, b));
	ToOut(minCost(25, a, b));
	ToOut(minCost(10, c, d));
}
