﻿#include "leetcode.hpp"

/* 1318. 或运算的最小翻转次数

给你三个正整数 a、b 和 c。

你可以对 a 和 b 的二进制表示进行位翻转操作，返回能够使按位或运算   a OR b == c 成立的最小翻转次数。

「位翻转操作」是指将一个数的二进制表示任何单个位上的 1 变成 0 或者 0 变成 1 。

示例 1：
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/01/11/sample_3_1676.png
输入：a = 2, b = 6, c = 5
输出：3
解释：翻转后 a = 1 , b = 4 , c = 5 使得 a OR b == c

示例 2：
输入：a = 4, b = 2, c = 7
输出：1

示例 3：
输入：a = 1, b = 2, c = 3
输出：0

提示：
  1 <= a <= 10^9
  1 <= b <= 10^9
  1 <= c <= 10^9
*/

int minFlips(int a, int b, int c)
{
	int n = 0;
	int mask = 1 << 30;
	for (; mask; mask >>= 1) {
		int x = mask & a;
		int y = mask & b;
		int z = mask & c;
		if ((x | y) == z)
			continue;
		else if (z == 0) {
			n += (x != 0);
			n += (y != 0);
		} else // z == **1**
			n += 1;
	}
	return n;
}

int main()
{
	ToOut(minFlips(2, 6, 5));
	ToOut(minFlips(4, 2, 7));
	ToOut(minFlips(1, 2, 3));
}
