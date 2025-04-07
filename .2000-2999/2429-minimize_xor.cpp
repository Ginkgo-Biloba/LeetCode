﻿#include "leetcode.hpp"

/* 2429. 最小异或

给你两个正整数 num1 和 num2 ，找出满足下述条件的正整数 x ：

x 的置位数和 num2 相同，且
x XOR num1 的值 最小
注意 XOR 是按位异或运算。

返回整数 x 。题目保证，对于生成的测试用例， x 是 唯一确定 的。

整数的 置位数 是其二进制表示中 1 的数目。

示例 1：
输入：num1 = 3, num2 = 5
输出：3
解释：
num1 和 num2 的二进制表示分别是 0011 和 0101 。
整数 3 的置位数与 num2 相同，且 3 XOR 3 = 0 是最小的。
示例 2：

输入：num1 = 1, num2 = 12
输出：3
解释：
num1 和 num2 的二进制表示分别是 0001 和 1100 。
整数 3 的置位数与 num2 相同，且 3 XOR 1 = 2 是最小的。

提示：
  1 <= num1, num2 <= 10^9
*/

int minimizeXor(int a, int b)
{
	int ans = 0, flip = 0;
	char abit[32] {};
	for (int i = 0; i < 31; ++i) {
		if (a & (1 << i))
			abit[i] = 1;
		if (b & (1 << i)) ++flip;
	}
	for (int i = 31; i--;)
		if (abit[i] == 1 && flip-- > 0) {
			ans |= 1 << i;
			abit[i] = 2;
		}
	for (int i = 0; i < 31; ++i)
		if (abit[i] == 0 && flip-- > 0)
			ans |= 1 << i;
	return ans;
}

int main()
{
	ToOut(minimizeXor(3, 5));
	ToOut(minimizeXor(1, 12));
}
