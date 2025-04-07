#include "leetcode.hpp"

/* 2348. 全 0 子数组的数目

给你一个整数数组 nums ，返回全部为 0 的 子数组 数目。

子数组 是一个数组中一段连续非空元素组成的序列。

示例 1：
输入：nums = [1,3,0,0,2,0,0,4]
输出：6
解释：
子数组 [0] 出现了 4 次。
子数组 [0,0] 出现了 2 次。
不存在长度大于 2 的全 0 子数组，所以我们返回 6 。

示例 2：
输入：nums = [0,0,0,2,0,0]
输出：9
解释：
子数组 [0] 出现了 5 次。
子数组 [0,0] 出现了 3 次。
子数组 [0,0,0] 出现了 1 次。
不存在长度大于 3 的全 0 子数组，所以我们返回 9 。

示例 3：
输入：nums = [2,10,2019]
输出：0
解释：没有全 0 子数组，所以我们返回 0 。

提示：
  1 <= nums.length <= 10^5
  -10^9 <= nums[i] <= 10^9
*/

long long zeroFilledSubarray(vector<int> const& nums)
{
	int n = static_cast<int>(nums.size());
	long long ans = 0;
	for (int h = n, i = 0; i <= n; ++i) {
		if (i == n || nums[i] != 0) {
			long long x = i - h;
			if (x > 0)
				ans += x * (x + 1) / 2;
			h = n;
		} else
			h = min(h, i);
	}
	return ans;
}

int main()
{
	ToOut(zeroFilledSubarray({1, 3, 0, 0, 2, 0, 0, 4}));
	ToOut(zeroFilledSubarray({0, 0, 0, 2, 0, 0}));
	ToOut(zeroFilledSubarray({2, 10, 2019}));
	ToOut(zeroFilledSubarray({0, 1, 0, 0, 1, 0, 0, 0}));
}
