﻿#include "leetcode.hpp"

/* 1944. 队列中可以看到的人数

有 n 个人排成一个队列，从左到右 编号为 0 到 n - 1 。
给你以一个整数数组 heights ，每个整数 互不相同，heights[i] 表示第 i 个人的高度。

一个人能 看到 他右边另一个人的条件是这两人之间的所有人都比他们两人 矮 。
更正式的，第 i 个人能看到第 j 个人的条件是 i < j 且 min(heights[i], heights[j]) > max(heights[i+1], heights[i+2], ..., heights[j-1]) 。

请你返回一个长度为 n 的数组 answer ，其中 answer[i] 是第 i 个人在他右侧队列中能 看到 的 人数 。

示例 1：
输入：heights = [10,6,8,5,11,9]
输出：[3,1,2,1,1,0]
解释：
第 0 个人能看到编号为 1 ，2 和 4 的人。
第 1 个人能看到编号为 2 的人。
第 2 个人能看到编号为 3 和 4 的人。
第 3 个人能看到编号为 4 的人。
第 4 个人能看到编号为 5 的人。
第 5 个人谁也看不到因为他右边没人。

示例 2：
输入：heights = [5,1,2,3,10]
输出：[4,1,1,1,0]

提示：
  n == heights.length
  1 <= n <= 10^5
  1 <= heights[i] <= 10^5
  heights 中所有数 互不相同 。
*/

// 抄的
vector<int> canSeePersonsCount(vector<int>& A)
{
	int len = static_cast<int>(A.size());
	vector<int> R(len), S;
	for (int i = 0; i < len; ++i) {
		while (S.size() && A[S.back()] <= A[i]) {
			R[S.back()] += 1;
			S.pop_back();
		}
		if (S.size())
			R[S.back()] += 1;
		S.push_back(i);
	}
	return R;
}

int main() { }
