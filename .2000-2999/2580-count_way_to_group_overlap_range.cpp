#include "leetcode.hpp"

/* 2580. 统计将重叠区间合并成组的方案数

给你一个二维整数数组 ranges ，其中 ranges[i] = [starti, endi] 表示 starti 到 endi 之间（包括二者）的所有整数都包含在第 i 个区间中。

你需要将 ranges 分成 两个 组（可以为空），满足：

每个区间只属于一个组。
两个有 交集 的区间必须在 同一个 组内。
如果两个区间有至少 一个 公共整数，那么这两个区间是 有交集 的。

比方说，区间 [1, 3] 和 [2, 5] 有交集，因为 2 和 3 在两个区间中都被包含。
请你返回将 ranges 划分成两个组的 总方案数 。
由于答案可能很大，将它对 10^9 + 7 取余 后返回。

示例 1：
输入：ranges = [[6,10],[5,15]]
输出：2
解释：
两个区间有交集，所以它们必须在同一个组内。
所以有两种方案：
- 将两个区间都放在第 1 个组中。
- 将两个区间都放在第 2 个组中。

示例 2：
输入：ranges = [[1,3],[10,20],[2,5],[4,8]]
输出：4
解释：
区间 [1,3] 和 [2,5] 有交集，所以它们必须在同一个组中。
同理，区间 [2,5] 和 [4,8] 也有交集，所以它们也必须在同一个组中。
所以总共有 4 种分组方案：
- 所有区间都在第 1 组。
- 所有区间都在第 2 组。
- 区间 [1,3] ，[2,5] 和 [4,8] 在第 1 个组中，[10,20] 在第 2 个组中。
- 区间 [1,3] ，[2,5] 和 [4,8] 在第 2 个组中，[10,20] 在第 1 个组中。

提示：
  1 <= ranges.length <= 10^5
  ranges[i].length == 2
  0 <= starti <= endi <= 10^9
*/

int countWays(vector<vector<int>> const& ranges)
{
	int n = static_cast<int>(ranges.size());
	vector<pair<int, int>> A(n);
	for (int i = 0; i < n; ++i)
		A[i] = {ranges[i][0], ranges[i][1] + 1};
	A.push_back({INT_MAX - 1, INT_MAX});
	std::sort(A.begin(), A.end());
	int to = A[0].second, count = 0;
	for (int i = 0; i <= n; ++i) {
		if (A[i].first < to)
			to = max(to, A[i].second);
		else {
			A[count++].second = to;
			to = A[i].second;
		}
	}
	int64_t const modval = 1000000007;
	int64_t base = 2, ans = 1;
	for (int x = count; x > 0; x >>= 1) {
		if (x & 1)
			ans = ans * base % modval;
		base = base * base % modval;
	}
	return static_cast<int>(ans);
}

int main()
{
	ToOut(countWays({{6, 10}, {5, 15}}));
	ToOut(countWays({{1, 3}, {10, 20}, {2, 5}, {4, 8}}));
}
