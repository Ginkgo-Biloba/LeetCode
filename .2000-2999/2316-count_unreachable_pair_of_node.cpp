#include "leetcode.hpp"

/* 2316. 统计无向图中无法互相到达点对数

给你一个整数 n ，表示一张 无向图 中有 n 个节点，编号为 0 到 n - 1 。
同时给你一个二维整数数组 edges ，其中 edges[i] = [ai, bi] 表示节点 ai 和 bi 之间有一条 无向 边。

请你返回 无法互相到达 的不同 点对数目 。

示例 1：
https://assets.leetcode.com/uploads/2022/05/05/tc-3.png
输入：n = 3, edges = [[0,1],[0,2],[1,2]]
输出：0
解释：所有点都能互相到达，意味着没有点对无法互相到达，所以我们返回 0 。

示例 2：
https://assets.leetcode.com/uploads/2022/05/05/tc-2.png
输入：n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
输出：14
解释：总共有 14 个点对互相无法到达：
[[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]]
所以我们返回 14 。

提示：
  1 <= n <= 10^5
  0 <= edges.length <= 2 * 10^5
  edges[i].length == 2
  0 <= ai, bi < n
  ai != bi
  不会有重复边。
*/

void bfs(vector<vector<int>> const& adj,
	vector<char>& visit, vector<int>& Q)
{
	for (size_t i = 0; i < Q.size(); ++i) {
		int f = Q[i];
		for (int t : adj[f])
			if (!visit[t]) {
				visit[t] = 1;
				Q.push_back(t);
			}
	}
}

long long countPairs(int n, vector<vector<int>>& edges)
{
	long long ans = 0;
	vector<vector<int>> adj(n);
	for (auto& e : edges) {
		adj[e[0]].push_back(e[1]);
		adj[e[1]].push_back(e[0]);
	}
	vector<char> visit(n);
	for (int i = 0; i < n; ++i) {
		if (visit[i])
			continue;
		vector<int> Q = {i};
		visit[i] = 1;
		bfs(adj, visit, Q);
		long long cur = static_cast<int>(Q.size());
		ans += cur * (n - cur);
	}
	return ans / 2;
}

int main()
{
	vector<vector<int>>
		e1 = {{0, 1}, {0, 2}, {1, 2}},
		e2 = {{0, 2}, {0, 5}, {2, 4}, {1, 6}, {5, 4}};
	ToOut(countPairs(3, e1));
	ToOut(countPairs(7, e2));
}
