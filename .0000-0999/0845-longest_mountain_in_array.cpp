﻿#include "leetcode.hpp"

/* 845. 数组中的最长山脉

我们把数组 A 中符合下列属性的任意连续子数组 B 称为 “山脉”：
    B.length >= 3
    存在 0 < i < B.length - 1 使得 B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
注意：B 可以是 A 的任意子数组，包括整个数组 A。

给出一个整数数组 A，返回最长 “山脉” 的长度。
如果不含有 “山脉” 则返回 0。

示例 1：
输入：[2,1,4,7,3,2,5]
输出：5
解释：最长的 “山脉” 是 [1,4,7,3,2]，长度为 5。

示例 2：
输入：[2,2,2]
输出：0
解释：不含 “山脉”。

提示：
  0 <= A.length <= 10000
  0 <= A[i] <= 10000

Follow up:
  Can you solve it using only one pass?
  Can you solve it in O(1) space?
*/

void skip(vector<int>& A, int& prev, int& i, int len)
{
	for (; i < len && A[i - 1] >= A[i]; ++i);
	prev = i - 1;
}

int longestMountain1(vector<int>& A)
{
	A.reserve(A.size() + 1);
	A.push_back(INT_MAX);
	int len = static_cast<int>(A.size());
	int prev, ans = 0, i = 1;
	bool ascend = true;
	if (len < 3)
		return 0;

	skip(A, prev, i, len);
	for (++i; i < len; ++i) {
		if (ascend) {
			if (A[i - 1] > A[i])
				ascend = false;
			else if (A[i - 1] == A[i])
				skip(A, prev, i, len);
		} else if (A[i - 1] <= A[i]) {
			int d = i - prev;
			if (d >= 3)
				ans = std::max(ans, d);
			skip(A, prev, i, len);
			ascend = true;
		}
	}

	return ans;
}

// https://leetcode.com/problems/longest-mountain-in-array/discuss/135593/C%2B%2BJavaPython-1-pass-and-O(1)-space
// 抄的
int longestMountain(vector<int> A)
{
	int len = static_cast<int>(A.size());
	int ans = 0, up = 0, down = 0;
	for (int i = 1; i < len; ++i) {
		if ((down && A[i - 1] < A[i]) || (A[i - 1] == A[i]))
			up = down = 0;
		up += (A[i - 1] < A[i]);
		down += (A[i - 1] > A[i]);
		if (up && down)
			ans = std::max(ans, up + down + 1);
	}
	return ans;
}

int main()
{
	vector<int>
		a = {2, 1, 4, 7, 3, 2, 5},
		b = {2, 2, 2},
		c = {0, 2, 2},
		d = {
			0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1};
	ToOut(longestMountain(a));
	ToOut(longestMountain(b));
	ToOut(longestMountain(c));
	ToOut(longestMountain(d));
}
