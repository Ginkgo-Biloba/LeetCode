#include "leetcode.hpp"

/* 1862. 向下取整数对和

给你一个整数数组 nums ，请你返回所有下标对 0 <= i, j < nums.length 的 floor(nums[i] / nums[j]) 结果之和。
由于答案可能会很大，请你返回答案对10^9 + 7 取余 的结果。

函数 floor() 返回输入数字的整数部分。

示例 1：
输入：nums = [2,5,9]
输出：10
解释：
floor(2 / 5) = floor(2 / 9) = floor(5 / 9) = 0
floor(2 / 2) = floor(5 / 5) = floor(9 / 9) = 1
floor(5 / 2) = 2
floor(9 / 2) = 4
floor(9 / 5) = 1
我们计算每一个数对商向下取整的结果并求和得到 10 。

示例 2：

输入：nums = [7,7,7,7,7,7,7]
输出：49

提示：
  1 <= nums.length <= 10^5
  1 <= nums[i] <= 10^5
*/

int sumOfFlooredPairs(vector<int>& A)
{
	int const up = static_cast<int>(1e5 + 1);
	int64_t sum = 0;
	vector<int> B(up), C(up);
	for (size_t i = A.size(); i--;)
		B[A[i]] += 1;
	for (int i = 1; i < up; ++i)
		C[i] = C[i - 1] + B[i];
	for (int i = 1; i < up; ++i) {
		if (!B[i])
			continue;
		for (int k = i; k < up; k += i) {
			int u = min(k + i, up);
			int64_t w = static_cast<int64_t>(k / i);
			sum += w * B[i] * (C[u - 1] - C[k - 1]);
		}
	}
	sum %= static_cast<int64_t>(1e9 + 7);
	return static_cast<int>(sum);
}

int main()
{
}
