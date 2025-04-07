#include "leetcode.hpp"

/* 2499. 让数组不相等的最小总代价

给你两个下标从 0 开始的整数数组 nums1 和 nums2 ，两者长度都为 n 。

每次操作中，你可以选择交换 nums1 中任意两个下标处的值。操作的 开销 为两个下标的 和 。

你的目标是对于所有的 0 <= i <= n - 1 ，都满足 nums1[i] != nums2[i] ，你可以进行 任意次 操作，请你返回达到这个目标的 最小 总代价。

请你返回让 nums1 和 nums2 满足上述条件的 最小总代价 ，如果无法达成目标，返回 -1 。

示例 1：
输入：nums1 = [1,2,3,4,5], nums2 = [1,2,3,4,5]
输出：10
解释：
实现目标的其中一种方法为：
- 交换下标为 0 和 3 的两个值，代价为 0 + 3 = 3 。现在 nums1 = [4,2,3,1,5] 。
- 交换下标为 1 和 2 的两个值，代价为 1 + 2 = 3 。现在 nums1 = [4,3,2,1,5] 。
- 交换下标为 0 和 4 的两个值，代价为 0 + 4 = 4 。现在 nums1 = [5,3,2,1,4] 。
最后，对于每个下标 i ，都有 nums1[i] != nums2[i] 。总代价为 10 。
还有别的交换值的方法，但是无法得到代价和小于 10 的方案。

示例 2：
输入：nums1 = [2,2,2,1,3], nums2 = [1,2,2,3,3]
输出：10
解释：
实现目标的一种方法为：
- 交换下标为 2 和 3 的两个值，代价为 2 + 3 = 5 。现在 nums1 = [2,2,1,2,3] 。
- 交换下标为 1 和 4 的两个值，代价为 1 + 4 = 5 。现在 nums1 = [2,3,1,2,2] 。
总代价为 10 ，是所有方案中的最小代价。

示例 3：
输入：nums1 = [1,2,2], nums2 = [1,2,2]
输出：-1
解释：
不管怎么操作，都无法满足题目要求。
所以返回 -1 。

提示：
  n == nums1.length == nums2.length
  1 <= n <= 10^5
  1 <= nums1[i], nums2[i] <= n
*/

// https://leetcode.cn/problems/minimum-total-cost-to-make-arrays-unequal/solutions/2015672/li-yong-nums10-tan-xin-zhao-bu-deng-yu-z-amvw/
// 抄的
long long minimumTotalCost(
	vector<int> const& A, vector<int> const& B)
{
	int n = static_cast<int>(A.size());
	long long ans = 0;
	int swap = 0, count = 0, mode = -1;
	vector<int> freq(n + 1);
	for (int i = 0; i < n; ++i)
		if (A[i] == B[i]) {
			int x = A[i];
			ans += i;
			++swap;
			++freq[x];
			if (freq[x] > count) {
				mode = x;
				count = freq[x];
			}
		}

	for (int i = 0; i < n && count * 2 > swap; ++i) {
		int x = A[i], y = B[i];
		if (x != y && x != mode && y != mode) {
			ans += i;
			++swap;
		}
	}
	return count * 2 > swap ? -1 : ans;
}

int main()
{
	ToOut(minimumTotalCost({1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}));
	ToOut(minimumTotalCost({2, 2, 2, 1, 3}, {1, 2, 2, 3, 3}));
	ToOut(minimumTotalCost({1, 2, 2}, {1, 2, 2}));
}
