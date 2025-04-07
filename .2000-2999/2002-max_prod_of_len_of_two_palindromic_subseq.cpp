#include "leetcode.hpp"

/* 2002. 两个回文子序列长度的最大乘积

给你一个字符串 s ，请你找到 s 中两个 不相交回文子序列 ，使得它们长度的 乘积最大 。
两个子序列在原字符串中如果没有任何相同下标的字符，则它们是 不相交 的。

请你返回两个回文子序列长度可以达到的 最大乘积 。

子序列 指的是从原字符串中删除若干个字符（可以一个也不删除）后，剩余字符不改变顺序而得到的结果。
如果一个字符串从前往后读和从后往前读一模一样，那么这个字符串是一个 回文字符串 。

示例 1：
https://assets.leetcode.com/uploads/2021/08/24/two-palindromic-subsequences.png
输入：s = "leetcodecom"
输出：9
解释：最优方案是选择 "ete" 作为第一个子序列，"cdc" 作为第二个子序列。
它们的乘积为 3 * 3 = 9 。

示例 2：
输入：s = "bb"
输出：1
解释：最优方案为选择 "b" （第一个字符）作为第一个子序列，"b" （第二个字符）作为第二个子序列。
它们的乘积为 1 * 1 = 1 。

示例 3：
输入：s = "accbcaxxcxx"
输出：25
解释：最优方案为选择 "accca" 作为第一个子序列，"xxcxx" 作为第二个子序列。
它们的乘积为 5 * 5 = 25 。

提示：
  2 <= s.length <= 12
  s 只含有小写英文字母。
*/

int maxProduct(string s)
{
	char t[16];
	int n = static_cast<int>(s.size());
	int X = 1 << n;
	vector<int> A(X);
	for (int i = 1; i < X; ++i) {
		int l = 0, r = 0, c = 0;
		// memset(t, 0, sizeof(t));
		for (int b = 0; b < n; ++b)
			if (i & (1 << b)) {
				++c;
				t[r++] = s[b];
			}
		for (--r; l < r; ++l, --r) {
			if (t[l] != t[r])
				break;
		}
		if (l >= r)
			A[i] = c;
	}
	for (int i = 1; i < X; ++i) {
		for (int b = 1; b < X; b <<= 1)
			A[i] = max(A[i], A[i & (~b)]);
	}
	int ans = 0;
	for (int i = 1; i < X; ++i)
		ans = max(ans, A[i] * A[X - 1 - i]);
	return ans;
}

int main()
{
	ToOut(maxProduct("leetcodecom"));
	ToOut(maxProduct("bb"));
	ToOut(maxProduct("accbcaxxcxx"));
}
