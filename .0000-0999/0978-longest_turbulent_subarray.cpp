﻿#include "leetcode.hpp"

/* 978. 最长湍流子数组

当 A 的子数组 A[i], A[i+1], ..., A[j] 满足下列条件时，我们称其为湍流子数组：
  若 i <= k < j，当 k 为奇数时， A[k] > A[k+1]，且当 k 为偶数时，A[k] < A[k+1]；
  或 若 i <= k < j，当 k 为偶数时，A[k] > A[k+1] ，且当 k 为奇数时， A[k] < A[k+1]。

也就是说，如果比较符号在子数组中的每个相邻元素对之间翻转，则该子数组是湍流子数组。

返回 A 的最大湍流子数组的长度。

示例 1：
输入：[9,4,2,10,7,8,8,1,9]
输出：5
解释：(A[1] > A[2] < A[3] > A[4] < A[5])

示例 2：
输入：[4,8,12,16]
输出：2

示例 3：
输入：[100]
输出：1

提示：
  1 <= A.length <= 40000
  0 <= A[i] <= 10^9
*/

int maxTurbulenceSize(vector<int>& A)
{
	int n = static_cast<int>(A.size());
	int s = 0;
	for (int k = 0; k < n - 1; ++k) {
		if (A[k] == A[k + 1])
			A[k] = 0;
		else if (k & 1)
			A[k] = (A[k] < A[k + 1]) ? 1 : -1;
		else
			A[k] = (A[k] > A[k + 1]) ? 1 : -1;
	}

	// 统计 A 中连续的 ±1 的数量
	A.pop_back();
	n -= 1;
	for (int i = 0; i < n;) {
		if (A[i] == 0)
			++i;
		else {
			int k = i + 1;
			while ((k < n) && (A[i] == A[k]))
				++k;
			s = max(s, k - i);
			i = k;
		}
	}

	return s + 1;
}

int main()
{
	vector<int>
		a = {9, 4, 2, 10, 7, 8, 8, 1, 9},
		b = {4, 8, 12, 16},
		c = {100};
	ToOut(maxTurbulenceSize(a));
	ToOut(maxTurbulenceSize(b));
	ToOut(maxTurbulenceSize(c));
}
