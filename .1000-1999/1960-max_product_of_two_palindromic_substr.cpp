#include "leetcode.hpp"

/* 1960. 两个回文子字符串长度的最大乘积

给你一个下标从 0 开始的字符串 s ，你需要找到两个 不重叠的回文 子字符串，它们的长度都必须为 奇数 ，使得它们长度的乘积最大。

更正式地，你想要选择四个整数 i ，j ，k ，l ，使得 0 <= i <= j < k <= l < s.length ，且子字符串 s[i...j] 和 s[k...l] 都是回文串且长度为奇数。
s[i...j] 表示下标从 i 到 j 且 包含 两端下标的子字符串。

请你返回两个不重叠回文子字符串长度的 最大 乘积。

回文字符串 指的是一个从前往后读和从后往前读一模一样的字符串。
子字符串 指的是一个字符串中一段连续字符。

示例 1：
输入：s = "ababbb"
输出：9
解释：子字符串 "aba" 和 "bbb" 为奇数长度的回文串。乘积为 3 * 3 = 9 。

示例 2：
输入：s = "zaaaxbbby"
输出：9
解释：子字符串 "aaa" 和 "bbb" 为奇数长度的回文串。乘积为 3 * 3 = 9 。

提示：
  2 <= s.length <= 10^5
  s 只包含小写英文字母。
*/

class Solution {
	// 抄的
	vector<int> manachers(string const& A)
	{
		int n = static_cast<int>(A.size());
		vector<int> M(n), L(n, 1);
		for (int i = 0, l = 0, r = -1; i < n; ++i) {
			int k = 1;
			if (i <= r)
				k = min(M[l + r - i], r - i + 1);
			while (0 <= i - k && i + k < n && A[i - k] == A[i + k]) {
				L[i + k] = 2 * k + 1;
				k += 1;
			}
			M[i] = k--;
			if (i + k > r) {
				l = i - k;
				r = i + k;
			}
		}
		for (int i = 1; i < n; ++i)
			L[i] = max(L[i - 1], L[i]);
		return L;
	}

public:
	long long maxProduct(string A)
	{
		int n = static_cast<int>(A.size());
		vector<int> L = manachers(A);
		reverse(A.begin(), A.end());
		vector<int> R = manachers(A);
		long long ans = 1;
		for (int i = 0; i < n - 1; ++i)
			ans = max(ans, static_cast<long long>(L[i]) * R[n - 2 - i]);
		return ans;
	}
};

int main()
{
	Solution s;
	ToOut(s.maxProduct("ababbb"));
	ToOut(s.maxProduct("zaaaxbbby"));
}
