﻿#include "leetcode.hpp"

/* 2554. 从一个范围内选择最多整数 I

给你一个整数数组 banned 和两个整数 n 和 maxSum 。你需要按照以下规则选择一些整数：

被选择整数的范围是 [1, n] 。
每个整数 至多 选择 一次 。
被选择整数不能在数组 banned 中。
被选择整数的和不超过 maxSum 。
请你返回按照上述规则 最多 可以选择的整数数目。

示例 1：
输入：banned = [1,6,5], n = 5, maxSum = 6
输出：2
解释：你可以选择整数 2 和 4 。
2 和 4 在范围 [1, 5] 内，且它们都不在 banned 中，它们的和是 6 ，没有超过 maxSum 。

示例 2：
输入：banned = [1,2,3,4,5,6,7], n = 8, maxSum = 1
输出：0
解释：按照上述规则无法选择任何整数。

示例 3：
输入：banned = [11], n = 7, maxSum = 50
输出：7
解释：你可以选择整数 1, 2, 3, 4, 5, 6 和 7 。
它们都在范围 [1, 7] 中，且都没出现在 banned 中，它们的和是 28 ，没有超过 maxSum 。

提示：
  1 <= banned.length <= 10^4
  1 <= banned[i], n <= 10^4
  1 <= maxSum <= 10^9
*/

int maxCount(vector<int> banned, int n, int maxSum)
{
	std::sort(banned.begin(), banned.end());
	int count = 0;
	int total = static_cast<int>(banned.size());
	for (int i = 1, k = 0; i <= n; ++i) {
		while (k < total && banned[k] < i) ++k;
		if (k < total && banned[k] == i) continue;
		maxSum -= i;
		if (maxSum < 0) break;
		count += 1;
	}
	return count;
}

int main()
{
	ToOut(maxCount({1, 6, 5}, 5, 6));
	ToOut(maxCount({1, 2, 3, 4, 5, 6, 7}, 8, 1));
	ToOut(maxCount({11}, 7, 50));
}
