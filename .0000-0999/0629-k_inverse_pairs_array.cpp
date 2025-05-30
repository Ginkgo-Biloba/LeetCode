﻿#include "leetcode.hpp"

/* 629. K个逆序对数组

给出两个整数 n 和 k，找出所有包含从 1 到 n 的数字，且恰好拥有 k 个逆序对的不同的数组的个数。
逆序对的定义如下：对于数组的第i个和第 j个元素，如果满i < j且 a[i] > a[j]，则其为一个逆序对；否则不是。
由于答案可能很大，只需要返回 答案 mod 10^9 + 7 的值。

示例 1:
输入: n = 3, k = 0
输出: 1
解释:
只有数组 [1,2,3] 包含了从1到3的整数并且正好拥有 0 个逆序对。

示例 2:
输入: n = 3, k = 1
输出: 2
解释:
数组 [1,3,2] 和 [2,1,3] 都有 1 个逆序对。

说明:
  n 的范围是 [1, 1000] 并且 k 的范围是 [0, 1000]。
*/

// https://leetcode.com/problems/k-inverse-pairs-array/discuss/104825/Shared-my-C%2B%2B-O(n-*-k)-solution-with-explanation
// 抄的
int kInversePairs(int n, int k)
{
	int const MOD = static_cast<int>(1e9 + 7);
	vector<int> prev(k + 1), curr(k + 1);
	curr[0] = 1;
	for (int a = 1; a <= n; ++a) {
		curr.swap(prev);
		curr[0] = 1;
		for (int b = 1; b <= k; ++b) {
			curr[b] = (curr[b - 1] + prev[b]) % MOD;
			if (a <= b)
				curr[b] = (curr[b] + MOD - prev[b - a]) % MOD;
		}
	}
	return curr[k];
}

int main()
{
	ToOut(kInversePairs(3, 1));
}
