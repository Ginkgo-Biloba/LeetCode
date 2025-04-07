#include "leetcode.hpp"

/* 2581. 统计可能的树根数目

Alice 有一棵 n 个节点的树，节点编号为 0 到 n - 1 。
树用一个长度为 n - 1 的二维整数数组 edges 表示，其中 edges[i] = [ai, bi] ，表示树中节点 ai 和 bi 之间有一条边。

Alice 想要 Bob 找到这棵树的根。
她允许 Bob 对这棵树进行若干次 猜测 。每一次猜测，Bob 做如下事情：
  选择两个 不相等 的整数 u 和 v ，且树中必须存在边 [u, v] 。
  Bob 猜测树中 u 是 v 的 父节点 。
  Bob 的猜测用二维整数数组 guesses 表示，其中 guesses[j] = [uj, vj] 表示 Bob 猜 uj 是 vj 的父节点。

Alice 非常懒，她不想逐个回答 Bob 的猜测，只告诉 Bob 这些猜测里面 至少 有 k 个猜测的结果为 true 。

给你二维整数数组 edges ，Bob 的所有猜测和整数 k ，请你返回可能成为树根的 节点数目 。
如果没有这样的树，则返回 0。

示例 1：
https://assets.leetcode.com/uploads/2022/12/19/ex-1.png
输入：edges = [[0,1],[1,2],[1,3],[4,2]], guesses = [[1,3],[0,1],[1,0],[2,4]], k = 3
输出：3
解释：
根为节点 0 ，正确的猜测为 [1,3], [0,1], [2,4]
根为节点 1 ，正确的猜测为 [1,3], [1,0], [2,4]
根为节点 2 ，正确的猜测为 [1,3], [1,0], [2,4]
根为节点 3 ，正确的猜测为 [1,0], [2,4]
根为节点 4 ，正确的猜测为 [1,3], [1,0]
节点 0 ，1 或 2 为根时，可以得到 3 个正确的猜测。

示例 2：
https://assets.leetcode.com/uploads/2022/12/19/ex-2.png
输入：edges = [[0,1],[1,2],[2,3],[3,4]], guesses = [[1,0],[3,4],[2,1],[3,2]], k = 1
输出：5
解释：
根为节点 0 ，正确的猜测为 [3,4]
根为节点 1 ，正确的猜测为 [1,0], [3,4]
根为节点 2 ，正确的猜测为 [1,0], [2,1], [3,4]
根为节点 3 ，正确的猜测为 [1,0], [2,1], [3,2], [3,4]
根为节点 4 ，正确的猜测为 [1,0], [2,1], [3,2]
任何节点为根，都至少有 1 个正确的猜测。


提示：
  edges.length == n - 1
  2 <= n <= 10^5
  1 <= guesses.length <= 10^5
  0 <= ai, bi, uj, vj <= n - 1
  ai != bi
  uj != vj
  edges 表示一棵有效的树。
  guesses[j] 是树中的一条边。
  guesses 是唯一的。
  0 <= k <= guesses.length
*/

// https://leetcode.cn/problems/count-number-of-possible-root-nodes/solutions/2147714/huan-gen-dppythonjavacgo-by-endlesscheng-ccwy/
// 抄的
class Solution {
	int cnt0, ans, K;
	vector<vector<int>> adj;
	unordered_set<int64_t> u;

	void dfs(int x, int fa)
	{
		for (int y : adj[x]) {
			if (y != fa) {
				cnt0 += static_cast<int>(
					u.count(static_cast<int64_t>(x) << 32 | y));
				dfs(y, x);
			}
		}
	}

	void reroot(int x, int fa, int cnt)
	{
		// 此时 cnt 就是以 x 为根时的猜对次数
		ans += cnt >= K;
		for (int y : adj[x]) {
			if (y != fa) {
				int val = cnt
					// 原来是对的，现在错了
					- static_cast<int>(u.count(static_cast<int64_t>(x) << 32 | y))
					// 原来是错的，现在对了
					+ static_cast<int>(u.count(static_cast<int64_t>(y) << 32 | x));
				reroot(y, x, val);
			}
		}
	};

public:
	int rootCount(vector<vector<int>> const& edges,
		vector<vector<int>> const& guesses, int k)
	{
		int n = static_cast<int>(edges.size()) + 1;
		adj.resize(n);
		for (int i = 0; i < n; ++i)
			adj[i].clear();
		for (auto& e : edges) {
			int x = e[0], y = e[1];
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		u.clear();
		for (auto& e : guesses)
			u.insert(static_cast<int64_t>(e[0]) << 32 | e[1]);

		K = k;
		ans = cnt0 = 0;
		dfs(0, -1);
		reroot(0, -1, cnt0);
		return ans;
	}
};

int main()
{
	Solution s;
	ToOut(s.rootCount(
		{{0, 1}, {1, 2}, {1, 3}, {4, 2}},
		{{1, 3}, {0, 1}, {1, 0}, {2, 4}},
		3));
	ToOut(s.rootCount(
		{{0, 1}, {1, 2}, {2, 3}, {3, 4}},
		{{1, 0}, {3, 4}, {2, 1}, {3, 2}},
		1));
}
