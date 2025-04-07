#include "leetcode.hpp"

/* 2360. 图中的最长环

给你一个 n 个节点的 有向图 ，节点编号为 0 到 n - 1 ，其中每个节点 至多 有一条出边。

图用一个大小为 n 下标从 0 开始的数组 edges 表示，节点 i 到节点 edges[i] 之间有一条有向边。
如果节点 i 没有出边，那么 edges[i] == -1 。

请你返回图中的 最长 环，如果没有任何环，请返回 -1 。

一个环指的是起点和终点是 同一个 节点的路径。

示例 1：
https://assets.leetcode.com/uploads/2022/06/08/graph4drawio-5.png
输入：edges = [3,3,4,2,3]
输出去：3
解释：图中的最长环是：2 -> 4 -> 3 -> 2 。
这个环的长度为 3 ，所以返回 3 。

示例 2：
https://assets.leetcode.com/uploads/2022/06/07/graph4drawio-1.png
输入：edges = [2,-1,3,1]
输出：-1
解释：图中没有任何环。

提示：
  n == edges.length
  2 <= n <= 10^5
  -1 <= edges[i] < n
  edges[i] != i
*/

int bfs(vector<int> const& edges, vector<int>& dist,
	vector<int>& root, int start)
{
	int t = start, d = 0;
	while (t >= 0 && root[t] < 0) {
		dist[t] = d++;
		root[t] = start;
		t = edges[t];
	}
	return t >= 0 && root[t] == start ? d - dist[t] : -1;
}

int longestCycle(vector<int> const& edges)
{
	int ans = -1;
	int n = static_cast<int>(edges.size());
	vector<int> dist(n, n), root(n, -1);
	for (int i = 0; i < n; ++i)
		if (dist[i] == n)
			ans = max(ans, bfs(edges, dist, root, i));
	return ans;
}

int main()
{
	vector<int>
		e1 = {3, 3, 4, 2, 3},
		e2 = {2, -1, 3, 1},
		e3 = {-1, 4, -1, 2, 0, 4};
	ToOut(longestCycle(e3));
	ToOut(longestCycle(e1));
	ToOut(longestCycle(e2));
}
