#include "leetcode.hpp"

/* 2040. 两个有序数组的第 K 小乘积

给你两个 从小到大排好序 且下标从 0 开始的整数数组 nums1 和 nums2 以及一个整数 k ，请你返回第 k （从 1 开始编号）小的 nums1[i] * nums2[j] 的乘积，其中 0 <= i < nums1.length 且 0 <= j < nums2.length 。

示例 1：
输入：nums1 = [2,5], nums2 = [3,4], k = 2
输出：8
解释：第 2 小的乘积计算如下：
- nums1[0] * nums2[0] = 2 * 3 = 6
- nums1[0] * nums2[1] = 2 * 4 = 8
第 2 小的乘积为 8 。

示例 2：
输入：nums1 = [-4,-2,0,3], nums2 = [2,4], k = 6
输出：0
解释：第 6 小的乘积计算如下：
- nums1[0] * nums2[1] = (-4) * 4 = -16
- nums1[0] * nums2[0] = (-4) * 2 = -8
- nums1[1] * nums2[1] = (-2) * 4 = -8
- nums1[1] * nums2[0] = (-2) * 2 = -4
- nums1[2] * nums2[0] = 0 * 2 = 0
- nums1[2] * nums2[1] = 0 * 4 = 0
第 6 小的乘积为 0 。

示例 3：
输入：nums1 = [-2,-1,0,1,2], nums2 = [-3,-1,2,4,5], k = 3
输出：-6
解释：第 3 小的乘积计算如下：
- nums1[0] * nums2[4] = (-2) * 5 = -10
- nums1[0] * nums2[3] = (-2) * 4 = -8
- nums1[4] * nums2[0] = 2 * (-3) = -6
第 3 小的乘积为 -6 。

提示：
  1 <= nums1.length, nums2.length <= 5 * 10^4
  -10^5 <= nums1[i], nums2[j] <= 10^5
  1 <= k <= nums1.length * nums2.length
  nums1 和 nums2 都是从小到大排好序的。
*/

// https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/discuss/1527753/Binary-Search-and-Two-Pointers
// 抄的
class Solution {
	int64_t count(vector<int>& A, vector<int>& B, int64_t m)
	{
		int64_t ans = 0;
		size_t a = 0, b = B.size() - 1;
		for (; a < A.size(); ++a) {
			while (b != (size_t)(-1)
				&& static_cast<int64_t>(A[a]) * B[b] > m)
				--b;
			ans += b + 1;
		}
		return ans;
	}

public:
	long long kthSmallestProduct(vector<int>& A, vector<int>& B, long long k)
	{
		vector<int> aneg, bneg, apos, bpos;
		for (int i : A) {
			if (i < 0)
				aneg.push_back(i);
			else
				apos.push_back(i);
		}
		for (int i : B) {
			if (i < 0)
				bneg.push_back(i);
			else
				bpos.push_back(i);
		}
		vector<int>
			anr(aneg.rbegin(), aneg.rend()),
			apr(apos.rbegin(), apos.rend()),
			bnr(bneg.rbegin(), bneg.rend()),
			bpr(bpos.rbegin(), bpos.rend());
		int64_t l = INT64_MIN / 2, r = INT64_MAX / 2;
		while (l < r) {
			int64_t cnt = 0;
			int64_t m = l + (r - l) / 2;
			if (m >= 0) {
				cnt = count(anr, bnr, m)
					+ count(apos, bpos, m)
					+ aneg.size() * bpos.size()
					+ apos.size() * bneg.size();
			} else {
				cnt = count(bpr, aneg, m)
					+ count(apr, bneg, m);
			}
			if (cnt < k)
				l = m + 1;
			else
				r = m;
		}
		return l;
	}
};

int main()
{
	Solution s;
	vector<int>
		A = {2, 5},
		B = {3, 4},
		C = {-4, -2, 0, 3},
		D = {2, 4},
		E = {-2, -1, 0, 1, 2},
		F = {-3, -1, 2, 4, 5};
	ToOut(s.kthSmallestProduct(A, B, 2));
	ToOut(s.kthSmallestProduct(C, D, 6));
	ToOut(s.kthSmallestProduct(E, F, 3));
}
