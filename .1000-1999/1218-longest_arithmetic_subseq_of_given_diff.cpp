﻿#include "leetcode.hpp"

/* 1218. 最长定差子序列

给你一个整数数组 arr 和一个整数 difference，请你找出 arr 中所有相邻元素之间的差等于给定 difference 的等差子序列，并返回其中最长的等差子序列的长度。

示例 1：
输入：arr = [1,2,3,4], difference = 1
输出：4
解释：最长的等差子序列是 [1,2,3,4]。

示例 2：
输入：arr = [1,3,5,7], difference = 1
输出：1
解释：最长的等差子序列是任意单个元素。

示例 3：
输入：arr = [1,5,7,8,5,3,4,2,1], difference = -2
输出：4
解释：最长的等差子序列是 [7,5,3,1]。

提示：
  1 <= arr.length <= 10^5
  -10^4 <= arr[i], difference <= 10^4
*/

int longestSubsequence(vector<int>& A, int d)
{
	unordered_map<int, int> M;
	int ans = 1;
	for (int a : A) {
		auto it = M.find(a - d);
		if (it != M.end()) {
			int len = it->second + 1;
			M[a] = len;
			ans = max(ans, len);
		} else
			M[a] = 1;
	}
	return ans;
}

int main()
{
	vector<int>
		a = {1, 2, 3, 4},
		b = {1, 3, 5, 7},
		c = {1, 5, 7, 8, 5, 3, 4, 2, 1};
	ToOut(longestSubsequence(a, 1));
	ToOut(longestSubsequence(b, 1));
	ToOut(longestSubsequence(c, -2));
}
