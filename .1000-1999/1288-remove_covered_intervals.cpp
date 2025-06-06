﻿#include "leetcode.hpp"

/* 1288. 删除被覆盖区间

给你一个区间列表，请你删除列表中被其他区间所覆盖的区间。

只有当 c <= a 且 b <= d 时，我们才认为区间 [a,b) 被区间 [c,d) 覆盖。

在完成所有删除操作后，请你返回列表中剩余区间的数目。

示例：
输入：intervals = [[1,4],[3,6],[2,8]]
输出：2
解释：区间 [3,6] 被区间 [2,8] 覆盖，所以它被删除了。

提示：​​​​​​
  1 <= intervals.length <= 1000
  0 <= intervals[i][0] < intervals[i][1] <= 10^5
  对于所有的 i != j：intervals[i] != intervals[j]
*/

struct Comp {
	bool operator()(vector<int> const& a, vector<int> const& b) const
	{
		return (a[0] < b[0])
			|| ((a[0] == b[0]) && (a[1] > b[1]));
	}
};

int removeCoveredIntervals1(vector<vector<int>>& range)
{
	int sum = 1;
	int len = static_cast<int>(range.size());
	sort(range.begin(), range.end(), Comp());
	for (int h = 0, i = 1; i < len; ++i) {
		if ((range[h][0] <= range[i][0]) && (range[i][1] <= range[h][1]))
			;
		else {
			h = i;
			++sum;
		}
	}
	return sum;
}

// https://leetcode.com/problems/remove-covered-intervals/discuss/451277/JavaC%2B%2BPython-Sort-Solution-Test-Cases-are-Trash
// 抄的
int removeCoveredIntervals(vector<vector<int>>& range)
{
	int sum = 0, left = -1, right = -1;
	int len = static_cast<int>(range.size());
	sort(range.begin(), range.end(), Comp());
	for (int i = 0; i < len; ++i) {
		if (range[i][0] > left && range[i][1] > right) {
			left = range[i][0];
			++sum;
		}
		// [2, 3] → [2, 8]
		right = max(right, range[i][1]);
	}
	return sum;
}

int main()
{
}
