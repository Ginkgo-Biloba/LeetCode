﻿#include "leetcode.hpp"

/* 1535. 找出数组游戏的赢家

给你一个由 不同 整数组成的整数数组 arr 和一个整数 k 。

每回合游戏都在数组的前两个元素（即 arr[0] 和 arr[1] ）之间进行。
比较 arr[0] 与 arr[1] 的大小，较大的整数将会取得这一回合的胜利并保留在位置 0 ，较小的整数移至数组的末尾。
当一个整数赢得 k 个连续回合时，游戏结束，该整数就是比赛的 赢家 。

返回赢得比赛的整数。

题目数据 保证 游戏存在赢家。

示例 1：

输入：arr = [2,1,3,5,4,6,7], k = 2
输出：5
解释：一起看一下本场游戏每回合的情况：
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/07/30/q-example.png
因此将进行 4 回合比赛，其中 5 是赢家，因为它连胜 2 回合。

示例 2：
输入：arr = [3,2,1], k = 10
输出：3
解释：3 将会在前 10 个回合中连续获胜。

示例 3：
输入：arr = [1,9,8,2,3,7,6,4,5], k = 7
输出：9

示例 4：
输入：arr = [1,11,22,33,44,55,66,77,88,99], k = 1000000000
输出：99

提示：
  2 <= arr.length <= 10^5
  1 <= arr[i] <= 10^6
  arr 所含的整数 各不相同 。
  1 <= k <= 10^9
*/

int getWinner(vector<int>& A, int k)
{
	int len = static_cast<int>(A.size());
	int xval = -1, cmp = len;
	vector<int> M;
	for (int i = 0; i < len; ++i)
		xval = max(xval, A[i]);
	M.resize(xval + 1);
	for (int p = 1; (--cmp) && (p < len); ++p) {
		if (A[0] < A[p])
			A[0] = A[p];
		if (++(M[A[0]]) >= k)
			return A[0];
	}
	return xval;
}

int main()
{
	vector<int>
		a = {2, 1, 3, 5, 4, 6, 7},
		b = {3, 2, 1},
		c = {1, 9, 8, 2, 3, 7, 6, 4, 5},
		d = {1, 11, 22, 33, 44, 55, 66, 77, 88, 99},
		e = {7, 2, 3, 14};
	ToOut(getWinner(a, 2));
	ToOut(getWinner(b, 10));
	ToOut(getWinner(c, 7));
	ToOut(getWinner(d, 1000000000));
	ToOut(getWinner(e, 3));
}
