#include "leetcode.hpp"

/* 2420. 找到所有好下标

给你一个大小为 n 下标从 0 开始的整数数组 nums 和一个正整数 k 。

对于 k <= i < n - k 之间的一个下标 i ，如果它满足以下条件，我们就称它为一个 好 下标：

  下标 i 之前 的 k 个元素是 非递增的 。
  下标 i 之后 的 k 个元素是 非递减的 。

按 升序 返回所有好下标。

示例 1：
输入：nums = [2,1,1,1,3,4,1], k = 2
输出：[2,3]
解释：数组中有两个好下标：
- 下标 2 。子数组 [2,1] 是非递增的，子数组 [1,3] 是非递减的。
- 下标 3 。子数组 [1,1] 是非递增的，子数组 [3,4] 是非递减的。
注意，下标 4 不是好下标，因为 [4,1] 不是非递减的。

示例 2：
输入：nums = [2,1,1,2], k = 2
输出：[]
解释：数组中没有好下标。

提示：
  n == nums.length
  3 <= n <= 10^5
  1 <= nums[i] <= 10^6
  1 <= k <= n / 2
*/

vector<int> goodIndices(vector<int> const& nums, int k)
{
	int n = static_cast<int>(nums.size());
	vector<int> ans, inc(n), dec(n);
	for (int i = 1; i < n; ++i) {
		inc[i] = nums[i - 1] < nums[i];
		dec[i] = nums[i - 1] > nums[i];
		inc[i] += inc[i - 1];
		dec[i] += dec[i - 1];
	}
	for (int i = k, end = n - k; i < end; ++i)
		if (inc[i - k] == inc[i - 1] && dec[i + 1] == dec[i + k])
			ans.push_back(i);
	return ans;
}

int main()
{
	ToOut(goodIndices({2, 1, 1, 1, 3, 4, 1}, 2));
	ToOut(goodIndices({2, 1, 1, 2}, 2));
	ToOut(goodIndices({878724, 201541, 179099, 98437, 35765, 327555, 475851, 598885, 849470, 943442}, 4));
}
