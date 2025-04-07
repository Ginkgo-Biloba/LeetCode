﻿#include "leetcode.hpp"

/* 2165. 重排数字的最小值

给你一个整数 num 。重排 num 中的各位数字，使其值 最小化 且不含 任何 前导零。

返回不含前导零且值最小的重排数字。

注意，重排各位数字后，num 的符号不会改变。

示例 1：
输入：num = 310
输出：103
解释：310 中各位数字的可行排列有：013、031、103、130、301、310 。
不含任何前导零且值最小的重排数字是 103 。

示例 2：
输入：num = -7605
输出：-7650
解释：-7605 中各位数字的部分可行排列为：-7650、-6705、-5076、-0567。
不含任何前导零且值最小的重排数字是 -7650 。

提示：
  -10^15 <= num <= 10^15
*/

long long smallestNumber(long long A)
{
	if (A == 0)
		return 0;
	vector<long long> digit;
	digit.reserve(32);
	long long val = llabs(A);
	for (; val; val /= 10)
		digit.push_back(val % 10);
	sort(digit.begin(), digit.end());
	val = 0;
	if (A < 0) {
		for (auto it = digit.rbegin(); it != digit.rend(); ++it)
			val = val * 10 - *it;
	} else {
		auto it = std::upper_bound(digit.begin(), digit.end(), 0);
		std::iter_swap(it, digit.begin());
		for (it = digit.begin(); it != digit.end(); ++it)
			val = val * 10 + *it;
	}
	return val;
}

int main() { }
