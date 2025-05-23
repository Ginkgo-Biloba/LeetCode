﻿#include "leetcode.hpp"

/* 1039. 多边形三角剖分的最低得分

给定 N，想象一个凸 N 边多边形，其顶点按顺时针顺序依次标记为 A[0], A[i], ..., A[N-1]。

假设您将多边形剖分为 N-2 个三角形。
对于每个三角形，该三角形的值是顶点标记的乘积。
三角剖分的分数是进行三角剖分后所有 N-2 个三角形的值之和。

返回多边形进行三角剖分后可以得到的最低分。

示例 1：
输入：[1,2,3]
输出：6
解释：多边形已经三角化，唯一三角形的分数为 6。

示例 2：
输入：[3,7,4,5]
输出：144
解释：有两种三角剖分，可能得分分别为：3*7*5 + 4*5*7 = 245，或 3*4*5 + 3*4*7 = 144。最低分数为 144。
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/05/03/minimum-score-triangulation-of-polygon-1.png

示例 3：
输入：[1,3,1,4,1,5]
输出：13
解释：最低分数三角剖分的得分情况为 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13。

提示：
  3 <= A.length <= 50
  1 <= A[i] <= 100
*/

// https://leetcode.com/problems/minimum-score-triangulation-of-polygon/discuss/286754/C%2B%2BPython-O(n3)-DP-explanation-%2B-diagrams
// 抄的
int minScoreTriangulation(vector<int>& A)
{
	int len = static_cast<int>(A.size());
	vector<int> buf(len * len);
	auto dp = [&buf, len](int L, int R)
		-> int& { return buf[L * len + R]; };
	for (int d = 2; d < len; ++d)
		for (int L = 0; L < len - d; ++L) {
			int R = L + d;
			int val = INT_MAX;
			for (int M = L + 1; M < R; ++M)
				val = min(val, A[L] * A[M] * A[R] + dp(L, M) + dp(M, R));
			dp(L, R) = val;
		}
	return dp(0, len - 1);
}

int main()
{
	vector<int>
		a = {1, 2, 3},
		b = {3, 7, 4, 5},
		c = {1, 3, 1, 4, 1, 5};
	ToOut(minScoreTriangulation(a));
	ToOut(minScoreTriangulation(b));
	ToOut(minScoreTriangulation(c));
}
