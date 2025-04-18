﻿#include "leetcode.hpp"

/* 2368. 受限条件下可到达节点的数目

现有一棵由 n 个节点组成的无向树，节点编号从 0 到 n - 1 ，共有 n - 1 条边。

给你一个二维整数数组 edges ，长度为 n - 1 ，其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条边。另给你一个整数数组 restricted 表示 受限 节点。

在不访问受限节点的前提下，返回你可以从节点 0 到达的 最多 节点数目。

注意，节点 0 不 会标记为受限节点。

示例 1：
https://assets.leetcode.com/uploads/2022/06/15/ex1drawio.png
输入：n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]
输出：4
解释：上图所示正是这棵树。
在不访问受限节点的前提下，只有节点 [0,1,2,3] 可以从节点 0 到达。

示例 2：
https://assets.leetcode.com/uploads/2022/06/15/ex1drawio.png
输入：n = 7, edges = [[0,1],[0,2],[0,5],[0,4],[3,2],[6,5]], restricted = [4,2,1]
输出：3
解释：上图所示正是这棵树。
在不访问受限节点的前提下，只有节点 [0,5,6] 可以从节点 0 到达。

提示：
  2 <= n <= 10^5
  edges.length == n - 1
  edges[i].length == 2
  0 <= ai, bi < n
  ai != bi
  edges 表示一棵有效的树
  1 <= restricted.length < n
  1 <= restricted[i] < n
  restricted 中的所有值 互不相同
*/

int reachableNodes(int n,
	vector<vector<int>> const& edges, vector<int>& restricted)
{
	vector<vector<int>> adj(n);
	std::sort(restricted.begin(), restricted.end());
	for (auto& e : edges) {
		if (std::binary_search(restricted.begin(), restricted.end(), e[0])
			|| std::binary_search(restricted.begin(), restricted.end(), e[1]))
			continue;
		adj[e[0]].push_back(e[1]);
		adj[e[1]].push_back(e[0]);
	}
	vector<int> Q = {0};
	vector<char> visited(n);
	visited[0] = 1;
	for (size_t i = 0; i < Q.size(); ++i) {
		int f = Q[i];
		for (int t : adj[f])
			if (!visited[t]) {
				visited[t] = 1;
				Q.push_back(t);
			}
	}
	return static_cast<int>(Q.size());
}

int main()
{
	vector<vector<int>>
		e1 = {{0, 1}, {1, 2}, {3, 1}, {4, 0}, {0, 5}, {5, 6}},
		e2 = {{0, 1}, {0, 2}, {0, 5}, {0, 4}, {3, 2}, {6, 5}};
	vector<int>
		r1 = {4, 5},
		r2 = {4, 2, 1};
	ToOut(reachableNodes(7, e1, r1));
	ToOut(reachableNodes(7, e2, r2));
}
