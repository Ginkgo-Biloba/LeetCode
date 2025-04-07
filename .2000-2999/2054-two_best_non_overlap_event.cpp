﻿#include "leetcode.hpp"

/* 2054. 两个最好的不重叠活动


给你一个下标从 0 开始的二维整数数组 events ，其中 events[i] = [startTimei, endTimei, valuei] 。
第 i 个活动开始于 startTimei ，结束于 endTimei ，如果你参加这个活动，那么你可以得到价值 valuei 。
你 最多 可以参加 两个时间不重叠 活动，使得它们的价值之和 最大 。

请你返回价值之和的 最大值 。

注意，活动的开始时间和结束时间是 包括 在活动时间内的，也就是说，你不能参加两个活动且它们之一的开始时间等于另一个活动的结束时间。
更具体的，如果你参加一个活动，且结束时间为 t ，那么下一个活动必须在 t + 1 或之后的时间开始。

示例 1:
https://assets.leetcode.com/uploads/2021/09/21/picture5.png
输入：events = [[1,3,2],[4,5,2],[2,4,3]]
输出：4
解释：选择绿色的活动 0 和 1 ，价值之和为 2 + 2 = 4 。

示例 2：
https://assets.leetcode.com/uploads/2021/09/21/picture1.png

输入：events = [[1,3,2],[4,5,2],[1,5,5]]
输出：5
解释：选择活动 2 ，价值和为 5 。

示例 3：
https://assets.leetcode.com/uploads/2021/09/21/picture3.png
输入：events = [[1,5,3],[1,5,1],[6,6,5]]
输出：8
解释：选择活动 0 和 2 ，价值之和为 3 + 5 = 8 。

提示：
  2 <= events.length <= 10^5
  events[i].length == 3
  1 <= startTimei <= endTimei <= 10^9
  1 <= valuei <= 10^6
*/

int maxTwoEvents(vector<vector<int>>& E)
{
	int ret = 0, pre = 0;
	sort(E.begin(), E.end(),
		[](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });
	priority_queue<pair<int, int>> Q;
	for (auto& e : E) {
		for (; !Q.empty() && -(Q.top().first) < e[0]; Q.pop())
			pre = max(pre, Q.top().second);
		ret = max(ret, pre + e[2]);
		Q.push({-e[1], e[2]});
	}
	return ret;
}

int main() { }
