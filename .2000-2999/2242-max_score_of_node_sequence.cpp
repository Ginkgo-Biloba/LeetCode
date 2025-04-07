#include "leetcode.hpp"

/* 2242. 节点序列的最大得分

给你一个 n 个节点的 无向图 ，节点编号为 0 到 n - 1 。

给你一个下标从 0 开始的整数数组 scores ，其中 scores[i] 是第 i 个节点的分数
。同时给你一个二维整数数组 edges ，其中 edges[i] = [ai, bi] ，表示节点 ai 和 bi 之间有一条 无向 边。

一个合法的节点序列如果满足以下条件，我们称它是 合法的 ：

  序列中每 相邻 节点之间有边相连。
  序列中没有节点出现超过一次。

节点序列的分数定义为序列中节点分数之 和 。

请你返回一个长度为 4 的合法节点序列的最大分数。
如果不存在这样的序列，请你返回 -1 。

示例 1：
https://assets.leetcode.com/uploads/2022/04/15/ex1new3.png
输入：scores = [5,2,9,8,4], edges = [[0,1],[1,2],[2,3],[0,2],[1,3],[2,4]]
输出：24
解释：上图为输入的图，节点序列为 [0,1,2,3] 。
节点序列的分数为 5 + 2 + 9 + 8 = 24 。
观察可知，没有其他节点序列得分和超过 24 。
注意节点序列 [3,1,2,0] 和 [1,0,2,3] 也是合法的，且分数为 24 。
序列 [0,3,2,4] 不是合法的，因为没有边连接节点 0 和 3 。

示例 2：
https://assets.leetcode.com/uploads/2022/03/17/ex2.png
输入：scores = [9,20,6,4,11,12], edges = [[0,3],[5,3],[2,4],[1,3]]
输出：-1
解释：上图为输入的图。
没有长度为 4 的合法序列，所以我们返回 -1 。

提示：
  n == scores.length
  4 <= n <= 5 * 10^4
  1 <= scores[i] <= 10^8
  0 <= edges.length <= 5 * 10^4
  edges[i].length == 2
  0 <= ai, bi <= n - 1
  ai != bi
  不会有重边。
*/

int maximumScore(
	vector<int> const& scores, vector<vector<int>> const& edges)
{
	int n = static_cast<int>(scores.size());
	vector<vector<int>> adj(n);
	for (auto& e : edges) {
		adj[e[0]].push_back(e[1]);
		adj[e[1]].push_back(e[0]);
	}
	for (auto& e : adj)
		if (e.size() > 3) {
			std::nth_element(e.begin(), e.begin() + 2, e.end(),
				[&scores](int a, int b) { return scores[a] > scores[b]; });
			e.resize(3);
		}
	int ans = -1;
	for (auto& e : edges) {
		int b = e[0], c = e[1];
		int s = scores[b] + scores[c];
		if (adj[b].size() < 2 || adj[c].size() < 2)
			continue;
		for (int a : adj[b])
			for (int d : adj[c])
				if (a != c && a != d && b != d)
					ans = max(ans, scores[a] + scores[d] + s);
	}
	return ans;
}

int main()
{
	vector<int>
		a = {5, 2, 9, 8, 4},
		b = {9, 20, 6, 4, 11, 12},
		c = {3, 16, 14, 4, 19, 13, 18, 10, 20, 2};
	vector<vector<int>>
		A = {{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}, {2, 4}},
		B = {{0, 3}, {5, 3}, {2, 4}, {1, 3}},
		C = {{0, 4}, {4, 5}, {5, 6}, {8, 9}, {9, 1}, {1, 5}, {6, 8}, {8, 3}, {3, 2}, {6, 2}, {2, 9}, {9, 5}, {8, 1}, {1, 3}, {3, 0}, {8, 4}, {3, 5}, {8, 0}, {6, 1}, {1, 0}};
	ToOut(maximumScore(a, A));
	ToOut(maximumScore(b, B));
	ToOut(maximumScore(c, C));
}
