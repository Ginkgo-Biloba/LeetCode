﻿#include "leetcode.hpp"

/* 805. 数组的均值分割

给定的整数数组 A ，我们要将 A数组 中的每个元素移动到 B数组 或者 C数组中。
B数组和C数组在开始的时候都为空。
返回true ，当且仅当在我们的完成这样的移动后，可使得B数组的平均值和C数组的平均值相等，并且B数组和C数组都不为空。

示例:
输入:
[1,2,3,4,5,6,7,8]
输出: true
解释: 我们可以将数组分割为 [1,4,5,8] 和 [2,3,6,7], 他们的平均值都是4.5。

注意:
  A 数组的长度范围为 [1, 30].
  A[i] 的数据范围为 [0, 10000].
*/

class Solution {
	vector<int> A;
	int n;

	// 注意到两个子数组的平均数是相等的，假定数量少的那个均值是 m，数量为 k
	// 则问题转化为，从 n 个数里面挑 k 个数，和是整数 m*k
	bool ksum(int i, int k, int s)
	{
		if (k == 0)
			return s == 0;
		if ((s < k * A[n - 1]) || (s > k * A[i]))
			return false;
		for (; i <= n - k; ++i) {
			if (A[i] <= s && ksum(i + 1, k - 1, s - A[i]))
				return true;
		}
		return false;
	}

public:
	bool splitArraySameAverage(vector<int>& ary)
	{
		int sum = 0;
		A.swap(ary);
		n = static_cast<int>(A.size());
		for (int i = 0; i < n; ++i)
			sum += A[i];
		sort(A.begin(), A.end(), std::greater<int>());

		for (int i = 1; i <= n / 2; ++i)
			if ((sum * i % n) == 0) {
				if (ksum(0, i, sum * i / n))
					return true;
			}

		return false;
	}
};

int main()
{
	vector<int>
		A0 = {1, 2, 3, 4, 5, 6, 7, 8},
		A1 = {18, 0, 16, 2},
		A2 = {4, 4, 4, 4, 4, 4, 5, 4, 4, 4, 4, 4, 4, 5};
	Solution s;
	ToOut(s.splitArraySameAverage(A0));
	ToOut(s.splitArraySameAverage(A1));
	ToOut(s.splitArraySameAverage(A2));
}
