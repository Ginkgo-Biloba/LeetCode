﻿#include "leetcode.hpp"

/* 300. 最长上升子序列

给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。

说明:
  可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
  你算法的时间复杂度应该为 O(n^2) 。

进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
*/

//
// 当初是抄的
int lengthOfLIS(vector<int>& A)
{
	vector<int> S;
	for (int a : A) {
		auto it = lower_bound(S.begin(), S.end(), a);
		if (it == S.end())
			S.push_back(a);
		else
			*it = a;
	}
	return static_cast<int>(S.size());
}

int main()
{
	vector<int> a = {10, 9, 2, 5, 3, 7, 101, 18};
	ToOut(lengthOfLIS(a));
}
