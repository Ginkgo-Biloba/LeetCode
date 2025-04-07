#include "leetcode.hpp"

/* 2246. 相邻字符不同的最长路径

给你一棵 树（即一个连通、无向、无环图），根节点是节点 0 ，这棵树由编号从 0 到 n - 1 的 n 个节点组成。
用下标从 0 开始、长度为 n 的数组 parent 来表示这棵树，其中 parent[i] 是节点 i 的父节点，由于节点 0 是根节点，所以 parent[0] == -1 。

另给你一个字符串 s ，长度也是 n ，其中 s[i] 表示分配给节点 i 的字符。

请你找出路径上任意一对相邻节点都没有分配到相同字符的 最长路径 ，并返回该路径的长度。

示例 1：
https://assets.leetcode.com/uploads/2022/03/25/testingdrawio.png
输入：parent = [-1,0,0,1,1,2], s = "abacbe"
输出：3
解释：任意一对相邻节点字符都不同的最长路径是：0 -> 1 -> 3 。该路径的长度是 3 ，所以返回 3 。
可以证明不存在满足上述条件且比 3 更长的路径。

示例 2：
https://assets.leetcode.com/uploads/2022/03/25/graph2drawio.png
输入：parent = [-1,0,0,0], s = "aabc"
输出：3
解释：任意一对相邻节点字符都不同的最长路径是：2 -> 0 -> 3 。该路径的长度为 3 ，所以返回 3 。

提示：
  n == parent.length == s.length
  1 <= n <= 10^5
  对所有 i >= 1 ，0 <= parent[i] <= n - 1 均成立
  parent[0] == -1
  parent 表示一棵有效的树
  s 仅由小写英文字母组成
*/

class Solution {
	struct Adj {
		vector<int> cto, idx;
	};

	void bfs(Adj const& adj, int n, int start, vector<int>& D, vector<int>& Q)
	{
		D[start] = 0;
		Q.assign({start});
		for (size_t i = 0; i < Q.size(); ++i) {
			int f = Q[i];
			int lo = adj.idx[f], hi = adj.idx[f + 1];
			for (int k = lo; k < hi; ++k) {
				int t = adj.cto[k];
				if (D[t] > n) {
					Q.push_back(t);
					D[t] = D[f] + 1;
				}
			}
		}
	}

public:
	int longestPath(vector<int> const& parent, string s)
	{
		int n = static_cast<int>(s.size());
		vector<pair<int, int>> edges;
		for (int i = 0; i < n; ++i) {
			int h = parent[i];
			if (h >= 0 && s[h] != s[i]) {
				edges.push_back({h, i});
				edges.push_back({i, h});
			}
		}

		std::sort(edges.begin(), edges.end());
		Adj adj;
		adj.cto.resize(edges.size());
		adj.idx.resize(n + 1, static_cast<int>(edges.size()));
		adj.idx[0] = 0;
		for (int r = 0, i = 0; i < adj.idx[n]; ++i) {
			int f = edges[i].first;
			int t = edges[i].second;
			for (; r < f; ++r)
				adj.idx[r + 1] = i;
			adj.cto[i] = t;
		}

		int ans = 1;
		vector<int> D(n, n + 2), Q;
		for (int i = 0; i < n; ++i) {
			if (D[i] < n)
				continue;
			if (adj.idx[i] == adj.idx[i + 1])
				continue;
			int fidx = i, fdis = 0;
			bfs(adj, n, i, D, Q);
			for (int k : Q) {
				if (D[k] > fdis) {
					fidx = k;
					fdis = D[k];
				}
				// 为第二次 bfs 做准备
				D[k] = n + 2;
			}
			bfs(adj, n, fidx, D, Q);
			for (int k : Q)
				fdis = max(fdis, D[k]);
			ans = max(ans, fdis + 1);
		}
		return ans;
	}
};

int main()
{
	Solution s;
	ToOut(s.longestPath({-1, 0, 0, 0}, "aabc"));
	ToOut(s.longestPath({-1, 0, 0}, "aba"));
	ToOut(s.longestPath({-1, 0, 0, 1, 1, 2}, "abacbe"));
	ToOut(s.longestPath({-1}, "z"));
}
