﻿#include "leetcode.hpp"

/* 2318. 不同骰子序列的数目

给你一个整数 n 。
你需要掷一个 6 面的骰子 n 次。请你在满足以下要求的前提下，求出 不同 骰子序列的数目：

  序列中任意 相邻 数字的 最大公约数 为 1 。
  序列中 相等 的值之间，至少有 2 个其他值的数字。
  正式地，如果第 i 次掷骰子的值 等于 第 j 次的值，那么 abs(i - j) > 2 。

请你返回不同序列的 总数目 。由于答案可能很大，请你将答案对 10^9 + 7 取余 后返回。

如果两个序列中至少有一个元素不同，那么它们被视为不同的序列。

示例 1：
输入：n = 4
输出：184
解释：一些可行的序列为 (1, 2, 3, 4) ，(6, 1, 2, 3) ，(1, 2, 3, 1) 等等。
一些不可行的序列为 (1, 2, 1, 3) ，(1, 2, 3, 6) 。
(1, 2, 1, 3) 是不可行的，因为第一个和第三个骰子值相等且 abs(1 - 3) = 2 （下标从 1 开始表示）。
(1, 2, 3, 6) i是不可行的，因为 3 和 6 的最大公约数是 3 。
总共有 184 个不同的可行序列，所以我们返回 184 。

示例 2：
输入：n = 2
输出：22
解释：一些可行的序列为 (1, 2) ，(2, 1) ，(3, 2) 。
一些不可行的序列为 (3, 6) ，(2, 4) ，因为最大公约数不为 1 。
总共有 22 个不同的可行序列，所以我们返回 22 。

提示：
  1 <= n <= 10^4
*/

// https://leetcode.cn/problems/number-of-distinct-roll-sequences/solutions/1625297/by-endlesscheng-tgkn
// 抄的
int distinctSequences(int n)
{
	int const mod = static_cast<int>(1e9 + 7);
	int const seq[7][6] = {
		{},
		{5, 2, 3, 4, 5, 6},
		{3, 1, 3, 5},
		{4, 1, 2, 4, 5},
		{3, 1, 3, 5},
		{5, 1, 2, 3, 4, 6},
		{2, 1, 5}};

	if (n == 1) return 6;
	vector<array<int, 7>> dp(n + 1);
	for (int d = 1; d <= 6; ++d) {
		dp[1][d] = 1;
		dp[2][d] = seq[d][0];
	}
	for (int i = 3; i <= n; ++i)
		for (int d = 1; d <= 6; ++d) {
			int val = 0;
			for (int k = 1; k <= seq[d][0]; ++k)
				val = (val + dp[i - 1][seq[d][k]] - dp[i - 2][d]) % mod;
			if (i > 3)
				val = (val + dp[i - 2][d]) % mod;
			dp[i][d] = (val + mod) % mod;
		}
	int ans = 0;
	for (int d = 1; d <= 6; ++d)
		ans = (ans + dp[n][d]) % mod;
	return ans;
}

int main()
{
	ToOut(distinctSequences(4));
	ToOut(distinctSequences(2));
}
