#include "leetcode.hpp"

/* 2233. K 次增加后的最大乘积

给你一个非负整数数组 nums 和一个整数 k 。
每次操作，你可以选择 nums 中 任一 元素并将它 增加 1 。

请你返回 至多 k 次操作后，能得到的 nums的 最大乘积 。
由于答案可能很大，请你将答案对 10^9 + 7 取余后返回。

示例 1：
输入：nums = [0,4], k = 5
输出：20
解释：将第一个数增加 5 次。
得到 nums = [5, 4] ，乘积为 5 * 4 = 20 。
可以证明 20 是能得到的最大乘积，所以我们返回 20 。
存在其他增加 nums 的方法，也能得到最大乘积。

示例 2：
输入：nums = [6,3,3,2], k = 2
输出：216
解释：将第二个数增加 1 次，将第四个数增加 1 次。
得到 nums = [6, 4, 3, 3] ，乘积为 6 * 4 * 3 * 3 = 216 。
可以证明 216 是能得到的最大乘积，所以我们返回 216 。
存在其他增加 nums 的方法，也能得到最大乘积。

提示：
  1 <= nums.length, k <= 10^5
  0 <= nums[i] <= 10^6
*/

int maximumProduct(vector<int> nums, int k)
{
	vector<pair<int, int>> valcnt;
	std::sort(nums.begin(), nums.end());
	for (size_t i = 0; i < nums.size();) {
		size_t r = i + 1;
		for (; r < nums.size(); ++r)
			if (nums[i] != nums[r])
				break;
		valcnt.emplace_back(nums[i], static_cast<int>(r - i));
		i = r;
	}
	std::sort(valcnt.begin(), valcnt.end(), std::greater<>());
	while (k) {
		pair<int, int> lo = valcnt.back(), hi = {-1, 0};
		valcnt.pop_back();
		int val = k;
		if (valcnt.size()) {
			hi = valcnt.back();
			val = min(k, (hi.first - lo.first) * lo.second);
		}
		k -= val;
		int d = val / lo.second;
		int r = val % lo.second;
		if (lo.first + d == hi.first)
			valcnt.back().second += lo.second;
		else {
			valcnt.emplace_back(lo.first + d + 1, r);
			valcnt.emplace_back(lo.first + d, lo.second - r);
		}
	}
	long long ans = 1;
	long long const mod = static_cast<long long>(1e9 + 7);
	for (auto& it : valcnt) {
		for (int i = 0; i < it.second; ++i)
			ans = ans * it.first % mod;
	}
	return static_cast<int>(ans);
}

int main()
{
	ToOut(maximumProduct({0, 4}, 5));
	ToOut(maximumProduct({6, 3, 3, 2}, 2));
}
