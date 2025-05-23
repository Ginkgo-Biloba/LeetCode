﻿#include "leetcode.hpp"

/* 1004. 最大连续1的个数 III

给定一个由若干 0 和 1 组成的数组 A，我们最多可以将 K 个值从 0 变成 1 。

返回仅包含 1 的最长（连续）子数组的长度。

示例 1：
输入：A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
输出：6
解释：
[1,1,1,0,0,1,1,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 6。

示例 2：
输入：A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
输出：10
解释：
[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 10。

提示：
  1 <= A.length <= 20000
  0 <= K <= A.length
  A[i] 为 0 或 1
*/

int longestOnes(vector<int>& A, int K)
{
	int len = static_cast<int>(A.size());
	int ans = 0, h = 0;
	for (int i = 0; i < len; ++i) {
		K -= (A[i] == 0);
		if (K < 0) {
			K += (A[h] == 0);
			++h;
		}
		ans = max(ans, i - h + 1);
	}
	return ans;
}

int main()
{
	vector<int>
		a = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0},
		b = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
	ToOut(longestOnes(a, 2));
	ToOut(longestOnes(b, 3));
}
