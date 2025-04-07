﻿#include "leetcode.hpp"

/* 1819. 序列中不同最大公约数的数目

给你一个由正整数组成的数组 nums 。

数字序列的 最大公约数 定义为序列中所有整数的共有约数中的最大整数。
  例如，序列 [4,6,16] 的最大公约数是 2 。

数组的一个 子序列 本质是一个序列，可以通过删除数组中的某些元素（或者不删除）得到。
  例如，[2,5,10] 是 [1,2,1,2,4,1,5,10] 的一个子序列。

计算并返回 nums 的所有 非空 子序列中 不同 最大公约数的 数目 。

示例 1：
https://assets.leetcode.com/uploads/2021/03/17/image-1.png
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/04/03/image-1.png
输入：nums = [6,10,3]
输出：5
解释：上图显示了所有的非空子序列与各自的最大公约数。
不同的最大公约数为 6 、10 、3 、2 和 1 。

示例 2：
输入：nums = [5,15,40,5,6]
输出：7

提示：
  1 <= nums.length <= 10^5
  1 <= nums[i] <= 2 * 10^5
*/

// https://leetcode-cn.com/problems/number-of-different-subsequences-gcds/solution/kao-lu-mei-yi-ge-shu-shi-fou-ke-yi-cheng-2sb2/
// 抄的，没看懂
class Solution {
	int limit;
	vector<char> has;

	int gcd(int a, int b)
	{
		while (b) {
			int t = a % b;
			a = b;
			b = t;
		}
		return a;
	}

	bool check(int x)
	{
		int t = 0;
		for (int i = x; i <= limit; i += x)
			if (has[i])
				t = gcd(t, i / x);
		return t == 1;
	}

public:
	int countDifferentSubsequenceGCDs(vector<int>& A)
	{
		int len = static_cast<int>(A.size());
		has.assign(200010, 0);
		limit = 0;
		for (int i = 0; i < len; ++i) {
			limit = max(limit, A[i]);
			has[A[i]] = 1;
		}
		int s = 0;
		for (int i = 1; i < 200010; ++i)
			s += check(i);
		return s;
	}
};

int main()
{
	Solution s;
	vector<int>
		a = {6, 10, 3},
		b = {5, 15, 40, 5, 6};
	ToOut(s.countDifferentSubsequenceGCDs(a));
	ToOut(s.countDifferentSubsequenceGCDs(b));
}
