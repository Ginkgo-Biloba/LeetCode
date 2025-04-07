﻿#include "leetcode.hpp"

/* 2478. 完美分割的方案数

给你一个字符串 s ，每个字符是数字 '1' 到 '9' ，再给你两个整数 k 和 minLength 。

如果对 s 的分割满足以下条件，那么我们认为它是一个 完美 分割：

s 被分成 k 段互不相交的子字符串。
每个子字符串长度都 至少 为 minLength 。
每个子字符串的第一个字符都是一个 质数 数字，最后一个字符都是一个 非质数 数字。
质数数字为 '2' ，'3' ，'5' 和 '7' ，剩下的都是非质数数字。
请你返回 s 的 完美 分割数目。
由于答案可能很大，请返回答案对 10^9 + 7 取余 后的结果。

一个 子字符串 是字符串中一段连续字符串序列。

示例 1：
输入：s = "23542185131", k = 3, minLength = 2
输出：3
解释：存在 3 种完美分割方案：
"2354 | 218 | 5131"
"2354 | 21851 | 31"
"2354218 | 51 | 31"

示例 2：
输入：s = "23542185131", k = 3, minLength = 3
输出：1
解释：存在一种完美分割方案："2354 | 218 | 5131" 。

示例 3：
输入：s = "3312958", k = 3, minLength = 1
输出：1
解释：存在一种完美分割方案："331 | 29 | 58" 。

提示：
  1 <= k, minLength <= s.length <= 1000
  s 每个字符都为数字 '1' 到 '9' 之一。
*/

int beautifulPartitions(string s, int k, int minLength)
{
	int const mod = static_cast<int>(1e9 + 7);
	bool const isPrime[10] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0};
	int n = static_cast<int>(s.size());
	if (!isPrime[s[0] - '0'] || isPrime[s[n - 1] - '0'])
		return 0;
	// 添加个质数，简化判断
	s.push_back('2');
	vector<int> cur(n + 1), sum(n + 1);
	cur[0] = 1;
	while (k--) {
		sum[0] = cur[0];
		for (int i = 1; i <= n; ++i)
			sum[i] = (sum[i - 1] + cur[i]) % mod;
		memset(cur.data(), 0, cur.size() * sizeof(cur[0]));
		for (int i = minLength; i <= n; ++i) {
			if (!isPrime[s[i - 1] - '0'] && isPrime[s[i] - '0'])
				cur[i] = sum[i - minLength];
		}
	}
	return cur[n];
}

int main()
{
	ToOut(beautifulPartitions("783938233588472343879134266968", 4, 6));
	ToOut(beautifulPartitions("23542185131", 3, 2));
	ToOut(beautifulPartitions("23542185131", 3, 3));
	ToOut(beautifulPartitions("3312958", 3, 1));
}
