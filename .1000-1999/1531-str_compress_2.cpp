﻿#include "leetcode.hpp"

/* 1531. 压缩字符串 II

行程长度编码 是一种常用的字符串压缩方法，它将连续的相同字符（重复 2 次或更多次）替换为字符和表示字符计数的数字（行程长度）。
例如，用此方法压缩字符串 "aabccc" ，将 "aa" 替换为 "a2" ，"ccc" 替换为` "c3" 。
因此压缩后的字符串变为 "a2bc3" 。

注意，本问题中，压缩时没有在单个字符后附加计数 '1' 。

给你一个字符串 s 和一个整数 k 。
你需要从字符串 s 中删除最多 k 个字符，以使 s 的行程长度编码长度最小。

请你返回删除最多 k 个字符后，s 行程长度编码的最小长度 。

示例 1：
输入：s = "aaabcccd", k = 2
输出：4
解释：
在不删除任何内容的情况下，压缩后的字符串是 "a3bc3d" ，长度为 6 。
最优的方案是删除 'b' 和 'd'，这样一来，压缩后的字符串为 "a3c3"，长度是 4。

示例 2：
输入：s = "aabbaa", k = 2
输出：2
解释：如果删去两个 'b' 字符，那么压缩后的字符串是长度为 2 的 "a4" 。

示例 3：
输入：s = "aaaaaaaaaaa", k = 0
输出：3
解释：由于 k 等于 0 ，不能删去任何字符。
压缩后的字符串是 "a11" ，长度为 3 。

提示：
  1 <= s.length <= 100
  0 <= k <= s.length
  s 仅包含小写英文字母
*/

// https://leetcode-cn.com/problems/string-compression-ii/solution/dong-tai-gui-hua-shi-jian-on3kong-jian-on2-by-newh/
// 抄的
class Solution {
	int calc(int x)
	{
		if (x <= 1) return x;
		if (x <= 9) return 2;
		if (x <= 99) return 3;
		return 4;
	}

public:
	int getLengthOfOptimalCompression(string s, int k)
	{
		int m = static_cast<int>(s.size());
		int n = m - k;
		vector<vector<int>> dp(m + 1, vector<int>(m + 1, 1000000));
		dp[m][n] = 0;
		for (int p = m - 1; p >= 0; --p)
			for (int c = 0; c <= n; ++c) {
				int q = p, same = 0;
				for (; q < m; ++q) {
					same += s[p] == s[q];
					if (same + c > n)
						break;
					dp[p][c] = min(dp[p][c],
						calc(same) + dp[q + 1][c + same]);
				}
				dp[p][c] = min(dp[p][c], dp[p + 1][c]);
			}
		return dp[0][0];
	}
};

int main()
{
	Solution s;
	ToOut(s.getLengthOfOptimalCompression("aaabcccd", 2));
	ToOut(s.getLengthOfOptimalCompression("aabbaa", 2));
	ToOut(s.getLengthOfOptimalCompression("aaaaaaaaaaa", 0));
}
