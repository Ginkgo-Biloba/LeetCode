﻿#include "leetcode.hpp"

/* 960. 删列造序 III

给定由 N 个小写字母字符串组成的数组 A，其中每个字符串长度相等。

选取一个删除索引序列，对于 A 中的每个字符串，删除对应每个索引处的字符。

比如，有 A = ["babca","bbazb"]，删除索引序列 {0, 1, 4}，删除后 A 为["bc","az"]。

假设，我们选择了一组删除索引 D，那么在执行删除操作之后，最终得到的数组的行中的每个元素都是按字典序排列的。

清楚起见，A[0] 是按字典序排列的（即，A[0][0] <= A[0][1] <= ... <= A[0][A[0].length - 1]），A[1] 是按字典序排列的（即，A[1][0] <= A[1][1] <= ... <= A[1][A[1].length - 1]），依此类推。

请你返回 D.length 的最小可能值。

示例 1：
输入：["babca","bbazb"]
输出：3
解释：
删除 0、1 和 4 这三列后，最终得到的数组是 A = ["bc", "az"]。
这两行是分别按字典序排列的（即，A[0][0] <= A[0][1] 且 A[1][0] <= A[1][1]）。
注意，A[0] > A[1] —— 数组 A 不一定是按字典序排列的。

示例 2：
输入：["edcba"]
输出：4
解释：如果删除的列少于 4 列，则剩下的行都不会按字典序排列。

示例 3：
输入：["ghi","def","abc"]
输出：0
解释：所有行都已按字典序排列。

提示：
  1 <= A.length <= 100
  1 <= A[i].length <= 100
*/

class Solution {
public:
	bool all_less(vector<string>& A, int m, int n)
	{
		size_t const len = A.size();
		for (size_t i = 0; i < len; ++i) {
			if (A[i][m] > A[i][n])
				return false;
		}
		return true;
	}

	int minDeletionSize(vector<string>& A)
	{
		int str_len = static_cast<int>(A[0].size());
		vector<int> dp(str_len);
		int max_len = 1;
		dp[0] = 1;

		for (int right = 1; right < str_len; ++right) {
			int cur_len = 1;
			for (int left = 0; left < right; ++left) {
				if (all_less(A, left, right))
					cur_len = std::max(cur_len, dp[left] + 1);
			}
			dp[right] = cur_len;
			if (max_len < cur_len)
				max_len = cur_len;
		}

		return str_len - max_len;
	}
};

int main()
{
	vector<string>
		a = {"babca", "bbazb"},
		b = {"edcba"},
		c = {"ghi", "def", "abc"};
	Solution s;
	ToOut(s.minDeletionSize(a));
	ToOut(s.minDeletionSize(b));
	ToOut(s.minDeletionSize(c));
}
