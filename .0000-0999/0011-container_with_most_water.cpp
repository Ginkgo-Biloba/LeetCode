﻿#include "leetcode.hpp"

/* 11. 盛最多水的容器

给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/07/25/question_11.jpg
图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

示例：
输入：[1,8,6,2,5,4,8,3,7]
输出：49
*/

int maxArea(vector<int>& A)
{
	int len = static_cast<int>(A.size());
	int h = 0, i = len - 1, ans = 0, val;
	while (h < i) {
		val = min(A[h], A[i]) * (i - h);
		ans = max(ans, val);
		if (A[h] < A[i])
			++h;
		else
			--i;
	}
	return ans;
}

int main()
{
	vector<int> a = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	ToOut(maxArea(a));
}
