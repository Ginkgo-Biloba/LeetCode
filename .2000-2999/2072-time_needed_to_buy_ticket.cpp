﻿#include "leetcode.hpp"

/* 2073. 买票需要的时间

有 n 个人前来排队买票，其中第 0 人站在队伍 最前方 ，第 (n - 1) 人站在队伍 最后方 。

给你一个下标从 0 开始的整数数组 tickets ，数组长度为 n ，其中第 i 人想要购买的票数为 tickets[i] 。

每个人买票都需要用掉 恰好 1 秒 。
一个人 一次只能买一张票 ，如果需要购买更多票，他必须走到  队尾 重新排队（瞬间 发生，不计时间）。
如果一个人没有剩下需要买的票，那他将会 离开 队伍。

返回位于位置 k（下标从 0 开始）的人完成买票需要的时间（以秒为单位）。

示例 1：
输入：tickets = [2,3,2], k = 2
输出：6
解释：
- 第一轮，队伍中的每个人都买到一张票，队伍变为 [1, 2, 1] 。
- 第二轮，队伍中的每个都又都买到一张票，队伍变为 [0, 1, 0] 。
位置 2 的人成功买到 2 张票，用掉 3 + 3 = 6 秒。

示例 2：
输入：tickets = [5,1,1,1], k = 0
输出：8
解释：
- 第一轮，队伍中的每个人都买到一张票，队伍变为 [4, 0, 0, 0] 。
- 接下来的 4 轮，只有位置 0 的人在买票。
位置 0 的人成功买到 5 张票，用掉 4 + 1 + 1 + 1 + 1 = 8 秒。

提示：
  n == tickets.length
  1 <= n <= 100
  1 <= tickets[i] <= 100
  0 <= k < n
*/

int timeRequiredToBuy(vector<int>& tickets, int k)
{
	int n = static_cast<int>(tickets.size());
	int sum = 0, val = tickets[k];
	for (int i = 0; i <= k; ++i)
		sum += min(val, tickets[i]);
	for (int i = k + 1; i < n; ++i)
		sum += min(val - 1, tickets[i]);
	return sum;
}

int main() { }
