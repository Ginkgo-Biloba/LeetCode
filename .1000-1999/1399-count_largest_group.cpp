﻿#include "leetcode.hpp"

/* 1399. 统计最大组的数目

给你一个整数 n 。
请你先求出从 1 到 n 的每个整数 10 进制表示下的数位和（每一位上的数字相加），然后把数位和相等的数字放到同一个组中。

请你统计每个组中的数字数目，并返回数字数目并列最多的组有多少个。

示例 1：
输入：n = 13
输出：4
解释：总共有 9 个组，将 1 到 13 按数位求和后这些组分别是：
[1,10]，[2,11]，[3,12]，[4,13]，[5]，[6]，[7]，[8]，[9]。总共有 4 个组拥有的数字并列最多。

示例 2：
输入：n = 2
输出：2
解释：总共有 2 个大小为 1 的组 [1]，[2]。

示例 3：
输入：n = 15
输出：6

示例 4：
输入：n = 24
输出：5

提示：
  1 <= n <= 10^4
*/

class Solution {
	vector<int> buf;

public:
	Solution()
	{
		int len = static_cast<int>(1e4 + 1);
		buf.resize(len);
		for (int i = 1; i < len; ++i) {
			int k = i, s = 0;
			for (; k; k /= 10)
				s += k % 10;
			buf[i] = s;
		}
	}

	int countLargestGroup(int n)
	{
		int const len = 9 * 4 + 1;
		int num[len + 1] = {0};
		int val = 0, ans = 0;
		for (int i = 1; i <= n; ++i)
			val = max(val, num[buf[i]] += 1);
		for (int i = 1; i <= len; ++i)
			ans += (num[i] == val);
		return ans;
	}
};

int main()
{
	Solution s;
	ToOut(s.countLargestGroup(13));
	ToOut(s.countLargestGroup(2));
	ToOut(s.countLargestGroup(15));
	ToOut(s.countLargestGroup(24));
	ToOut(s.countLargestGroup(999));
	ToOut(s.countLargestGroup(1439));
}
