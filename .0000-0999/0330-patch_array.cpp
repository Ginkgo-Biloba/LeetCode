﻿#include "leetcode.hpp"

/* 330. 按要求补齐数组

给定一个已排序的正整数数组 nums，和一个正整数 n 。
从 [1, n] 区间内选取任意个数字补充到 nums 中，使得 [1, n] 区间内的任何数字都可以用 nums 中某几个数字的和来表示。
请输出满足上述要求的最少需要补充的数字个数。

示例 1:
输入: nums = [1,3], n = 6
输出: 1
解释:
根据 nums 里现有的组合 [1], [3], [1,3]，可以得出 1, 3, 4。
现在如果我们将 2 添加到 nums 中， 组合变为: [1], [2], [3], [1,3], [2,3], [1,2,3]。
其和可以表示数字 1, 2, 3, 4, 5, 6，能够覆盖 [1, 6] 区间里所有的数。
所以我们最少需要添加一个数字。

示例 2:
输入: nums = [1,5,10], n = 20
输出: 2
解释: 我们需要添加 [2, 4]。

示例 3:
输入: nums = [1,2,2], n = 5
输出: 0
*/

int minPatches(vector<int>& A, int n)
{
	int len = static_cast<int>(A.size());
	int i = 1, ans = 0;
	int64_t cur = 1;
	if ((len == 0) || (A[0] != 1)) {
		i = 0;
		ans = 1;
	}
	while (cur < n) {
		while ((i < len) && (cur + 1 >= A[i]))
			cur += A[i++];
		if (cur >= n)
			return ans;
		cur += cur + 1;
		++ans;
	}
	return ans;
}

// https://leetcode.com/problems/patching-array/discuss/78488/Solution-%2B-explanation
// 抄的
int minPatches_Org(vector<int>& A, int n)
{
	int len = static_cast<int>(A.size());
	int i = 0, ans = 0;
	int64_t miss = 1;
	while (miss <= n) {
		if ((i < len) && (miss >= A[i]))
			miss += A[i++];
		else {
			miss += miss;
			ans += 1;
		}
	}
	return ans;
}

int main()
{
	vector<int>
		a = {1, 3},
		b = {1, 5, 10},
		c = {1, 2, 2};
	ToOut(minPatches(a, 6));
	ToOut(minPatches(b, 20));
	ToOut(minPatches(c, 5));
}
