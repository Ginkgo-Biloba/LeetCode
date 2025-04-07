﻿#include "leetcode.hpp"

/* 1175. 质数排列

请你帮忙给从 1 到 n 的数设计排列方案，使得所有的「质数」都应该被放在「质数索引」（索引从 1 开始）上；你需要返回可能的方案总数。

让我们一起来回顾一下「质数」：质数一定是大于 1 的，并且不能用两个小于它的正整数的乘积来表示。

由于答案可能会很大，所以请你返回答案 模 mod 10^9 + 7 之后的结果即可。

示例 1：
输入：n = 5
输出：12
解释：举个例子，[1,2,5,4,3] 是一个有效的排列，但 [5,2,3,4,1] 不是，因为在第二种情况里质数 5 被错误地放在索引为 1 的位置上。

示例 2：
输入：n = 100
输出：682289015

提示：
  1 <= n <= 100
*/

bool isPrime(int n)
{
	int k = static_cast<int>(::sqrt(n));
	for (; k > 1; --k) {
		if (n % k == 0)
			break;
	}
	return n >= 2 && k == 1;
}

int numPrimeArrangements(int n)
{
	int64_t const Mod = static_cast<int>(1e9 + 7);
	int p = 0, q = 0;
	for (int i = 1; i <= n; ++i)
		p += isPrime(i);
	q = n - p;
	n = max(p, q);

	vector<int64_t> A(n + 1);
	A[0] = 1;
	for (int i = 1; i <= n; ++i)
		A[i] = (A[i - 1] * i) % Mod;

	A[0] = (A[p] * A[q]) % Mod;
	return static_cast<int>(A[0]);
}

int main()
{
	ToOut(numPrimeArrangements(5));
	ToOut(numPrimeArrangements(100));
}
