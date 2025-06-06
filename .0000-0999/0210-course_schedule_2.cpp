﻿#include "leetcode.hpp"

/* 210. 课程表 II

现在你总共有 n 门课需要选，记为 0 到 n-1。

在选修某些课程之前需要一些先修课程。
例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]

给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序。

可能会有多个正确的顺序，你只要返回一种就可以了。
如果不可能完成所有课程，返回一个空数组。

示例 1:
输入: 2, [[1,0]]
输出: [0,1]
解释:
总共有 2 门课程。要学习课程 1，你需要先完成课程 0。
因此，正确的课程顺序为 [0,1] 。

示例 2:
输入: 4, [[1,0],[2,0],[3,1],[3,2]]
输出: [0,1,2,3] or [0,2,1,3]
解释:
总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。
并且课程 1 和课程 2 都应该排在课程 0 之后。
因此，一个正确的课程顺序是 [0,1,2,3] 。另一个正确的排序是 [0,2,1,3] 。

说明:
  输入的先决条件是由边缘列表表示的图形，而不是邻接矩阵。详情请参见图的表示法。
  你可以假定输入的先决条件中没有重复的边。
*/

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
	vector<int> req(numCourses), cur, ans;
	vector<vector<int>> adj(numCourses);
	for (auto& p : prerequisites) {
		req[p[0]] += 1;
		adj[p[1]].push_back(p[0]);
	}
	for (int i = 0; i < numCourses; ++i) {
		if (req[i] == 0)
			cur.push_back(i);
	}
	for (size_t d = 0; d < cur.size(); ++d) {
		vector<int>& ngh = adj[cur[d]];
		for (int n : ngh) {
			req[n] -= 1;
			if (req[n] == 0)
				cur.push_back(n);
		}
	}
	if (static_cast<int>(cur.size()) != numCourses)
		cur.clear();
	return cur;
}

int main()
{
	vector<vector<int>>
		a = {{1, 0}},
		b = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
	ToOut(findOrder(2, a));
	ToOut(findOrder(4, b));
}
