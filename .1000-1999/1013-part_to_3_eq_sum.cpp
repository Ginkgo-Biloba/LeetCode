﻿#include "leetcode.hpp"

/* 1013. 将数组分成和相等的三个部分

给定一个整数数组 A，只有我们可以将其划分为三个和相等的非空部分时才返回 true，否则返回 false。

形式上，如果我们可以找出索引 i+1 < j 且满足 (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1]) 就可以将数组三等分。

示例 1：
输出：[0,2,1,-6,6,-7,9,1,2,0,1]
输出：true
解释：0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1

示例 2：
输入：[0,2,1,-6,6,7,9,-1,2,0,1]
输出：false

示例 3：
输入：[3,3,6,5,-2,2,5,1,-9,4]
输出：true
解释：3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4

提示：
  3 <= A.length <= 50000
  -10000 <= A[i] <= 10000
*/

bool canThreePartsEqualSum(vector<int>& A)
{
	int n = 0, s = 0, p;
	for (int a : A)
		s += a;
	if (s % 3)
		return false;
	p = s / 3;
	s = 0;
	for (int a : A) {
		s += a;
		if (s == p) {
			++n;
			s = 0;
		}
	}
	return n >= 3;
}

int main()
{
	vector<int>
		a = {0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1},
		b = {0, 2, 1, -6, 6, 7, 9, -1, 2, 0, 1},
		c = {3, 3, 6, 5, -2, 2, 5, 1, -9, 4};
	ToOut(canThreePartsEqualSum(a));
	ToOut(canThreePartsEqualSum(b));
	ToOut(canThreePartsEqualSum(c));
}
