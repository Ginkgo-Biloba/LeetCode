#include "leetcode.hpp"

/* 1847. 最近的房间

一个酒店里有 n 个房间，这些房间用二维整数数组 rooms 表示，其中 rooms[i] = [roomIdi, sizei] 表示有一个房间号为 roomIdi 的房间且它的面积为 sizei 。
每一个房间号 roomIdi 保证是 独一无二 的。

同时给你 k 个查询，用二维数组 queries 表示，其中 queries[j] = [preferredj, minSizej] 。
第 j 个查询的答案是满足如下条件的房间 id ：
  房间的面积 至少 为 minSizej ，且
  abs(id - preferredj) 的值 最小 ，其中 abs(x) 是 x 的绝对值。

如果差的绝对值有 相等 的，选择 最小 的 id 。
如果 没有满足条件的房间 ，答案为 -1 。

请你返回长度为 k 的数组 answer ，其中 answer[j] 为第 j 个查询的结果。

示例 1：
输入：rooms = [[2,2],[1,2],[3,2]], queries = [[3,1],[3,3],[5,2]]
输出：[3,-1,3]
解释：查询的答案如下：
查询 [3,1] ：房间 3 的面积为 2 ，大于等于 1 ，且号码是最接近 3 的，为 abs(3 - 3) = 0 ，所以答案为 3 。
查询 [3,3] ：没有房间的面积至少为 3 ，所以答案为 -1 。
查询 [5,2] ：房间 3 的面积为 2 ，大于等于 2 ，且号码是最接近 5 的，为 abs(3 - 5) = 2 ，所以答案为 3 。

示例 2：

输入：rooms = [[1,4],[2,3],[3,5],[4,1],[5,2]], queries = [[2,3],[2,4],[2,5]]
输出：[2,1,3]
解释：查询的答案如下：
查询 [2,3] ：房间 2 的面积为 3 ，大于等于 3 ，且号码是最接近的，为 abs(2 - 2) = 0 ，所以答案为 2 。
查询 [2,4] ：房间 1 和 3 的面积都至少为 4 ，答案为 1 因为它房间编号更小。
查询 [2,5] ：房间 3 是唯一面积大于等于 5 的，所以答案为 3 。

提示：
  n == rooms.length
  1 <= n <= 10^5
  k == queries.length
  1 <= k <= 10^4
  1 <= roomIdi, preferredj <= 10^7
  1 <= sizei, minSizej <= 10^7
*/

vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queris)
{
	int rlen = static_cast<int>(rooms.size());
	int qlen = static_cast<int>(queris.size());
	vector<array<int, 2>> R, S;
	for (int i = 0; i < rlen; ++i)
		R.push_back({rooms[i][0], rooms[i][1]});
	vector<array<int, 3>> Q;
	for (int i = 0; i < qlen; ++i)
		Q.push_back({queris[i][0], queris[i][1], i});

	vector<int> A(qlen, INT_MIN / 2);
	sort(R.begin(), R.end());
	sort(Q.begin(), Q.end());

	for (int ri = 0, qi = 0; qi < qlen; ++qi) {
		auto q = Q[qi];
		for (; ri < rlen && R[ri][0] <= q[0]; ++ri) {
			while (S.size() && S.back()[1] <= R[ri][1])
				S.pop_back();
			S.push_back(R[ri]);
		}
		if (S.empty())
			continue;
		auto it = upper_bound(
			S.begin(), S.end(), array<int, 2> {-1, q[1]},
			[](array<int, 2> const& x, array<int, 2> const& y) -> bool { return x[1] > y[1]; });
		if (it == S.begin())
			continue;
		auto r = *(--it);
		if (r[1] >= q[1] && abs(q[0] - r[0]) < abs(q[0] - A[q[2]]))
			A[q[2]] = r[0];
	}

	S.clear();
	for (int ri = rlen - 1, qi = qlen - 1; qi > -1; --qi) {
		auto q = Q[qi];
		for (; ri > -1 && R[ri][0] >= q[0]; --ri) {
			while (S.size() && S.back()[1] <= R[ri][1])
				S.pop_back();
			S.push_back(R[ri]);
		}
		if (S.empty())
			continue;
		auto it = upper_bound(
			S.begin(), S.end(), array<int, 2> {-1, q[1]},
			[](array<int, 2> const& x, array<int, 2> const& y) -> bool { return x[1] > y[1]; });
		if (it == S.begin())
			continue;
		auto r = *(--it);
		if (r[1] >= q[1] && abs(q[0] - r[0]) < abs(q[0] - A[q[2]]))
			A[q[2]] = r[0];
	}

	for (int i = 0; i < qlen; ++i)
		A[i] = max(A[i], -1);
	return A;
}

int main()
{
	vector<vector<int>>
		a = {{2, 2}, {1, 2}, {3, 2}},
		b = {{3, 1}, {3, 3}, {5, 2}},
		c = {{1, 4}, {2, 3}, {3, 5}, {4, 1}, {5, 2}},
		d = {{2, 3}, {2, 4}, {2, 5}};
	ToOut(closestRoom(a, b));
	ToOut(closestRoom(c, d));
}
