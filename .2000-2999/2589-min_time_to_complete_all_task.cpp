#include "leetcode.hpp"

/* 2589. 完成所有任务的最少时间

你有一台电脑，它可以 同时 运行无数个任务。
给你一个二维整数数组 tasks ，其中 tasks[i] = [starti, endi, durationi] 表示第 i 个任务需要在 闭区间 时间段 [starti, endi] 内运行 durationi 个整数时间点（但不需要连续）。

当电脑需要运行任务时，你可以打开电脑，如果空闲时，你可以将电脑关闭。

请你返回完成所有任务的情况下，电脑最少需要运行多少秒。

示例 1：
输入：tasks = [[2,3,1],[4,5,1],[1,5,2]]
输出：2
解释：
- 第一个任务在闭区间 [2, 2] 运行。
- 第二个任务在闭区间 [5, 5] 运行。
- 第三个任务在闭区间 [2, 2] 和 [5, 5] 运行。
电脑总共运行 2 个整数时间点。

示例 2：
输入：tasks = [[1,3,2],[2,5,3],[5,6,2]]
输出：4
解释：
- 第一个任务在闭区间 [2, 3] 运行
- 第二个任务在闭区间 [2, 3] 和 [5, 5] 运行。
- 第三个任务在闭区间 [5, 6] 运行。
电脑总共运行 4 个整数时间点。

提示：
  1 <= tasks.length <= 2000
  tasks[i].length == 3
  1 <= starti, endi <= 2000
  1 <= durationi <= endi - starti + 1
*/

// https://leetcode.cn/problems/minimum-time-to-complete-all-tasks/solutions/2773362/wan-cheng-suo-you-ren-wu-de-zui-shao-shi-nnbt/
// 抄的
int findMinimumTime(vector<vector<int>> const& tasks)
{
	struct Task {
		int start, end, duration;
	};
	int n = static_cast<int>(tasks.size());
	vector<Task> A(n);
	for (int i = 0; i < n; ++i)
		A[i] = Task {tasks[i][0], tasks[i][1], tasks[i][2]};
	std::sort(A.begin(), A.end(),
		[](Task const& a, Task const& b) { return a.end < b.end; });
	vector<Task> S = {Task {-1, -1, 0}};
	for (Task const& task : A) {
		int start = task.start, end = task.end, duration = task.duration;
		int k = static_cast<int>(
			std::lower_bound(S.begin(), S.end(), task,
				[](Task const& a, Task const& b) { return a.start < b.start; })
			- S.begin());
		duration -= S.back().duration - S[k - 1].duration;
		if (start <= S[k - 1].end)
			duration -= S[k - 1].end - start + 1;
		if (duration <= 0) continue;
		while (end - S.back().end <= duration) {
			duration += S.back().end - S.back().start + 1;
			S.pop_back();
		}
		S.push_back(Task {
			end - duration + 1, end, S.back().duration + duration});
	}
	return S.back().duration;
}

int main()
{
	ToOut(findMinimumTime({{2, 3, 1}, {4, 5, 1}, {1, 5, 2}}));
	ToOut(findMinimumTime({{1, 3, 2}, {2, 5, 3}, {5, 6, 2}}));
}
