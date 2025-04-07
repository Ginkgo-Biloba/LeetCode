﻿#include "leetcode.hpp"

/* 1015. 可被 K 整除的最小整数

给定正整数 K，你需要找出可以被 K 整除的、仅包含数字 1 的最小正整数 N。

返回 N 的长度。如果不存在这样的 N，就返回 -1。

示例 1：
输入：1
输出：1
解释：最小的答案是 N = 1，其长度为 1。

示例 2：
输入：2
输出：-1
解释：不存在可被 2 整除的正整数 N 。

示例 3：
输入：3
输出：3
解释：最小的答案是 N = 111，其长度为 3。

提示：
  1 <= K <= 10^5
*/

// https://leetcode-cn.com/problems/smallest-integer-divisible-by-k/solution/javajie-fa-yi-ji-zheng-ming-de-si-lu-by-jiangzk/
// https://leetcode.com/problems/smallest-integer-divisible-by-k/discuss/260875/Python-O(K)-with-Detailed-Explanations
// 抄的
int smallestRepunitDivByK(int K)
{
	if ((K % 2 == 0) || (K % 5 == 0))
		return -1;

	int m = 0;
	for (int i = 1; i <= K; ++i) {
		m = (10 * m + 1) % K;
		if (m == 0)
			return i;
	}
	return -1;
}

int main()
{
	ToOut(smallestRepunitDivByK(1));
	ToOut(smallestRepunitDivByK(2));
	ToOut(smallestRepunitDivByK(3));
	ToOut(smallestRepunitDivByK(77));
}
