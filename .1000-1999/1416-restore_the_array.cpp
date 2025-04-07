﻿#include "leetcode.hpp"

/* 1416. 恢复数组

某个程序本来应该输出一个整数数组。但是这个程序忘记输出空格了以致输出了一个数字字符串，我们所知道的信息只有：数组中所有整数都在 [1, k] 之间，且数组中的数字都没有前导 0 。

给你字符串 s 和整数 k 。可能会有多种不同的数组恢复结果。

按照上述程序，请你返回所有可能输出字符串 s 的数组方案数。

由于数组方案数可能会很大，请你返回它对 10^9 + 7 取余 后的结果。


示例 1：
输入：s = "1000", k = 10000
输出：1
解释：唯一一种可能的数组方案是 [1000]

示例 2：
输入：s = "1000", k = 10
输出：0
解释：不存在任何数组方案满足所有整数都 >= 1 且 <= 10 同时输出结果为 s 。

示例 3：
输入：s = "1317", k = 2000
输出：8
解释：可行的数组方案为 [1317]，[131,7]，[13,17]，[1,317]，[13,1,7]，[1,31,7]，[1,3,17]，[1,3,1,7]

示例 4：
输入：s = "2020", k = 30
输出：1
解释：唯一可能的数组方案是 [20,20] 。 [2020] 不是可行的数组方案，原因是 2020 > 30 。 [2,020] 也不是可行的数组方案，因为 020 含有前导 0 。

示例 5：
输入：s = "1234567890", k = 90
输出：34

提示：
  1 <= s.length <= 10^5.
  s 只包含数字且不包含前导 0 。
  1 <= k <= 10^9.
*/

class Solution {
	int64_t k64;
	int64_t p10[10];

public:
	Solution()
	{
		p10[0] = 1;
		for (int i = 1; i < 10; ++i)
			p10[i] = p10[i - 1] * 10;
	}

	int numberOfArrays(string s, int k)
	{
		int64_t const Mod = static_cast<int>(1e9 + 7);
		k64 = k;
		s.reserve(s.length() + 10);
		reverse(s.begin(), s.end());
		for (int i = 0; i < 10; ++i)
			s.push_back('0');
		reverse(s.begin(), s.end());
		int len = static_cast<int>(s.size());
		vector<int64_t> dp(len);
		for (int i = 0; i < 10; ++i)
			dp[i] = 1;
		for (int i = 10; i < len; ++i) {
			int64_t val = 0;
			for (int d = 0; d < 10; ++d) {
				int h = i - d;
				val += p10[d] * (s[h] - '0');
				if (s[h] != '0' && 0 < val && val <= k)
					dp[i] += dp[h - 1];
			}
			dp[i] %= Mod;
		}
		return static_cast<int>(dp[len - 1]);
	}
};

int main()
{
	Solution s;
	ToOut(s.numberOfArrays("1000", 10000));
	ToOut(s.numberOfArrays("1000", 10));
	ToOut(s.numberOfArrays("1317", 2000));
	ToOut(s.numberOfArrays("2020", 30));
	ToOut(s.numberOfArrays("1234567890", 90));
}
