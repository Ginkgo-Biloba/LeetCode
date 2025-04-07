#include "leetcode.hpp"

/* 1856. 子数组最小乘积的最大值

一个数组的 最小乘积 定义为这个数组中 最小值 乘以 数组的 和 。
  比方说，数组 [3,2,5] （最小值是 2）的最小乘积为 2 * (3+2+5) = 2 * 10 = 20 。

给你一个正整数数组 nums ，请你返回 nums 任意 非空子数组 的最小乘积 的 最大值 。
由于答案可能很大，请你返回答案对  10^9 + 7 取余 的结果。

请注意，最小乘积的最大值考虑的是取余操作 之前 的结果。
题目保证最小乘积的最大值在 不取余 的情况下可以用 64 位有符号整数 保存。

子数组 定义为一个数组的 连续 部分。

示例 1：
输入：nums = [1,2,3,2]
输出：14
解释：最小乘积的最大值由子数组 [2,3,2] （最小值是 2）得到。
2 * (2+3+2) = 2 * 7 = 14 。

示例 2：
输入：nums = [2,3,3,1,2]
输出：18
解释：最小乘积的最大值由子数组 [3,3] （最小值是 3）得到。
3 * (3+3) = 3 * 6 = 18 。

示例 3：
输入：nums = [3,1,5,6,4,2]
输出：60
解释：最小乘积的最大值由子数组 [5,6,4] （最小值是 4）得到。
4 * (5+6+4) = 4 * 15 = 60 。

提示：
  1 <= nums.length <= 10^5
  1 <= nums[i] <= 10^7
*/

int maxSumMinProduct(vector<int>& A)
{
	int len = static_cast<int>(A.size());
	vector<int> L(len), R(len);
	vector<pair<int, int>> S;
	S.clear();
	S.push_back({-1, -1});
	for (int i = 0; i < len; ++i) {
		while (S.back().second >= A[i])
			S.pop_back();
		L[i] = S.back().first;
		S.push_back({i, A[i]});
	}
	S.clear();
	S.push_back({len, -1});
	for (int i = len - 1; i >= 0; --i) {
		while (S.back().second >= A[i])
			S.pop_back();
		R[i] = S.back().first;
		S.push_back({i, A[i]});
	}
	vector<int64_t> B(len + 1);
	for (int i = 0; i < len; ++i)
		B[i + 1] = B[i] + A[i];
	int64_t ans = 0;
	for (int i = 0; i < len; ++i) {
		int64_t cur = A[i];
		cur *= B[R[i]] - B[L[i] + 1];
		ans = max(ans, cur);
	}
	ans %= static_cast<int64_t>(1e9 + 7);
	return static_cast<int>(ans);
}

int main()
{
}
