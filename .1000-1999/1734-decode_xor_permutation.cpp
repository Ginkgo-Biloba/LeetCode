﻿#include "leetcode.hpp"

/* 1734. 解码异或后的排列

给你一个整数数组 perm ，它是前 n 个正整数的排列，且 n 是个 奇数 。
它被加密成另一个长度为 n - 1 的整数数组 encoded ，满足 encoded[i] = perm[i] XOR perm[i + 1] 。
比方说，如果 perm = [1,3,2] ，那么 encoded = [2,1] 。

给你 encoded 数组，请你返回原始数组 perm 。
题目保证答案存在且唯一。

示例 1：
输入：encoded = [3,1]
输出：[1,2,3]
解释：如果 perm = [1,2,3] ，那么 encoded = [1 XOR 2,2 XOR 3] = [3,1]

示例 2：
输入：encoded = [6,5,4,6]
输出：[2,4,1,5,3]

提示：
  3 <= n < 10^5
  n 是奇数。
  encoded.length == n - 1
*/

// https://leetcode-cn.com/problems/decode-xored-permutation/solution/ling-ji-yi-dong-de-jie-fa-by-motmlsc-5zkm/
// 抄的
vector<int> decode(vector<int>& A)
{
	int n = static_cast<int>(A.size()) + 1;
	int cur = 0;
	vector<int> C;
	for (int i = 1; i <= n; ++i)
		cur ^= i;
	for (int i = 1; i < n - 1; i += 2)
		cur ^= A[i];
	C.push_back(cur);
	for (int i = 0; i < n - 1; ++i) {
		cur ^= A[i];
		C.push_back(cur);
	}
	return C;
}

int main()
{
	vector<int>
		a = {3, 1},
		b = {6, 5, 4, 6};
	ToOut(decode(a));
	ToOut(decode(b));
}
