﻿#include "leetcode.hpp"

/* 1529. 灯泡开关 IV

房间中有 n 个灯泡，编号从 0 到 n-1 ，自左向右排成一行。
最开始的时候，所有的灯泡都是 关 着的。

请你设法使得灯泡的开关状态和 target 描述的状态一致，其中 target[i] 等于 1 第 i 个灯泡是开着的，等于 0 意味着第 i 个灯是关着的。

有一个开关可以用于翻转灯泡的状态，翻转操作定义如下：
  选择当前配置下的任意一个灯泡（下标为 i ）
  翻转下标从 i 到 n-1 的每个灯泡

翻转时，如果灯泡的状态为 0 就变为 1，为 1 就变为 0 。

返回达成 target 描述的状态所需的 最少 翻转次数。

示例 1：
输入：target = "10111"
输出：3
解释：初始配置 "00000".
从第 3 个灯泡（下标为 2）开始翻转 "00000" -> "00111"
从第 1 个灯泡（下标为 0）开始翻转 "00111" -> "11000"
从第 2 个灯泡（下标为 1）开始翻转 "11000" -> "10111"
至少需要翻转 3 次才能达成 target 描述的状态

示例 2：
输入：target = "101"
输出：3
解释："000" -> "111" -> "100" -> "101".

示例 3：
输入：target = "00000"
输出：0

示例 4：
输入：target = "001011101"
输出：5

提示：
  1 <= target.length <= 10^5
  target[i] == '0' 或者 target[i] == '1'
*/

int minFlips(string target)
{
	int len = static_cast<int>(target.length());
	int ans = 0, cur = 0;
	for (int i = 0; i < len; ++i) {
		int v = target[i] - '0';
		if (v == cur)
			continue;
		++ans;
		cur = 1 - cur;
	}
	return ans;
}

int main()
{
	ToOut(minFlips("10111"));
	ToOut(minFlips("101"));
	ToOut(minFlips("00000"));
	ToOut(minFlips("001011101"));
}
