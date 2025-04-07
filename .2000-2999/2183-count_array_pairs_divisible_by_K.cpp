#include "leetcode.hpp"

/* 2183. 统计可以被 K 整除的下标对数目

给你一个下标从 0 开始、长度为 n 的整数数组 nums 和一个整数 k ，返回满足下述条件的下标对 (i, j) 的数目：

  0 <= i < j <= n - 1 且
  nums[i] * nums[j] 能被 k 整除。

示例 1：
输入：nums = [1,2,3,4,5], k = 2
输出：7
解释：
共有 7 对下标的对应积可以被 2 整除：
(0, 1)、(0, 3)、(1, 2)、(1, 3)、(1, 4)、(2, 3) 和 (3, 4)
它们的积分别是 2、4、6、8、10、12 和 20 。
其他下标对，例如 (0, 2) 和 (2, 4) 的乘积分别是 3 和 15 ，都无法被 2 整除。

示例 2：
输入：nums = [1,2,3,4], k = 5
输出：0
解释：不存在对应积可以被 5 整除的下标对。

提示：

  1 <= nums.length <= 10^5
  1 <= nums[i], k <= 10^5
*/

int gcd(int a, int b)
{
	while (b) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

long long countPairs(vector<int> const& nums, int k)
{
	vector<pair<int, int>> factors;
	for (int lo = static_cast<int>(sqrt(k + 1.0)); lo > 0; --lo)
		if (k % lo == 0) {
			int hi = k / lo;
			factors.push_back({lo, 0});
			if (lo != hi)
				factors.push_back({hi, 0});
		}
	long long ans = 0;
	for (int i : nums) {
		int want = k / gcd(i, k);
		for (auto& j : factors) {
			if (j.first == want)
				ans += j.second;
			if (i % j.first == 0)
				j.second += 1;
		}
	}
	return ans;
}

int main()
{
	ToOut(countPairs({2, 3}, 1));
	ToOut(countPairs({1, 2, 3, 4, 5}, 2));
	ToOut(countPairs({1, 2, 3, 4}, 5));
}
