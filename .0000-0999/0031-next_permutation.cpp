﻿#include "leetcode.hpp"

/* 31. 下一个排列

实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

void nextPermutation(vector<int>& A)
{
	int len = static_cast<int>(A.size());
	if (len < 2)
		return;
	int p = len - 2, q, t;
	for (; p >= 0; --p) {
		if (A[p] < A[p + 1])
			break;
	}
	if (p >= 0) {
		for (q = len - 1; p < q; --q) {
			if (A[p] < A[q])
				break;
		}
		t = A[p];
		A[p] = A[q];
		A[q] = t;
	}
	++p;
	q = len - 1;
	for (; p < q; ++p, --q) {
		t = A[p];
		A[p] = A[q];
		A[q] = t;
	}
}

int main()
{
	vector<int> a = {1, 2, 3, 4};
	for (int i = 1 * 2 * 3 * 4; i > 0; --i) {
		ToOut(a);
		nextPermutation(a);
	}
}
