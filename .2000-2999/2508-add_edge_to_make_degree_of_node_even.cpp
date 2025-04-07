#include "leetcode.hpp"

/* 2508. 添加边使所有节点度数都为偶数

给你一个有 n 个节点的 无向 图，节点编号为 1 到 n 。
再给你整数 n 和一个二维整数数组 edges ，其中 edges[i] = [ai, bi] 表示节点 ai 和 bi 之间有一条边。
图不一定连通。

你可以给图中添加 至多 两条额外的边（也可以一条边都不添加），使得图中没有重边也没有自环。

如果添加额外的边后，可以使得图中所有点的度数都是偶数，返回 true ，否则返回 false 。

点的度数是连接一个点的边的数目。

示例 1：
https://assets.leetcode.com/uploads/2022/10/26/agraphdrawio.png
输入：n = 5, edges = [[1,2],[2,3],[3,4],[4,2],[1,4],[2,5]]
输出：true
解释：上图展示了添加一条边的合法方案。
最终图中每个节点都连接偶数条边。

示例 2：
https://assets.leetcode.com/uploads/2022/10/26/aagraphdrawio.png
输入：n = 4, edges = [[1,2],[3,4]]
输出：true
解释：上图展示了添加两条边的合法方案。

示例 3：
https://assets.leetcode.com/uploads/2022/10/26/aaagraphdrawio.png
输入：n = 4, edges = [[1,2],[1,3],[1,4]]
输出：false
解释：无法添加至多 2 条边得到一个符合要求的图。

提示：
  3 <= n <= 10^5
  2 <= edges.length <= 10^5
  edges[i].length == 2
  1 <= ai, bi <= n
  ai != bi
  图中不会有重边
*/

bool isPossible(int n, vector<vector<int>> const& edges)
{
	vector<unordered_set<int>> adj(n);
	for (auto& e : edges) {
		adj[e[0] - 1].insert(e[1] - 1);
		adj[e[1] - 1].insert(e[0] - 1);
	}
	vector<int> odd;
	for (int i = 0; i < n; ++i)
		if (adj[i].size() % 2)
			odd.push_back(i);
	if (odd.size() == 2) {
		int a = odd[0], b = odd[1];
		for (int i = 0; i < n; ++i)
			if (!adj[i].count(a) && !adj[i].count(b))
				return true;
	}
	if (odd.size() == 4) {
		int a = odd[0], b = odd[1], c = odd[2], d = odd[3];
		return false
			|| (!adj[a].count(b) && !adj[c].count(d))
			|| (!adj[a].count(c) && !adj[b].count(d))
			|| (!adj[a].count(d) && !adj[b].count(c));
	}
	return odd.empty();
}

int main()
{
	ToOut(isPossible(5, {{1, 2}, {2, 3}, {3, 4}, {4, 2}, {1, 4}, {2, 5}}));
	ToOut(isPossible(4, {{1, 2}, {3, 4}}));
	ToOut(isPossible(4, {{1, 2}, {1, 3}, {1, 4}}));
}
