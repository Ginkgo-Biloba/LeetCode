﻿#include "leetcode.hpp"

/* 1184. 公交站间的距离

环形公交路线上有 n 个站，按次序从 0 到 n - 1 进行编号。我们已知每一对相邻公交站之间的距离，distance[i] 表示编号为 i 的车站和编号为 (i + 1) % n 的车站之间的距离。

环线上的公交车都可以按顺时针和逆时针的方向行驶。

返回乘客从出发点 start 到目的地 destination 之间的最短距离。

示例 1：
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/09/08/untitled-diagram-1.jpg
输入：distance = [1,2,3,4], start = 0, destination = 1
输出：1
解释：公交站 0 和 1 之间的距离是 1 或 9，最小值是 1。

示例 2：
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/09/08/untitled-diagram-1-1.jpg
输入：distance = [1,2,3,4], start = 0, destination = 2
输出：3
解释：公交站 0 和 2 之间的距离是 3 或 7，最小值是 3。


示例 3：
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/09/08/untitled-diagram-1-2.jpg
输入：distance = [1,2,3,4], start = 0, destination = 3
输出：4
解释：公交站 0 和 3 之间的距离是 6 或 4，最小值是 4。

提示：
  1 <= n <= 10^4
  distance.length == n
  0 <= start, destination < n
  0 <= distance[i] <= 10^4
*/

int distanceBetweenBusStops(vector<int>& dist, int start, int des)
{
	int len = static_cast<int>(dist.size());
	int s0 = 0, s1 = 0;
	if (start > des)
		std::swap(start, des);
	for (int i = 0; i < start; ++i)
		s0 += dist[i];
	for (int i = start; i < des; ++i)
		s1 += dist[i];
	for (int i = des; i < len; ++i)
		s0 += dist[i];
	return min(s0, s1);
}

int main()
{
	vector<int> a = {7, 10, 1, 12, 11, 14, 5, 0};
	ToOut(distanceBetweenBusStops(a, 7, 2));
}
