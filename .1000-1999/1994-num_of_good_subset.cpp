#include "leetcode.hpp"

/* 1994. 好子集的数目

给你一个整数数组 nums 。
如果 nums 的一个子集中，所有元素的乘积可以表示为一个或多个 互不相同的质数 的乘积，那么我们称它为 好子集 。

比方说，如果 nums = [1, 2, 3, 4] ：
    [2, 3] ，[1, 2, 3] 和 [1, 3] 是 好 子集，乘积分别为 6 = 2*3 ，6 = 2*3 和 3 = 3 。
    [1, 4] 和 [4] 不是 好 子集，因为乘积分别为 4 = 2*2 和 4 = 2*2 。

请你返回 nums 中不同的 好 子集的数目对 10^9 + 7 取余 的结果。

nums 中的 子集 是通过删除 nums 中一些（可能一个都不删除，也可能全部都删除）元素后剩余元素组成的数组。
如果两个子集删除的下标不同，那么它们被视为不同的子集。

示例 1：
输入：nums = [1,2,3,4]
输出：6
解释：好子集为：
- [1,2]：乘积为 2 ，可以表示为质数 2 的乘积。
- [1,2,3]：乘积为 6 ，可以表示为互不相同的质数 2 和 3 的乘积。
- [1,3]：乘积为 3 ，可以表示为质数 3 的乘积。
- [2]：乘积为 2 ，可以表示为质数 2 的乘积。
- [2,3]：乘积为 6 ，可以表示为互不相同的质数 2 和 3 的乘积。
- [3]：乘积为 3 ，可以表示为质数 3 的乘积。

示例 2：
输入：nums = [4,2,3,15]
输出：5
解释：好子集为：
- [2]：乘积为 2 ，可以表示为质数 2 的乘积。
- [2,3]：乘积为 6 ，可以表示为互不相同质数 2 和 3 的乘积。
- [2,15]：乘积为 30 ，可以表示为互不相同质数 2，3 和 5 的乘积。
- [3]：乘积为 3 ，可以表示为质数 3 的乘积。
- [15]：乘积为 15 ，可以表示为互不相同质数 3 和 5 的乘积。

提示：
  1 <= nums.length <= 10^5
  1 <= nums[i] <= 30
*/

class Solution {
	int64_t gcd(int64_t a, int64_t b)
	{
		int64_t t;
		while (b) {
			t = a % b;
			a = b;
			b = t;
		}
		return a;
	}

public:
	// https://leetcode-cn.com/problems/the-number-of-good-subsets/solution/hao-zi-ji-de-shu-mu-by-leetcode-solution-ky65/
	// 抄的
	int numberOfGoodSubsets(vector<int>& nums)
	{
		int const mod = static_cast<int>(1e9 + 7);
		int const prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
		int const N = 30;
		int freq[N + 1] = {0};
		vector<int> dp(1 << 10);
		dp[0] = 1;
		for (int i : nums)
			freq[i] += 1;
		for (int i = 0; i < freq[1]; ++i)
			dp[0] = dp[0] * 2 % mod;
		for (int i = 2; i <= N; ++i) {
			if (!freq[i])
				continue;
			// 检查 i 的每个质因数是否均不超过 1 个
			int ok = 1, sub = 0;
			for (int j = 0; ok && j < 10; ++j) {
				int p = prime[j];
				ok = i % (p * p);
				if (i % p == 0)
					sub |= (1 << j);
			}
			if (!ok)
				continue;
			for (int m = 1 << 10; --m;)
				if ((m & sub) == sub) {
					int64_t tmp = static_cast<int64_t>(dp[m ^ sub]) * freq[i];
					dp[m] = static_cast<int>((dp[m] + tmp) % mod);
				}
		}
		int ret = 0;
		for (int i = 1 << 10; --i;)
			ret = (ret + dp[i]) % mod;
		return ret;
	}

	// https://leetcode-cn.com/problems/the-number-of-good-subsets/solution/cfei-dong-tai-gui-hua-zuo-fa-by-kujo-jol-fhp9/
	// 抄的
	int numberOfGoodSubsets2(vector<int>& nums)
	{
		int64_t const mod = static_cast<int>(1e9 + 7);
		int const A[18] = {2, 3, 5, 6, 7, 10, 11, 13, 14, 15, 17, 19, 21, 22, 23, 26, 29, 30};
		int count[31] = {0};
		int64_t ret = 0;
		for (int i : nums)
			count[i] += 1;
		for (int i = 1 << 18; --i;) {
			bool ok = true;
			int64_t prod = 1;
			int64_t total = 1;
			for (int b = 18; ok && (b--);)
				if ((i >> b) & 1) {
					ok = gcd(prod, A[b]) == 1;
					prod *= A[b];
					total = (total * count[A[b]]) % mod;
				}
			if (ok)
				ret = (ret + total) % mod;
		}
		// 对于每一个1，我们可以选择或者不选择，所以每次乘2.
		for (int i = count[1]; i--;)
			ret = (ret * 2) % mod;
		return static_cast<int>(ret);
	}
};

int main()
{
	Solution s;
	vector<int>
		a = {1, 2, 3, 4},
		b = {4, 2, 3, 15};
	ToOut(s.numberOfGoodSubsets(a));
	ToOut(s.numberOfGoodSubsets(b));
}
