#include "leetcode.hpp"

/* 2449. 使数组相似的最少操作次数

给你两个正整数数组 nums 和 target ，两个数组长度相等。

在一次操作中，你可以选择两个 不同 的下标 i 和 j ，其中 0 <= i, j < nums.length ，并且：

令 nums[i] = nums[i] + 2 且
令 nums[j] = nums[j] - 2 。
如果两个数组中每个元素出现的频率相等，我们称两个数组是 相似 的。

请你返回将 nums 变得与 target 相似的最少操作次数。
测试数据保证 nums 一定能变得与 target 相似。

示例 1：
输入：nums = [8,12,6], target = [2,14,10]
输出：2
解释：可以用两步操作将 nums 变得与 target 相似：
- 选择 i = 0 和 j = 2 ，nums = [10,12,4] 。
- 选择 i = 1 和 j = 2 ，nums = [10,14,2] 。
2 次操作是最少需要的操作次数。

示例 2：
输入：nums = [1,2,5], target = [4,1,3]
输出：1
解释：一步操作可以使 nums 变得与 target 相似：
- 选择 i = 1 和 j = 2 ，nums = [1,4,3] 。

示例 3：
输入：nums = [1,1,1,1,1], target = [1,1,1,1,1]
输出：0
解释：数组 nums 已经与 target 相似。

提示：
  n == nums.length == target.length
  1 <= n <= 10^5
  1 <= nums[i], target[i] <= 10^6
  nums 一定可以变得与 target 相似。
*/

long long make(int evenodd,
	vector<int> const& src, vector<int> const& dst)
{
	vector<int> S, D;
	int len = static_cast<int>(src.size());
	for (int i = 0; i < len; ++i) {
		if (src[i] % 2 == evenodd)
			S.push_back(src[i]);
		if (dst[i] % 2 == evenodd)
			D.push_back(dst[i]);
	}
	long long ans = 0;
	std::sort(S.begin(), S.end());
	std::sort(D.begin(), D.end());
	len = static_cast<int>(S.size());
	for (int i = 0; i < len; ++i) {
		if (S[i] < D[i])
			ans += (D[i] - S[i]) / 2;
	}
	return ans;
}

long long makeSimilar(
	vector<int> const& src, vector<int> const& dst)
{
	return make(0, src, dst) + make(1, src, dst);
}

int main()
{
	ToOut(makeSimilar({8, 12, 6}, {2, 14, 10}));
	ToOut(makeSimilar({1, 2, 5}, {4, 1, 3}));
	ToOut(makeSimilar({1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}));
}
