#include "leetcode.hpp"

/* 1938. 查询最大基因差

给你一棵 n 个节点的有根树，节点编号从 0 到 n - 1 。
每个节点的编号表示这个节点的 独一无二的基因值 （也就是说节点 x 的基因值为 x）。
两个基因值的 基因差 是两者的 异或和 。

给你整数数组 parents ，其中 parents[i] 是节点 i 的父节点。
如果节点 x 是树的 根 ，那么 parents[x] == -1 。

给你查询数组 queries ，其中 queries[i] = [nodei, vali] 。
对于查询 i ，请你找到 vali 和 pi 的 最大基因差 ，其中 pi 是节点 nodei 到根之间的任意节点（包含 nodei 和根节点）。
更正式的，你想要最大化 vali XOR pi 。

请你返回数组 ans ，其中 ans[i] 是第 i 个查询的答案。

示例 1：
https://assets.leetcode.com/uploads/2021/06/29/c1.png
输入：parents = [-1,0,1,1], queries = [[0,2],[3,2],[2,5]]
输出：[2,3,7]
解释：查询数组处理如下：
- [0,2]：最大基因差的对应节点为 0 ，基因差为 2 XOR 0 = 2 。
- [3,2]：最大基因差的对应节点为 1 ，基因差为 2 XOR 1 = 3 。
- [2,5]：最大基因差的对应节点为 2 ，基因差为 5 XOR 2 = 7 。

示例 2：
https://assets.leetcode.com/uploads/2021/06/29/c2.png
输入：parents = [3,7,-1,2,0,7,0,2], queries = [[4,6],[1,15],[0,5]]
输出：[6,14,7]
解释：查询数组处理如下：
- [4,6]：最大基因差的对应节点为 0 ，基因差为 6 XOR 0 = 6 。
- [1,15]：最大基因差的对应节点为 1 ，基因差为 15 XOR 1 = 14 。
- [0,5]：最大基因差的对应节点为 2 ，基因差为 5 XOR 2 = 7 。

提示：
  2 <= parents.length <= 10^5
  对于每个 不是 根节点的 i ，有 0 <= parents[i] <= parents.length - 1 。
  parents[root] == -1
  1 <= queries.length <= 3 * 10^4
  0 <= nodei <= parents.length - 1
  0 <= vali <= 2 * 10^5
*/

struct Node {
	int h;
	Node* c[2];
};

// 抄的
class Solution {
	Node root;
	size_t idxbuf;
	vector<Node> buffer;
	vector<Node*> qalloc;
	vector<vector<int>> G;
	vector<vector<pair<int, int>>> Q;
	vector<int> R;

	Node* create()
	{
		Node* q = nullptr;
		if (idxbuf < buffer.size()) {
			q = buffer.data() + idxbuf;
			++idxbuf;
		} else {
			q = static_cast<Node*>(malloc(sizeof(*q)));
			qalloc.push_back(q);
		}
		q->h = 0;
		q->c[0] = q->c[1] = nullptr;
		return q;
	}

	void release()
	{
		idxbuf = 0;
		buffer.resize(800000);
		for (Node* q : qalloc)
			free(q);
		qalloc.clear();
	}

	void insert(int x, int d)
	{
		Node* q = &root;
		for (int i = 17; i >= 0; --i) {
			int b = (x >> i) & 1;
			if (!(q->c[b]))
				q->c[b] = create();
			q = q->c[b];
			q->h += d;
		}
	}

	int find(int x)
	{
		int ret = 0;
		Node* q = &root;
		for (int i = 17; i >= 0; --i) {
			int b = 1 - ((x >> i) & 1);
			if (q->c[b] && q->c[b]->h) {
				q = q->c[b];
				ret |= 1 << i;
			} else
				q = q->c[1 - b];
		}
		return ret;
	}

	void dfs(int x)
	{
		insert(x, +1);
		for (auto& q : Q[x])
			R[q.second] = find(q.first);
		for (int y : G[x])
			dfs(y);
		insert(x, -1);
	}

public:
	~Solution() { release(); }

	vector<int> maxGeneticDifference(
		vector<int>& parents, vector<vector<int>>& queries)
	{
		int start = -1;
		int n = static_cast<int>(parents.size());
		int m = static_cast<int>(queries.size());
		memset(&root, 0, sizeof(root));
		G.clear();
		G.resize(n);
		for (int i = 0; i < n; ++i) {
			if (parents[i] == -1)
				start = i;
			else
				G[parents[i]].push_back(i);
		}
		Q.clear();
		Q.resize(n);
		for (int i = 0; i < m; ++i)
			Q[queries[i][0]].push_back({queries[i][1], i});
		R.resize(m);
		dfs(start);
		return std::move(R);
	}
};

int main() { }
