#include "leetcode.hpp"

/* 2148. 元素计数

给你一个整数数组 nums ，统计并返回在 nums 中同时至少具有一个严格较小元素和一个严格较大元素的元素数目。

示例 1：
输入：nums = [11,7,2,15]
输出：2
解释：元素 7 ：严格较小元素是元素 2 ，严格较大元素是元素 11 。
元素 11 ：严格较小元素是元素 7 ，严格较大元素是元素 15 。
总计有 2 个元素都满足在 nums 中同时存在一个严格较小元素和一个严格较大元素。

示例 2：
输入：nums = [-3,3,3,90]
输出：2
解释：元素 3 ：严格较小元素是元素 -3 ，严格较大元素是元素 90 。
由于有两个元素的值为 3 ，总计有 2 个元素都满足在 nums 中同时存在一个严格较小元素和一个严格较大元素。

提示：
  1 <= nums.length <= 100
  -10^5 <= nums[i] <= 10^5
*/

int countElements(vector<int>& A)
{
	int n = static_cast<int>(A.size());
	sort(A.begin(), A.end());
	int lo = 1, hi = n - 1;
	for (; lo < n; ++lo) {
		if (A[lo - 1] < A[lo])
			break;
	}
	for (; hi > 0; --hi) {
		if (A[hi - 1] < A[hi])
			break;
	}
	return max(0, hi - lo);
}

int main() { }
