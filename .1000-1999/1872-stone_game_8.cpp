﻿#include "leetcode.hpp"

/* 1872. 石子游戏 VIII

Alice 和 Bob 玩一个游戏，两人轮流操作， Alice 先手 。

总共有 n 个石子排成一行。轮到某个玩家的回合时，如果石子的数目 大于 1 ，他将执行以下操作：

  选择一个整数 x > 1 ，并且 移除 最左边的 x 个石子。
  将 移除 的石子价值之 和 累加到该玩家的分数中。
  将一个 新的石子 放在最左边，且新石子的值为被移除石子值之和。

当只剩下 一个 石子时，游戏结束。

Alice 和 Bob 的 分数之差 为 (Alice 的分数 - Bob 的分数) 。
Alice 的目标是 最大化 分数差，Bob 的目标是 最小化 分数差。

给你一个长度为 n 的整数数组 stones ，其中 stones[i] 是 从左边起 第 i 个石子的价值。
请你返回在双方都采用 最优 策略的情况下，Alice 和 Bob 的 分数之差 。

示例 1：
输入：stones = [-1,2,-3,4,-5]
输出：5
解释：
- Alice 移除最左边的 4 个石子，得分增加 (-1) + 2 + (-3) + 4 = 2 ，并且将一个价值为 2 的石子放在最左边。stones = [2,-5] 。
- Bob 移除最左边的 2 个石子，得分增加 2 + (-5) = -3 ，并且将一个价值为 -3 的石子放在最左边。stones = [-3] 。
两者分数之差为 2 - (-3) = 5 。

示例 2：
输入：stones = [7,-6,5,10,5,-2,-6]
输出：13
解释：
- Alice 移除所有石子，得分增加 7 + (-6) + 5 + 10 + 5 + (-2) + (-6) = 13 ，并且将一个价值为 13 的石子放在最左边。stones = [13] 。
两者分数之差为 13 - 0 = 13 。

示例 3：
输入：stones = [-10,-12]
输出：-22
解释：
- Alice 只有一种操作，就是移除所有石子。得分增加 (-10) + (-12) = -22 ，并且将一个价值为 -22 的石子放在最左边。stones = [-22] 。
两者分数之差为 (-22) - 0 = -22 。

提示：
  n == stones.length
  2 <= n <= 10^5
  -10^4 <= stones[i] <= 10^4
*/

// https://leetcode-cn.com/problems/stone-game-viii/solution/shi-zi-you-xi-viii-by-leetcode-solution-e8dx/
// 抄的
int stoneGameVIII(vector<int>& A)
{
	int len = static_cast<int>(A.size());
	for (int i = 1; i < len; ++i)
		A[i] += A[i - 1];
	for (int i = len - 2; i > 0; --i)
		A[i] = max(A[i + 1], A[i] - A[i + 1]);
	return A[1];
}

int main()
{
}
