﻿#include "leetcode.hpp"

/* 1072. 按列翻转得到最大值等行数

给定由若干 0 和 1 组成的矩阵 matrix，从中选出任意数量的列并翻转其上的 每个 单元格。
翻转后，单元格的值从 0 变成 1，或者从 1 变为 0 。

返回经过一些翻转后，行上所有值都相等的最大行数。

示例 1：
输入：[[0,1],[1,1]]
输出：1
解释：不进行翻转，有 1 行所有值都相等。

示例 2：
输入：[[0,1],[1,0]]
输出：2
解释：翻转第一列的值之后，这两行都由相等的值组成。

示例 3：
输入：[[0,0,0],[0,0,1],[1,1,0]]
输出：2
解释：翻转前两列的值之后，后两行由相等的值组成。

提示：
  1 <= matrix.length <= 300
  1 <= matrix[i].length <= 300
  所有 matrix[i].length 都相等
  matrix[i][j] 为 0 或 1
*/

// https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/discuss/303758/My-java-solution-with-hashmap
// 抄的
int maxEqualRowsAfterFlips(vector<vector<int>>& matrix)
{
	unordered_map<string, int> M;
	string s, t;
	s.resize(matrix[0].size());
	t.resize(s.size());
	for (auto const& row : matrix) {
		s.clear();
		t.clear();
		for (int i : row) {
			s.push_back(static_cast<char>(i));
			t.push_back(static_cast<char>(1 - i));
		}
		M[s] += 1;
		M[t] += 1;
	}
	int ans = 0;
	for (auto const& kv : M)
		ans = max(ans, kv.second);
	return ans;
}

int main()
{
	vector<vector<int>>
		a = {{0, 1}, {1, 1}},
		b = {{0, 1}, {1, 0}},
		c = {{0, 0, 0}, {0, 0, 1}, {1, 1, 0}};
	ToOut(maxEqualRowsAfterFlips(a));
	ToOut(maxEqualRowsAfterFlips(b));
	ToOut(maxEqualRowsAfterFlips(c));
}
