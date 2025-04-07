﻿#include "leetcode.hpp"

/* 888. 公平的糖果交换

爱丽丝和鲍勃有不同大小的糖果棒：A[i] 是爱丽丝拥有的第 i 块糖的大小，B[j] 是鲍勃拥有的第 j 块糖的大小。

因为他们是朋友，所以他们想交换一个糖果棒，这样交换后，他们都有相同的糖果总量。
一个人拥有的糖果总量是他们拥有的糖果棒大小的总和。

返回一个整数数组 ans，其中 ans[0] 是爱丽丝必须交换的糖果棒的大小，ans[1] 是 Bob 必须交换的糖果棒的大小。

如果有多个答案，你可以返回其中任何一个。保证答案存在。

示例 1：
输入：A = [1,1], B = [2,2]
输出：[1,2]

示例 2：
输入：A = [1,2], B = [2,3]
输出：[1,2]

示例 3：
输入：A = [2], B = [1,3]
输出：[2,3]

示例 4：
输入：A = [1,2,5], B = [2,4]
输出：[5,4]

提示：
  1 <= A.length <= 10000
  1 <= B.length <= 10000
  1 <= A[i] <= 100000
  1 <= B[i] <= 100000
  保证爱丽丝与鲍勃的糖果总量不同。
  答案肯定存在。
*/

vector<int> fairCandySwap(vector<int>& A, vector<int>& B)
{
	int lenA = static_cast<int>(A.size());
	int lenB = static_cast<int>(B.size());
	int sA = 0, sB = 0, sd;
	vector<int> ab(2);

	for (int i = 0; i < lenA; ++i)
		sA += A[i];
	for (int i = 0; i < lenB; ++i)
		sB += B[i];
	sd = (sA - sB) / 2;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int iA = 0, iB = 0;
	while (iA < lenA && iB < lenB) {
		int cd = A[iA] - B[iB];
		if (cd == sd) {
			ab[0] = A[iA];
			ab[1] = B[iB];
			break;
		} else if (cd < sd)
			++iA;
		else
			++iB;
	}
	return ab;
}

int main()
{
	vector<int>
		a = {1, 1},
		b = {2, 2},
		c = {1, 2}, d = {2, 3},
		e = {2}, f = {1, 3},
		g = {1, 2, 5}, h = {2, 4};
	ToOut(fairCandySwap(a, b));
	ToOut(fairCandySwap(c, d));
	ToOut(fairCandySwap(e, f));
	ToOut(fairCandySwap(g, h));
}
