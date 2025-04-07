#include "leetcode.hpp"

/* 2523. 范围内最接近的两个质数

给你两个正整数 left 和 right ，请你找到两个整数 num1 和 num2 ，它们满足：

left <= nums1 < nums2 <= right  。
nums1 和 nums2 都是 质数 。
nums2 - nums1 是满足上述条件的质数对中的 最小值 。
请你返回正整数数组 ans = [nums1, nums2] 。如果有多个整数对满足上述条件，请你返回 nums1 最小的质数对。如果不存在符合题意的质数对，请你返回 [-1, -1] 。

示例 1：
输入：left = 10, right = 19
输出：[11,13]
解释：10 到 19 之间的质数为 11 ，13 ，17 和 19 。
质数对的最小差值是 2 ，[11,13] 和 [17,19] 都可以得到最小差值。
由于 11 比 17 小，我们返回第一个质数对。

示例 2：
输入：left = 4, right = 6
输出：[-1,-1]
解释：给定范围内只有一个质数，所以题目条件无法被满足。

提示：
  1 <= left <= right <= 10^6
*/

vector<int> closestPrimes(int left, int right)
{
	vector<char> check(right + 1, 1);
	vector<int> primes;
	for (int i = 2; i <= right; ++i) {
		if (check[i]) {
			primes.push_back(i);
			if (i > right / i) continue;
			for (int k = i * i; k <= right; k += i)
				check[k] = 0;
		}
	}
	int mindif = INT_MAX, minidx = -1;
	for (int i = static_cast<int>(primes.size()) - 2; i >= 0; --i) {
		if (primes[i] < left)
			break;
		int dif = primes[i + 1] - primes[i];
		if (dif <= mindif) {
			mindif = dif;
			minidx = i;
		}
	}
	vector<int> ans = {-1, -1};
	if (minidx != -1) {
		ans[0] = primes[minidx];
		ans[1] = primes[minidx + 1];
	}
	return ans;
}

int main()
{
	ToOut(closestPrimes(10, 19));
	ToOut(closestPrimes(4, 6));
}
