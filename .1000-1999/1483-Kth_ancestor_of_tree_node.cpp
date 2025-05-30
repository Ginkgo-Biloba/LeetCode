﻿#include "leetcode.hpp"

/* 1483. 树节点的第 K 个祖先

给你一棵树，树上有 n 个节点，按从 0 到 n-1 编号。
树以父节点数组的形式给出，其中 parent[i] 是节点 i 的父节点。
树的根节点是编号为 0 的节点。

请你设计并实现 getKthAncestor(int node, int k) 函数，函数返回节点 node 的第 k 个祖先节点。
如果不存在这样的祖先节点，返回 -1 。

树节点的第 k 个祖先节点是从该节点到根节点路径上的第 k 个节点。

示例：
https://assets.leetcode.com/uploads/2019/08/28/1528_ex1.png
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/06/14/1528_ex1.png

输入：
["TreeAncestor","getKthAncestor","getKthAncestor","getKthAncestor"]
[[7,[-1,0,0,1,1,2,2]],[3,1],[5,2],[6,3]]

输出：
[null,1,0,-1]

解释：
TreeAncestor treeAncestor = new TreeAncestor(7, [-1, 0, 0, 1, 1, 2, 2]);

treeAncestor.getKthAncestor(3, 1);  // 返回 1 ，它是 3 的父节点
treeAncestor.getKthAncestor(5, 2);  // 返回 0 ，它是 5 的祖父节点
treeAncestor.getKthAncestor(6, 3);  // 返回 -1 因为不存在满足要求的祖先节点

提示：
  1 <= k <= n <= 5*10^4
  parent[0] == -1 表示编号为 0 的节点是根节点。
  对于所有的 0 < i < n ，0 <= parent[i] < n 总成立
  0 <= node < n
  至多查询 5*10^4 次
*/

// https://leetcode.com/problems/kth-ancestor-of-a-tree-node/discuss/686362/JavaC%2B%2BPython-Binary-Lifting
// 抄的
class TreeAncestor {
	vector<array<int, 20>> par;

public:
	TreeAncestor(int n, vector<int>& parent)
	{
		par.resize(n);
		for (int i = 0; i < n; ++i)
			par[i][0] = parent[i];
		for (int p = 1; p < 20; ++p)
			for (int i = 0; i < n; ++i) {
				int h = par[i][p - 1];
				if (h == -1)
					par[i][p] = -1;
				else
					par[i][p] = par[h][p - 1];
			}
	}

	int getKthAncestor(int node, int k)
	{
		for (int p = 0; p < 20; ++p) {
			if (k & (1 << p))
				node = par[node][p];
			if (node == -1)
				break;
		}
		return node;
	}
};

int main()
{
	vector<int> a = {-1, 0, 0, 1, 1, 2, 2};
	TreeAncestor t(7, a);
	ToOut(t.getKthAncestor(3, 1));
	ToOut(t.getKthAncestor(5, 2));
	ToOut(t.getKthAncestor(6, 3));
	ToOut(t.getKthAncestor(6, 9));
}
