#include "leetcode.hpp"

/* 2446. 判断两个事件是否存在冲突

给你两个字符串数组 event1 和 event2 ，表示发生在同一天的两个闭区间时间段事件，其中：

event1 = [startTime1, endTime1] 且
event2 = [startTime2, endTime2]
事件的时间为有效的 24 小时制且按 HH:MM 格式给出。

当两个事件存在某个非空的交集时（即，某些时刻是两个事件都包含的），则认为出现 冲突 。

如果两个事件之间存在冲突，返回 true ；否则，返回 false 。

示例 1：
输入：event1 = ["01:15","02:00"], event2 = ["02:00","03:00"]
输出：true
解释：两个事件在 2:00 出现交集。

示例 2：
输入：event1 = ["01:00","02:00"], event2 = ["01:20","03:00"]
输出：true
解释：两个事件的交集从 01:20 开始，到 02:00 结束。

示例 3：
输入：event1 = ["10:00","11:00"], event2 = ["14:00","15:00"]
输出：false
解释：两个事件不存在交集。

提示：
  event1.length == event2.length == 2
  event1[i].length == event2[i].length == 5
  startTime1 <= endTime1
  startTime2 <= endTime2
  所有事件的时间都按照 HH:MM 格式给出
*/

int tominute(string const& s)
{
	int h = (s[0] - '0') * 10 + s[1] - '0';
	int m = (s[3] - '0') * 10 + s[4] - '0';
	return h * 60 + m;
}

bool haveConflict(
	vector<string> const& e1, vector<string> const& e2)
{
	int a1 = tominute(e1[0]), a2 = tominute(e1[1]);
	int b1 = tominute(e2[0]), b2 = tominute(e2[1]);
	return max(a1, b1) <= min(a2, b2);
}

int main()
{
	ToOut(haveConflict({"01:15", "02:00"}, {"02:00", "03:00"}));
	ToOut(haveConflict({"01:00", "02:00"}, {"01:20", "03:00"}));
	ToOut(haveConflict({"10:00", "11:00"}, {"14:00", "15:00"}));
}
