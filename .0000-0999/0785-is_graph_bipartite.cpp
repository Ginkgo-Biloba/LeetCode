﻿#include "leetcode.hpp"

/* 785. 判断二分图

给定一个无向图 graph，当这个图为二分图时返回 true。

如果我们能将一个图的节点集合分割成两个独立的子集A和B，并使图中的每一条边的两个节点一个来自A集合，一个来自B集合，我们就将这个图称为二分图。

graph将会以邻接表方式给出，graph[i]表示图中与节点i相连的所有节点
。每个节点都是一个在0到graph.length-1之间的整数。
这图中没有自环和平行边： graph[i] 中不存在i，并且graph[i]中没有重复的值。

示例 1:
输入: [[1,3], [0,2], [1,3], [0,2]]
输出: true
解释:
无向图如下:
0----1
|    |
|    |
3----2
我们可以将节点分成两组: {0, 2} 和 {1, 3}。

示例 2:
输入: [[1,2,3], [0,2], [0,1,3], [0,2]]
输出: false
解释:
无向图如下:
0----1
| \  |
|  \ |
3----2
我们不能将节点分割成两个独立的子集。

注意:
  graph 的长度范围为 [1, 100]。
  graph[i] 中的元素的范围为 [0, graph.length - 1]。
  graph[i] 不会包含 i 或者有重复的值。
  图是无向的: 如果j 在 graph[i]里边, 那么 i 也会在 graph[j]里边。
*/

bool isBipartite(vector<vector<int>>& graph)
{
	int N = static_cast<int>(graph.size());
	vector<int> group(N, -1);
	vector<int> q;
	for (int n = 0; n < N; ++n) {
		if (group[n] != -1)
			continue;
		q.clear();
		q.push_back(n);
		group[n] = 1;
		for (size_t i = 0; i < q.size(); ++i) {
			int cur = q[i];
			int ngi = 1 - group[cur];
			vector<int>& adj = graph[cur];
			for (int a : adj) {
				if (group[a] == -1) {
					group[a] = ngi;
					q.push_back(a);
				} else if (group[a] != ngi)
					return false;
			}
		}
	}
	return true;
}

int main()
{
	vector<vector<int>>
		g0 = {{1, 3}, {0, 2}, {1, 3}, {0, 2}},
		g1 = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}},
		g2 = {
			{},
			{2, 4, 6},
			{1, 4, 8, 9},
			{7, 8},
			{1, 2, 8, 9},
			{6, 9},
			{1, 5, 7, 8, 9},
			{3, 6, 9},
			{2, 3, 4, 6, 9},
			{2, 4, 5, 6, 7, 8},
		};
	ToOut(isBipartite(g0));
	ToOut(isBipartite(g1));
	ToOut(isBipartite(g2));
}
