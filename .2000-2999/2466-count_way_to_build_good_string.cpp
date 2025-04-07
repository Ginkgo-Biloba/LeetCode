﻿#include "leetcode.hpp"

/* 2466. 统计构造好字符串的方案数

给你整数 zero ，one ，low 和 high ，我们从空字符串开始构造一个字符串，每一步执行下面操作中的一种：

将 '0' 在字符串末尾添加 zero  次。
将 '1' 在字符串末尾添加 one 次。
以上操作可以执行任意次。

如果通过以上过程得到一个 长度 在 low 和 high 之间（包含上下边界）的字符串，那么这个字符串我们称为 好 字符串。

请你返回满足以上要求的 不同 好字符串数目。
由于答案可能很大，请将结果对 10^9 + 7 取余 后返回。

示例 1：
输入：low = 3, high = 3, zero = 1, one = 1
输出：8
解释：
一个可能的好字符串是 "011" 。
可以这样构造得到："" -> "0" -> "01" -> "011" 。
从 "000" 到 "111" 之间所有的二进制字符串都是好字符串。

示例 2：
输入：low = 2, high = 3, zero = 1, one = 2
输出：5
解释：好字符串为 "00" ，"11" ，"000" ，"110" 和 "011" 。

提示：
  1 <= low <= high <= 10^5
  1 <= zero, one <= low
*/

int countGoodStrings(int low, int high, int zero, int one)
{
	int const mod = 1000000007;
	int sum = 0;
	vector<int> dp(high + 1);
	dp[0] = 1;
	for (int i = 1; i <= high; ++i) {
		if (i >= zero) dp[i] = dp[i - zero];
		if (i >= one)
			dp[i] = (dp[i] + dp[i - one]) % mod;
		if (i >= low)
			sum = (sum + dp[i]) % mod;
	}
	return sum;
}

int main()
{
	ToOut(countGoodStrings(3, 3, 1, 1));
	ToOut(countGoodStrings(2, 3, 1, 2));
}
