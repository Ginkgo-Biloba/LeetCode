#include "leetcode.hpp"

/* 2333. 最小差值平方和

给你两个下标从 0 开始的整数数组 nums1 和 nums2 ，长度为 n 。

数组 nums1 和 nums2 的 差值平方和 定义为所有满足 0 <= i < n 的 (nums1[i] - nums2[i])^2 之和。

同时给你两个正整数 k1 和 k2 。
你可以将 nums1 中的任意元素 +1 或者 -1 至多 k1 次。
类似的，你可以将 nums2 中的任意元素 +1 或者 -1 至多 k2 次。

请你返回修改数组 nums1 至多 k1 次且修改数组 nums2 至多 k2 次后的最小 差值平方和 。

注意：你可以将数组中的元素变成 负 整数。

示例 1：
输入：nums1 = [1,2,3,4], nums2 = [2,10,20,19], k1 = 0, k2 = 0
输出：579
解释：nums1 和 nums2 中的元素不能修改，因为 k1 = 0 和 k2 = 0 。
差值平方和为：(1 - 2)2 + (2 - 10)2 + (3 - 20)2 + (4 - 19)2 = 579 。

示例 2：
输入：nums1 = [1,4,10,12], nums2 = [5,8,6,9], k1 = 1, k2 = 1
输出：43
解释：一种得到最小差值平方和的方式为：
- 将 nums1[0] 增加一次。
- 将 nums2[2] 增加一次。
最小差值平方和为：
(2 - 5)2 + (4 - 8)2 + (10 - 7)2 + (12 - 9)2 = 43 。
注意，也有其他方式可以得到最小差值平方和，但没有得到比 43 更小答案的方案。

提示：
  n == nums1.length == nums2.length
  1 <= n <= 10^5
  0 <= nums1[i], nums2[i] <= 10^5
  0 <= k1, k2 <= 10^9
*/

long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2)
{
	int n = static_cast<int>(nums1.size());
	vector<int64_t> dif(n);
	int64_t aks = k1 + k2, sum = 0;
	for (int i = 0; i < n; ++i) {
		dif[i] = abs(nums1[i] - nums2[i]);
		sum += dif[i] * dif[i];
	}
	if (sum <= aks)
		return 0;
	std::sort(dif.begin(), dif.end());
	vector<pair<int64_t, int64_t>> Q;
	// 多 push 一个 0 可以不用是否有判断 B
	Q.push_back({0, 0});
	for (int h = 0, i = 1; i <= n; ++i)
		if (i == n || dif[h] != dif[i]) {
			Q.push_back({dif[h], i - h});
			h = i;
		}
	while (Q.size() > 1 && aks > 0) {
		auto A = Q.back();
		Q.pop_back();
		auto B = Q.back();
		Q.pop_back();
		int64_t want = (A.first - B.first) * A.second;
		int64_t have = min(aks, want);
		aks -= have;
		if (want == have) {
			B.second += A.second;
			Q.push_back(B);
			continue;
		}
		int64_t dec = have / A.second;
		int64_t more = have - dec * A.second;
		Q.push_back(B);
		Q.push_back({A.first - dec, A.second - more});
		Q.push_back({A.first - dec - 1, more});
	}
	sum = 0;
	for (auto A : Q)
		sum += A.first * A.first * A.second;
	return sum;
}

int main()
{
	vector<int>
		n1 = {1, 2, 3, 4},
		n2 = {2, 10, 20, 19},
		n3 = {1, 4, 10, 12},
		n4 = {5, 8, 6, 9};
	ToOut(minSumSquareDiff(n1, n2, 0, 0));
	ToOut(minSumSquareDiff(n3, n4, 1, 1));
}
