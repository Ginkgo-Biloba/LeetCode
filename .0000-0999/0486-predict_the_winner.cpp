﻿#include "leetcode.hpp"

/* 486. 预测赢家

给定一个表示分数的非负整数数组。 玩家1从数组任意一端拿取一个分数，随后玩家2继续从剩余数组任意一端拿取分数，然后玩家1拿，……。每次一个玩家只能拿取一个分数，分数被拿取之后不再可取。直到没有剩余分数可取时游戏结束。最终获得分数总和最多的玩家获胜。

给定一个表示分数的数组，预测玩家1是否会成为赢家。你可以假设每个玩家的玩法都会使他的分数最大化。

示例 1:
输入: [1, 5, 2]
输出: False
解释: 一开始，玩家1可以从1和2中进行选择。
如果他选择2（或者1），那么玩家2可以从1（或者2）和5中进行选择。如果玩家2选择了5，那么玩家1则只剩下1（或者2）可选。
所以，玩家1的最终分数为 1 + 2 = 3，而玩家2为 5。
因此，玩家1永远不会成为赢家，返回 False。

示例 2:
输入: [1, 5, 233, 7]
输出: True
解释: 玩家1一开始选择1。然后玩家2必须从5和7中进行选择。无论玩家2选择了哪个，玩家1都可以选择233。
最终，玩家1（234分）比玩家2（12分）获得更多的分数，所以返回 True，表示玩家1可以成为赢家。

注意:
    1 <= 给定的数组长度 <= 20.
    数组里所有分数都为非负数且不会大于10000000。
    如果最终两个玩家的分数相等，那么玩家1仍为赢家。
*/

// https://leetcode.com/problems/predict-the-winner/discuss/96828/JAVA-9-lines-DP-solution-easy-to-understand-with-improvement-to-O(N)-space-complexity.
// 抄的
bool PredictTheWinner(vector<int> const& nums)
{
	int len = static_cast<int>(nums.size());
	if (len % 2 == 0)
		return true;
	vector<int> dp(len);

	for (int i = len - 1; i >= 0; --i) {
		dp[i] = nums[i];
		for (int k = i + 1; k < len; ++k)
			dp[k] = std::max(nums[i] - dp[k],
				nums[k] - dp[k - 1]);
	}

	return dp[len - 1] >= 0;
}

int main()
{
	ToOut(PredictTheWinner({1, 5, 233, 7}));
}
