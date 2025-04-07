#include "leetcode.hpp"

/* 2484. 统计回文子序列数目

给你数字字符串 s ，请你返回 s 中长度为 5 的 回文子序列 数目。
由于答案可能很大，请你将答案对 10^9 + 7 取余 后返回。

提示：
如果一个字符串从前往后和从后往前读相同，那么它是 回文字符串 。
子序列是一个字符串中删除若干个字符后，不改变字符顺序，剩余字符构成的字符串。

示例 1：
输入：s = "103301"
输出：2
解释：
总共有 6 长度为 5 的子序列："10330" ，"10331" ，"10301" ，"10301" ，"13301" ，"03301" 。
它们中有两个（都是 "10301"）是回文的。

示例 2：
输入：s = "0000000"
输出：21
解释：所有 21 个长度为 5 的子序列都是 "00000" ，都是回文的。

示例 3：
输入：s = "9999900000"
输出：2
解释：仅有的两个回文子序列是 "99999" 和 "00000" 。

提示：
  1 <= s.length <= 10^4
  s 只包含数字字符。
*/

// https://leetcode.cn/problems/count-palindromic-subsequences/solutions/1993115/qian-hou-zhui-fen-jie-o100-chang-shu-kon-51cv/
// 抄的
int countPalindromes(string str)
{
	int n = static_cast<int>(str.size());
	int suffix[10] {}, S[10][10] {};
	for (int i = n - 1; i >= 0; --i) {
		int x = str[i] - '0';
		for (int y = 0; y < 10; ++y)
			S[x][y] += suffix[y];
		++suffix[x];
	}
	int64_t ans = 0;
	int prefix[10] {}, P[10][10] {};
	for (int x : str) {
		x -= '0';
		--suffix[x];
		for (int y = 0; y < 10; ++y)
			S[x][y] -= suffix[y];
		for (int a = 0; a < 10; ++a)
			for (int b = 0; b < 10; ++b)
				ans += static_cast<int64_t>(P[a][b]) * S[b][a];
		for (int u = 0; u < 10; ++u)
			P[u][x] += prefix[u];
		++prefix[x];
	}
	return static_cast<int>(ans % static_cast<int64_t>(1e9 + 7));
}

int main()
{
	ToOut(countPalindromes("103301"));
	ToOut(countPalindromes("0000000"));
	ToOut(countPalindromes("9999900000"));
}
