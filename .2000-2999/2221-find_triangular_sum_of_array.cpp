#include "leetcode.hpp"

/* 2221. 数组的三角和

给你一个下标从 0 开始的整数数组 nums ，其中 nums[i] 是 0 到 9 之间（两者都包含）的一个数字。

nums 的 三角和 是执行以下操作以后最后剩下元素的值：
nums 初始包含 n 个元素。
  如果 n == 1 ，终止 操作。否则，创建 一个新的下标从 0 开始的长度为 n - 1 的整数数组 newNums 。
  对于满足 0 <= i < n - 1 的下标 i ，newNums[i] 赋值 为 (nums[i] + nums[i+1]) % 10 ，% 表示取余运算。
  将 newNums 替换 数组 nums 。
  从步骤 1 开始 重复 整个过程。

请你返回 nums 的三角和。

示例 1：
https://assets.leetcode.com/uploads/2022/02/22/ex1drawio.png
输入：nums = [1,2,3,4,5]
输出：8
解释：
上图展示了得到数组三角和的过程。

示例 2：
输入：nums = [5]
输出：5
解释：
由于 nums 中只有一个元素，数组的三角和为这个元素自己。

提示：
  1 <= nums.length <= 1000
  0 <= nums[i] <= 9
*/

// https://leetcode.com/problems/find-triangular-sum-of-an-array/solutions/1907380/o-n-time-o-1-space-python-189-ms-c-12-ms-java-4-ms/
// 抄的
int triangularSum(vector<int> const& nums)
{
	int result = 0;
	int m = static_cast<int>(nums.size()) - 1;
	int mck = 1, exp2 = 0, exp5 = 0;
	int inv[] = {0, 1, 0, 7, 0, 0, 0, 3, 0, 9};
	int pow2mod10[] = {6, 2, 4, 8};
	for (int k = 0; true; k++) {
		if (!exp2 || !exp5) {
			int mCK
				= exp2 ? mck * pow2mod10[exp2 % 4]
				: exp5 ? mck * 5
							 : mck;
			result = (result + mCK * nums[k]) % 10;
		}
		if (k == m)
			return result;

		// mCk *= m - k
		int mul = m - k;
		while (mul % 2 == 0) {
			mul /= 2;
			exp2++;
		}
		while (mul % 5 == 0) {
			mul /= 5;
			exp5++;
		}
		mck = mck * mul % 10;

		// mCk /= k + 1
		int div = k + 1;
		while (div % 2 == 0) {
			div /= 2;
			exp2--;
		}
		while (div % 5 == 0) {
			div /= 5;
			exp5--;
		}
		mck = mck * inv[div % 10] % 10;
	}
}

int main()
{
	ToOut(triangularSum({1, 2, 3, 4, 5}));
	ToOut(triangularSum({5}));
}
