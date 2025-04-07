﻿#include "leetcode.hpp"

/* 321. 拼接最大数

给定长度分别为 m 和 n 的两个数组，其元素由 0-9 构成，表示两个自然数各位上的数字。
现在从这两个数组中选出 k (k <= m + n) 个数字拼接成一个新的数，要求从同一个数组中取出的数字保持其在原数组中的相对顺序。

求满足该条件的最大数。
结果返回一个表示该最大数的长度为 k 的数组。

说明: 请尽可能地优化你算法的时间和空间复杂度。

示例 1:
输入:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
输出:
[9, 8, 6, 5, 3]

示例 2:
输入:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
输出:
[6, 7, 6, 0, 4]

示例 3:
输入:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
输出:
[9, 8, 9]
*/

// https://leetcode.com/problems/create-maximum-number/discuss/?currentPage=1&orderBy=most_votes&query=
// 抄的
class Solution {
public:
	void maxArray(vector<int>& nums, int k, vector<int>& ans)
	{
		ans.assign(k, 0);
		int len = static_cast<int>(nums.size());
		int i = 0, A = 0;
		for (; i < len; ++i) {
			while (len - i + A > k // 剩余个数大于等于 k
				&& A > 0
				&& ans[A - 1] < nums[i])
				--A;
			if (A < k) {
				ans[A] = nums[i];
				++A;
			}
		}
	}

	bool greater(vector<int>& n1, int i1, vector<int>& n2, int i2)
	{
		int L1 = static_cast<int>(n1.size()),
				L2 = static_cast<int>(n2.size());
		for (; i1 < L1 && i2 < L2 && n1[i1] == n2[i2]; ++i1, ++i2);
		return (i1 == L1 && i2 < L2)
			? false
			: (i2 == L2 && i1 < L1)
			? true
			: (i1 < L1 && i2 < L2 && n1[i1] > n2[i2]);
	}

	void merge(vector<int>& n1, vector<int>& n2, int k, vector<int>& ans)
	{
		ans.assign(k, 0);
		int i1 = 0, i2 = 0;
		for (int r = 0; r < k; ++r) {
			if (greater(n1, i1, n2, i2)) {
				ans[r] = n1[i1];
				++i1;
			} else {
				ans[r] = n2[i2];
				++i2;
			}
		}
	}

	vector<int> maxNumber(vector<int>& n1, vector<int>& n2, int k)
	{
		vector<int> ans(k);
		int L1 = static_cast<int>(n1.size()),
				L2 = static_cast<int>(n2.size());
		int i = std::max(0, k - L2);
		vector<int> v1(k), v2(k), cand(k);

		for (; i <= k && i <= L1; ++i) {
			maxArray(n1, i, v1);
			maxArray(n2, k - i, v2);
			merge(v1, v2, k, cand);
			if (greater(cand, 0, ans, 0))
				ans.swap(cand);
		}

		return ans;
	}
};

int main()
{
	vector<int>
		a = {3, 4, 6, 5},
		b = {9, 1, 2, 5, 8, 3},
		c = {6, 7},
		d = {6, 0, 4},
		e = {3, 9},
		f = {8, 9};
	Solution s;
	ToOut(s.maxNumber(a, b, 5));
	ToOut(s.maxNumber(c, d, 5));
	ToOut(s.maxNumber(e, f, 3));
}
