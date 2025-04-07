#include "leetcode.hpp"

/* 2014. 重复 K 次的最长子序列

给你一个长度为 n 的字符串 s ，和一个整数 k 。

请你找出字符串 s 中 重复 k 次的 最长子序列 。

子序列 是由其他字符串删除某些（或不删除）字符派生而来的一个字符串。

如果 seq * k 是 s 的一个子序列，其中 seq * k 表示一个由 seq 串联 k 次构造的字符串，那么就称 seq 是字符串 s 中一个 重复 k 次 的子序列。

  举个例子，"bba" 是字符串 "bababcba" 中的一个重复 2 次的子序列，因为字符串 "bbabba" 是由 "bba" 串联 2 次构造的，而 "bbabba" 是字符串 "bababcba" 的一个子序列。

返回字符串 s 中 重复 k 次的最长子序列。
如果存在多个满足的子序列，则返回 字典序最大 的那个。
如果不存在这样的子序列，返回一个 空 字符串。

示例 1：
https://assets.leetcode.com/uploads/2021/08/30/longest-subsequence-repeat-k-times.png
输入：s = "letsleetcode", k = 2
输出："let"
解释：存在两个最长子序列重复 2 次：let" 和 "ete" 。
"let" 是其中字典序最大的一个。

示例 2：
输入：s = "bb", k = 2
输出："b"
解释：重复 2 次的最长子序列是 "b" 。

示例 3：
输入：s = "ab", k = 2
输出：""
解释：不存在重复 2 次的最长子序列。返回空字符串。

提示：
  n == s.length
  2 <= k <= 2000
  2 <= n < k * 8
  s 由小写英文字母组成
*/

// https://leetcode.cn/problems/longest-subsequence-repeated-k-times/comments/
// 抄的
class Solution {
	string cand;

	void shrink(string& s, int k)
	{
		int C[128] = {0};
		int n = static_cast<int>(s.size());
		for (int i = 0; i < n; ++i)
			C[(int)s[i]] += 1;
		for (int i = 'a'; i <= 'z'; ++i) {
			if (C[i] >= k)
				cand.push_back(static_cast<char>(i));
		}
		int l = 0, r;
		for (; l < n; ++l) {
			if (C[(int)s[l]] < k)
				break;
		}
		for (r = l + 1; r < n; ++r) {
			if (C[(int)s[r]] >= k)
				s[l++] = s[r];
		}
		s.resize(l);
	}

	int check(string const& s, string const& p)
	{
		int n = static_cast<int>(s.size());
		int m = static_cast<int>(p.size());
		if (m == 0)
			return n;
		int q = 0, k = 0;
		for (int t = 0; t < n; ++t)
			if (s[t] == p[q]) {
				if (++q == m)
					++k, q = 0;
			}
		return k;
	}

public:
	string longestSubsequenceRepeatedK(string s, int k)
	{
		shrink(s, k);
		string ans;
		vector<string> cur, pre;
		cur.push_back("");
		while (!cur.empty()) {
			ans = cur.back();
			pre.swap(cur);
			cur.clear();
			for (string& p : pre)
				for (char c : cand) {
					string q = p + c;
					if (check(s, q) >= k)
						cur.push_back(std::move(q));
				}
		}
		return ans;
	}
};

int main()
{
	Solution s;
	ToOut(s.longestSubsequenceRepeatedK("letsleetcode", 2));
	ToOut(s.longestSubsequenceRepeatedK("bb", 2));
	ToOut(s.longestSubsequenceRepeatedK("ab", 2));
}
