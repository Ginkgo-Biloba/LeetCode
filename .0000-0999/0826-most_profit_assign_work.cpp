﻿#include "leetcode.hpp"

/* 826. 安排工作以达到最大收益

有一些工作：difficulty[i] 表示第i个工作的难度，profit[i]表示第i个工作的收益。

现在我们有一些工人。worker[i]是第i个工人的能力，即该工人只能完成难度小于等于worker[i]的工作。
每一个工人都最多只能安排一个工作，但是一个工作可以完成多次。

举个例子，如果3个工人都尝试完成一份报酬为1的同样工作，那么总收益为 $3。
如果一个工人不能完成任何工作，他的收益为 $0 。

我们能得到的最大收益是多少？

示例：

输入: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
输出: 100
解释: 工人被分配的工作难度是 [4,4,6,6] ，分别获得 [20,20,30,30] 的收益。

提示:
  1 <= difficulty.length = profit.length <= 10000
  1 <= worker.length <= 10000
  difficulty[i], profit[i], worker[i]  的范围是 [1, 10^5]
*/

int maxProfitAssignment1(vector<int>& difficulty, vector<int>& profit, vector<int>& worker)
{
	int const Hard = static_cast<int>(1e5 + 1);
	int make[Hard] = {0};
	int len = static_cast<int>(profit.size());
	int sum = 0;

	for (int i = 0; i < len; ++i) {
		int d = difficulty[i];
		make[d] = std::max(make[d], profit[i]);
	}
	for (int i = 1; i < Hard; ++i)
		make[i] = std::max(make[i], make[i - 1]);

	len = static_cast<int>(worker.size());
	for (int i = 0; i < len; ++i)
		sum += make[worker[i]];

	return sum;
}

// 抄的
int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker)
{
	vector<pair<int, int>> dp;
	int len = static_cast<int>(profit.size());
	int k = 0, sum = 0, cur = 0;
	if (len == 0 || worker.empty())
		return sum;

	dp.reserve(len);
	for (int i = 0; i < len; ++i)
		dp.emplace_back(difficulty[i], profit[i]);

	sort(dp.begin(), dp.end());
	sort(worker.begin(), worker.end());

	for (int w : worker) {
		for (; (k < len) && (dp[k].first <= w); ++k)
			cur = std::max(cur, dp[k].second);
		sum += cur;
	}

	return sum;
}

int main()
{
	vector<int>
		d = {2, 4, 6, 8, 10},
		p = {10, 20, 30, 40, 50},
		w = {4, 5, 6, 7};
	ToOut(maxProfitAssignment(d, p, w));
}
