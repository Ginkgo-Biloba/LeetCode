#include "leetcode.hpp"

/* 2407. 最长递增子序列 II

给你一个整数数组 nums 和一个整数 k 。

找到 nums 中满足以下要求的最长子序列：

  子序列 严格递增
  子序列中相邻元素的差值 不超过 k 。

请你返回满足上述要求的 最长子序列 的长度。

子序列 是从一个数组中删除部分元素后，剩余元素不改变顺序得到的数组。

示例 1：
输入：nums = [4,2,1,4,3,4,5,8,15], k = 3
输出：5
解释：
满足要求的最长子序列是 [1,3,4,5,8] 。
子序列长度为 5 ，所以我们返回 5 。
注意子序列 [1,3,4,5,8,15] 不满足要求，因为 15 - 8 = 7 大于 3 。

示例 2：
输入：nums = [7,4,5,1,8,12,4,7], k = 5
输出：4
解释：
满足要求的最长子序列是 [4,5,8,12] 。
子序列长度为 4 ，所以我们返回 4 。

示例 3：
输入：nums = [1,5], k = 1
输出：1
解释：
满足要求的最长子序列是 [1] 。
子序列长度为 1 ，所以我们返回 1 。

提示：
  1 <= nums.length <= 10^5
  1 <= nums[i], k <= 10^5
*/

#include <numeric>

int lengthOfLIS(vector<int>& nums, int k)
{
	int const cbit = 9, fbit = 8;
	vector<int> coarse(1 << cbit), fine(1 << (cbit + fbit));
	int ans = 0;
	for (int val : nums) {
		int prefix = 0;
		int start = max(0, val - k);
		for (int h = 0; h < (1 << cbit); ++h) {
			int lo = max(start, h << fbit);
			int hi = min(val, (h + 1) << fbit);
			int len = hi - lo;
			if (len == (1 << fbit))
				prefix = max(prefix, coarse[h]);
			else
				for (int i = lo; i < hi; ++i)
					prefix = max(prefix, fine[i]);
		}
		fine[val] = max(fine[val], prefix + 1);
		ans = max(ans, fine[val]);
		int fidx = val >> fbit;
		coarse[fidx] = max(coarse[fidx], fine[val]);
	}
	return ans;
}

int main()
{
	vector<int>
		a = {4, 2, 1, 4, 3, 4, 5, 8, 15},
		b = {7, 4, 5, 1, 8, 12, 4, 7},
		c = {1, 5},
		d = {4, 1, 5, 2, 6, 7, 8},
		e = {1, 3, 3, 4, 4},
		f(100000);
	std::iota(f.begin(), f.end(), 1);
	ToOut(lengthOfLIS(f, 1));
	ToOut(lengthOfLIS(a, 3));
	ToOut(lengthOfLIS(b, 5));
	ToOut(lengthOfLIS(c, 1));
	ToOut(lengthOfLIS(d, 2));
	ToOut(lengthOfLIS(e, 1));
}
