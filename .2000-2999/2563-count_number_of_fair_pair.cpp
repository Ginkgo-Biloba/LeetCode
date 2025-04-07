#include "leetcode.hpp"

/* 2563. 统计公平数对的数目

给你一个下标从 0 开始、长度为 n 的整数数组 nums ，和两个整数 lower 和 upper ，返回 公平数对的数目 。

如果 (i, j) 数对满足以下情况，则认为它是一个 公平数对 ：

0 <= i < j < n，且
lower <= nums[i] + nums[j] <= upper

示例 1：
输入：nums = [0,1,7,4,4,5], lower = 3, upper = 6
输出：6
解释：共计 6 个公平数对：(0,3)、(0,4)、(0,5)、(1,3)、(1,4) 和 (1,5) 。

示例 2：
输入：nums = [1,7,9,2,5], lower = 11, upper = 11
输出：1
解释：只有单个公平数对：(2,3) 。

提示：
  1 <= nums.length <= 10^5
  nums.length == n
  -10^9 <= nums[i] <= 10^9
  -10^9 <= lower <= upper <= 10^9
*/

long long countFairPairs(
	vector<int> A, int lower, int upper)
{
	int n = static_cast<int>(A.size());
	int L = n - 1, R = n - 1;
	long long ans = 0;
	std::sort(A.begin(), A.end());
	for (int i = 0; i < n; ++i) {
		while (L >= 0 && A[i] + A[L] >= lower) --L;
		while (R >= 0 && A[i] + A[R] > upper) --R;
		ans += min(R + 1, i) - min(L + 1, i);
	}
	return ans;
}

int main()
{
	ToOut(countFairPairs({0, 1, 7, 4, 4, 5}, 3, 6));
	ToOut(countFairPairs({1, 7, 9, 2, 5}, 11, 11));
	ToOut(countFairPairs({0, 0, 0}, 0, 0));
}
