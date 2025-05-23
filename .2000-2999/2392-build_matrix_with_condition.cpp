﻿#include "leetcode.hpp"

/* 2392. 给定条件下构造矩阵

给你一个 正 整数 k ，同时给你：
一个大小为 n 的二维整数数组 rowConditions ，其中 rowConditions[i] = [abovei, belowi]
一个大小为 m 的二维整数数组 colConditions ，其中 colConditions[i] = [lefti, righti] 。

两个数组里的整数都是 1 到 k 之间的数字。

你需要构造一个 k x k 的矩阵，1 到 k 每个数字需要 恰好出现一次 。剩余的数字都是 0 。

矩阵还需要满足以下条件：

对于所有 0 到 n - 1 之间的下标 i ，数字 abovei 所在的 行 必须在数字 belowi 所在行的上面。
对于所有 0 到 m - 1 之间的下标 i ，数字 lefti 所在的 列 必须在数字 righti 所在列的左边。

返回满足上述要求的 任意 矩阵。如果不存在答案，返回一个空的矩阵。

示例 1：
https://assets.leetcode.com/uploads/2022/07/06/gridosdrawio.png
输入：k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
输出：[[3,0,0],[0,0,1],[0,2,0]]
解释：上图为一个符合所有条件的矩阵。
行要求如下：
- 数字 1 在第 1 行，数字 2 在第 2 行，1 在 2 的上面。
- 数字 3 在第 0 行，数字 2 在第 2 行，3 在 2 的上面。
列要求如下：
- 数字 2 在第 1 列，数字 1 在第 2 列，2 在 1 的左边。
- 数字 3 在第 0 列，数字 2 在第 1 列，3 在 2 的左边。
注意，可能有多种正确的答案。

示例 2：

输入：k = 3, rowConditions = [[1,2],[2,3],[3,1],[2,3]], colConditions = [[2,1]]
输出：[]
解释：由前两个条件可以得到 3 在 1 的下面，但第三个条件是 3 在 1 的上面。
没有符合条件的矩阵存在，所以我们返回空矩阵。

提示：
  2 <= k <= 400
  1 <= rowConditions.length, colConditions.length <= 10^4
  rowConditions[i].length == colConditions[i].length == 2
  1 <= abovei, belowi, lefti, righti <= k
  abovei != belowi
  lefti != righti
*/

bool topo(int k, vector<vector<int>> const& condition,
	vector<int>& order)
{
	vector<int> ind(k + 1);
	vector<vector<int>> after(k + 1);
	order.resize(k + 1);
	for (auto& c : condition) {
		after[c[0]].push_back(c[1]);
		++ind[c[1]];
	}
	int step = 0;
	vector<int> Q;
	for (int i = 1; i <= k; ++i)
		if (ind[i] == 0) {
			Q.push_back(i);
			order[i] = step++;
		}
	for (size_t i = 0; i < Q.size(); ++i) {
		vector<int> const& T = after[Q[i]];
		for (int t : T)
			if (--ind[t] == 0) {
				Q.push_back(t);
				order[t] = step++;
			}
	}
	return step == k;
}

vector<vector<int>> buildMatrix(int k,
	vector<vector<int>> const& rowConditions,
	vector<vector<int>> const& colConditions)
{
	vector<vector<int>> dst;
	vector<int> row, col;
	if (!topo(k, rowConditions, row))
		return dst;
	if (!topo(k, colConditions, col))
		return dst;
	dst.resize(k);
	for (int i = 0; i < k; ++i)
		dst[i].resize(k);
	for (int i = 1; i <= k; ++i)
		dst[row[i]][col[i]] = i;
	return dst;
}

int main()
{
	vector<vector<int>>
		r1 = {{1, 2}, {3, 2}},
		c1 = {{2, 1}, {3, 2}},
		r2 = {{1, 2}, {2, 3}, {3, 1}, {2, 3}},
		c2 = {{2, 1}};
	ToOut(buildMatrix(3, r1, c1));
	ToOut(buildMatrix(3, r2, c2));
}
