﻿#include "leetcode.hpp"

/* 1802. 有界数组中指定下标处的最大值

给你三个正整数 n、index 和 maxSum 。你需要构造一个同时满足下述所有条件的数组 nums（下标 从 0 开始 计数）：

  nums.length == n
  nums[i] 是 正整数 ，其中 0 <= i < n
  abs(nums[i] - nums[i+1]) <= 1 ，其中 0 <= i < n-1
  nums 中所有元素之和不超过 maxSum
  nums[index] 的值被 最大化

返回你所构造的数组中的 nums[index] 。

注意：abs(x) 等于 x 的前提是 x >= 0 ；否则，abs(x) 等于 -x 。

示例 1：
输入：n = 4, index = 2,  maxSum = 6
输出：2
解释：数组 [1,1,2,1] 和 [1,2,2,1] 满足所有条件。不存在其他在指定下标处具有更大值的有效数组。

示例 2：
输入：n = 6, index = 1,  maxSum = 10
输出：3

提示：
  1 <= n <= maxSum <= 10^9
  0 <= index < n
*/

int64_t cumulate(int n, int idx, int val)
{
	int64_t na = 1 + min(val, idx);
	int64_t nb = 1 + min(val, n - 1 - idx);
	int64_t sa = val * na - na * (na - 1) / 2;
	int64_t sb = val * nb - nb * (nb - 1) / 2;
	return sa + sb - val;
}

int maxValue(int n, int index, int maxSum)
{
	maxSum -= n;
	int lo = 0, hi = maxSum;
	while (lo < hi) {
		int mid = (lo + hi + 1) / 2;
		int64_t s = cumulate(n, index, mid);
		if (s > maxSum)
			hi = mid - 1;
		else
			lo = mid;
	}
	return lo + 1;
}

int main()
{
	ToOut(maxValue(4, 0, 4));
	ToOut(maxValue(3, 2, 18));
	ToOut(maxValue(4, 2, 6));
	ToOut(maxValue(6, 1, 10));
}
