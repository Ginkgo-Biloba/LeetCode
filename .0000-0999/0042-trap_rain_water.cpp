﻿#include "leetcode.hpp"

/* 42. 接雨水

给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/rainwatertrap.png
https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png
上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
感谢 Marcos 贡献此图。

示例:
输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
*/

int trap_Org(vector<int>& A)
{
	int len = static_cast<int>(A.size());
	if (len < 3)
		return 0;
	int sum = 0;
	vector<int> S;
	for (int i = 0; i < len; ++i) {
		while (S.size() && A[S.back()] < A[i]) {
			int q = S.back();
			S.pop_back();
			if (S.size()) {
				int p = S.back();
				sum += (min(A[p], A[i]) - A[q]) * (i - S.back() - 1);
			}
		}
		S.push_back(i);
	}
	return sum;
}

int trap(vector<int>& A)
{
	int len = static_cast<int>(A.size());
	int sum = 0;
	int maxL = 0, maxR = 0, L = 0, R = len - 1;
	while (L <= R) {
		if (A[L] <= A[R]) {
			if (A[L] >= maxL)
				maxL = A[L];
			else
				sum += maxL - A[L];
			++L;
		} else {
			if (A[R] >= maxR)
				maxR = A[R];
			else
				sum += maxR - A[R];
			--R;
		}
	}
	return sum;
}

int main()
{
	vector<int> a = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	ToOut(trap(a));
}
