#include "leetcode.hpp"

/* 1879. 两个数组最小的异或值之和

给你两个整数数组 nums1 和 nums2 ，它们长度都为 n 。

两个数组的 异或值之和 为 (nums1[0] XOR nums2[0]) + (nums1[1] XOR nums2[1]) + ... + (nums1[n - 1] XOR nums2[n - 1]) （下标从 0 开始）。
  比方说，[1,2,3] 和 [3,2,1] 的 异或值之和 等于 (1 XOR 3) + (2 XOR 2) + (3 XOR 1) = 2 + 0 + 2 = 4 。

请你将 nums2 中的元素重新排列，使得 异或值之和 最小 。

请你返回重新排列之后的 异或值之和 。

示例 1：
输入：nums1 = [1,2], nums2 = [2,3]
输出：2
解释：将 nums2 重新排列得到 [3,2] 。
异或值之和为 (1 XOR 3) + (2 XOR 2) = 2 + 0 = 2 。

示例 2：
输入：nums1 = [1,0,3], nums2 = [5,3,4]
输出：8
解释：将 nums2 重新排列得到 [5,4,3] 。
异或值之和为 (1 XOR 5) + (0 XOR 4) + (3 XOR 3) = 4 + 4 + 0 = 8 。

提示：
  n == nums1.length
  n == nums2.length
  1 <= n <= 14
  0 <= nums1[i], nums2[i] <= 10^7
*/

class Solution {
public:
	int minimumXORSum(vector<int>& A, vector<int>& B)
	{
		int len = static_cast<int>(A.size());
		int limit = 1 << len;
		vector<int> dp(limit, INT_MAX);
		dp[0] = 0;
		for (int i = 1; i < limit; ++i)
			for (int b = 0; b < len; ++b)
				if (i & (1 << b)) {
					int a = popcount(i) - 1;
					int h = i - (1 << b);
					dp[i] = min(dp[i], dp[h] + (A[a] ^ B[b]));
				}
		return dp[limit - 1];
	}
};

int main()
{
	Solution s;
	vector<int>
		a = {2486049, 4395362, 7707310, 8834753, 2726898, 2325653, 2316899, 7393406, 6058081, 5196941, 6723570, 4034813, 1943421, 3459280},
		b = {5125370, 1144646, 1784851, 3818824, 6660686, 5391696, 8260455, 1677288, 3133334, 754650, 928502, 390631, 3633236, 582394};
	ToOut(s.minimumXORSum(a, b));
}
