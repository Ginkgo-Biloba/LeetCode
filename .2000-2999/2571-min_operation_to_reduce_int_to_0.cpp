﻿#include "leetcode.hpp"

/* 2571. 将整数减少到零需要的最少操作数

给你一个正整数 n ，你可以执行下述操作 任意 次：

  n 加上或减去 2 的某个 幂
  返回使 n 等于 0 需要执行的 最少 操作数。

如果 x == 2i 且其中 i >= 0 ，则数字 x 是 2 的幂。

示例 1：
输入：n = 39
输出：3
解释：我们可以执行下述操作：
- n 加上 20 = 1 ，得到 n = 40 。
- n 减去 23 = 8 ，得到 n = 32 。
- n 减去 25 = 32 ，得到 n = 0 。
可以证明使 n 等于 0 需要执行的最少操作数是 3 。

示例 2：
输入：n = 54
输出：3
解释：我们可以执行下述操作：
- n 加上 21 = 2 ，得到 n = 56 。
- n 加上 23 = 8 ，得到 n = 64 。
- n 减去 26 = 64 ，得到 n = 0 。
使 n 等于 0 需要执行的最少操作数是 3 。

提示：
  1 <= n <= 10^5
*/

int minOperations(int n)
{
	int ans = 1;
	// n 不是 2 的幂次
	while (n & (n - 1)) {
		int lb = n & -n;
		if (n & (lb << 1))
			n += lb; // 多个连续 1
		else
			n -= lb; // 单个 1
		++ans;
	}
	return ans;
}

int main()
{
	ToOut(minOperations(39));
	ToOut(minOperations(54));
}
