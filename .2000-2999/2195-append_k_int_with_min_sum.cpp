#include "leetcode.hpp"

/* 2195. 向数组中追加 K 个整数

给你一个整数数组 nums 和一个整数 k 。
请你向 nums 中追加 k 个 未 出现在 nums 中的、互不相同 的 正 整数，并使结果数组的元素和 最小 。

返回追加到 nums 中的 k 个整数之和。

示例 1：

输入：nums = [1,4,25,10,25], k = 2
输出：5
解释：在该解法中，向数组中追加的两个互不相同且未出现的正整数是 2 和 3 。
nums 最终元素和为 1 + 4 + 25 + 10 + 25 + 2 + 3 = 70 ，这是所有情况中的最小值。
所以追加到数组中的两个整数之和是 2 + 3 = 5 ，所以返回 5 。

示例 2：

输入：nums = [5,6], k = 6
输出：25
解释：在该解法中，向数组中追加的两个互不相同且未出现的正整数是 1 、2 、3 、4 、7 和 8 。
nums 最终元素和为 5 + 6 + 1 + 2 + 3 + 4 + 7 + 8 = 36 ，这是所有情况中的最小值。
所以追加到数组中的两个整数之和是 1 + 2 + 3 + 4 + 7 + 8 = 25 ，所以返回 25 。

提示：
  1 <= nums.length <= 10^5
  1 <= nums[i], k <= 10^9
*/

long long minimalKSum(vector<int> nums, int K)
{
	long long cur = 1, ans = 0, kll = K;
	std::sort(nums.begin(), nums.end());
	for (size_t i = 0; kll > 0 && i < nums.size(); ++i) {
		long long n = max(0ll, min(nums[i] - cur, kll));
		ans += n * (n - 1) / 2 + cur * n;
		kll -= n;
		cur = nums[i] + 1;
	}
	return ans + kll * (kll - 1) / 2 + cur * kll;
}

int main()
{
	ToOut(minimalKSum({96, 44, 99, 25, 61, 84, 88, 18, 19, 33, 60, 86, 52, 19, 32, 47, 35, 50, 94, 17, 29, 98, 22, 21, 72, 100, 40, 84}, 35));
	ToOut(minimalKSum({1, 4, 25, 10, 25}, 2));
	ToOut(minimalKSum({5, 6}, 6));
}
