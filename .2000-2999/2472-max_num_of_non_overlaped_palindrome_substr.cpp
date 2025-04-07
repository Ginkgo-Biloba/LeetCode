#include "leetcode.hpp"

/* 2472. 不重叠回文子字符串的最大数目

给你一个字符串 s 和一个 正 整数 k 。

从字符串 s 中选出一组满足下述条件且 不重叠 的子字符串：

每个子字符串的长度 至少 为 k 。
每个子字符串是一个 回文串 。
返回最优方案中能选择的子字符串的 最大 数目。

子字符串 是字符串中一个连续的字符序列。

示例 1 ：
输入：s = "abaccdbbd", k = 3
输出：2
解释：可以选择 s = "abaccdbbd" 中斜体加粗的子字符串。"aba" 和 "dbbd" 都是回文，且长度至少为 k = 3 。
可以证明，无法选出两个以上的有效子字符串。

示例 2 ：
输入：s = "adbcda", k = 2
输出：0
解释：字符串中不存在长度至少为 2 的回文子字符串。

提示：
  1 <= k <= s.length <= 2000
  s 仅由小写英文字母组成
*/

int maxPalindromes(string s, int k)
{
	int n = static_cast<int>(s.size());
	TriUpper<uint8_t> P(n);
	for (int l = 0; l < n; ++l) {
		P(l, l) = 1;
		if (l < n - 1)
			P(l, l + 1) = (s[l] == s[l + 1]);
	}
	for (int d = 3, dend = min(k + 1, n); d <= dend; ++d)
		for (int l = 0, r = l + d - 1; r < n; ++l, ++r)
			P(l, r) = (s[l] == s[r] && P(l + 1, r - 1));
	vector<int> dp(n + 1);
	for (int r = 1; r <= n; ++r) {
		dp[r] = dp[r - 1];
		int l = r - k;
		if (l >= 0)
			dp[r] = max(dp[r], dp[l] + P(l, r - 1));
		l = r - k - 1;
		if (l >= 0)
			dp[r] = max(dp[r], dp[l] + P(l, r - 1));
	}
	return dp[n];
}

int main()
{
	ToOut(maxPalindromes("abaccdbbd", 3));
	ToOut(maxPalindromes("adbcda", 2));
}
