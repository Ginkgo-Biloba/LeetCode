﻿#include "leetcode.hpp"

/* 376. 摆动序列

如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为摆动序列。
第一个差（如果存在的话）可能是正数或负数。少于两个元素的序列也是摆动序列。

例如， [1,7,4,9,2,5] 是一个摆动序列，因为差值 (6,-3,5,-7,3) 是正负交替出现的。
相反, [1,4,7,2,5] 和 [1,7,4,5,5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。

给定一个整数序列，返回作为摆动序列的最长子序列的长度。
通过从原始序列中删除一些（也可以不删除）元素来获得子序列，剩下的元素保持其原始顺序。

示例 1:
输入: [1,7,4,9,2,5]
输出: 6
解释: 整个序列均为摆动序列。

示例 2:
输入: [1,17,5,10,13,15,10,5,16,8]
输出: 7
解释: 这个序列包含几个长度为 7 摆动序列，其中一个可为[1,17,10,13,10,16,8]。

示例 3:
输入: [1,2,3,4,5,6,7,8,9]
输出: 2

进阶:
你能否用 O(n) 时间复杂度完成此题?
*/

// 抄的
// https://leetcode.com/problems/wiggle-subsequence/discuss/84843/Easy-understanding-DP-solution-with-O(n)-Java-version
int wiggleMaxLength(vector<int>& A)
{
	int len = static_cast<int>(A.size());
	if (len < 2)
		return len;

	int up = 1, down = 1;
	for (int i = 1; i < len; ++i) {
		if (A[i] > A[i - 1])
			up = down + 1;
		else if (A[i] < A[i - 1])
			down = up + 1;
	}

	len = std::max(up, down);
	return len;
}

int main()
{
	vector<int> A = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
	ToOut(wiggleMaxLength(A));
}
