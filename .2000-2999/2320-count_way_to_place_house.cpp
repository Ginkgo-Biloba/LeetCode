﻿#include "leetcode.hpp"

/* 320. 统计放置房子的方式数

一条街道上共有 n * 2 个 地块 ，街道的两侧各有 n 个地块。
每一边的地块都按从 1 到 n 编号。每个地块上都可以放置一所房子。

现要求街道同一侧不能存在两所房子相邻的情况，请你计算并返回放置房屋的方式数目。
由于答案可能很大，需要对 10^9 + 7 取余后再返回。

注意，如果一所房子放置在这条街某一侧上的第 i 个地块，不影响在另一侧的第 i 个地块放置房子。

示例 1：
输入：n = 1
输出：4
解释：
可能的放置方式：
1. 所有地块都不放置房子。
2. 一所房子放在街道的某一侧。
3. 一所房子放在街道的另一侧。
4. 放置两所房子，街道两侧各放置一所。

示例 2：
https://assets.leetcode.com/uploads/2022/05/12/arrangements.png
输入：n = 2
输出：9
解释：如上图所示，共有 9 种可能的放置方式。

提示：
  1 <= n <= 10^4
*/

int countHousePlacements(int n)
{
	int64_t const mod = static_cast<int64_t>(1e9 + 7);
	int64_t a = 1, b = 1;
	for (int i = 0; i < n; ++i) {
		int64_t t = (a + b) % mod;
		a = b;
		b = t;
	}
	return static_cast<int>(b * b % mod);
}

int main()
{
	ToOut(countHousePlacements(1));
	ToOut(countHousePlacements(2));
}
