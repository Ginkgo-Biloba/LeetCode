﻿#include "leetcode.hpp"

/* 630. 课程表 III

这里有 n 门不同的在线课程，他们按从 1 到 n 编号。
每一门课程有一定的持续上课时间（课程时间）t 以及关闭时间第 d 天。
一门课要持续学习 t 天直到第 d 天时要完成，你将会从第 1 天开始。

给出 n 个在线课程用 (t, d) 对表示。你的任务是找出最多可以修几门课。

示例：
输入: [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
输出: 3
解释:
这里一共有 4 门课程, 但是你最多可以修 3 门:
首先, 修第一门课时, 它要耗费 100 天，你会在第 100 天完成, 在第 101 天准备下门课。
第二, 修第三门课时, 它会耗费 1000 天，所以你将在第 1100 天的时候完成它, 以及在第 1101 天开始准备下门课程。
第三, 修第二门课时, 它会耗时 200 天，所以你将会在第 1300 天时完成它。
第四门课现在不能修，因为你将会在第 3300 天完成它，这已经超出了关闭日期。

提示:
  整数 1 <= d, t, n <= 10,000 。
  你不能同时修两门课程。
*/

// https://leetcode.com/problems/course-schedule-iii/discuss/104844/C++-Short-and-Elegant-O(nlogn)-Time-O(k)-Space-Solution/164603
// 抄的
typedef vector<int> range;
int scheduleCourse(vector<range>& courses)
{
	sort(courses.begin(), courses.end(),
		[](range const& x, range const& y) -> bool {
			return x[1] < y[1];
		});
	std::priority_queue<int> q;
	int cur = 0;
	for (range const& r : courses) {
		q.push(r[0]);
		cur += r[0];
		if (cur > r[1]) {
			cur -= q.top();
			q.pop();
		}
	}
	cur = static_cast<int>(q.size());
	return cur;
}

int main()
{
	vector<range> courses = {
		{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
	ToOut(scheduleCourse(courses));
}
