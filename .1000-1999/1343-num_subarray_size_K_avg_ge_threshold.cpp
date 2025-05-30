﻿#include "leetcode.hpp"

/* 1343. 大小为 K 且平均值大于等于阈值的子数组数目

给你一个整数数组 arr 和两个整数 k 和 threshold 。

请你返回长度为 k 且平均值大于等于 threshold 的子数组数目。

示例 1：
输入：arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
输出：3
解释：子数组 [2,5,5],[5,5,5] 和 [5,5,8] 的平均值分别为 4，5 和 6 。
其他长度为 3 的子数组的平均值都小于 4 （threshold 的值)。

示例 2：
输入：arr = [1,1,1,1,1], k = 1, threshold = 0
输出：5

示例 3：
输入：arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
输出：6
解释：前 6 个长度为 3 的子数组平均值都大于 5 。注意平均值不是整数。

示例 4：
输入：arr = [7,7,7,7,7,7,7], k = 7, threshold = 7
输出：1

示例 5：
输入：arr = [4,4,4,4], k = 4, threshold = 1
输出：1

提示：
  1 <= arr.length <= 10^5
  1 <= arr[i] <= 10^4
  1 <= k <= arr.length
  0 <= threshold <= 10^4
*/

int numOfSubarrays(vector<int>& A, int k, int threshold)
{
	int len = static_cast<int>(A.size());
	int ans = 0, sum = 0;
	threshold *= k;
	for (int i = 0; i < k - 1; ++i)
		sum += A[i];
	for (int h = 0, i = k - 1; i < len; ++h, ++i) {
		sum += A[i];
		ans += (sum >= threshold);
		sum -= A[h];
	}
	return ans;
}

int main()
{
	vector<int>
		a = {2, 2, 2, 2, 5, 5, 5, 8},
		b = {1, 1, 1, 1, 1},
		c = {11, 13, 17, 23, 29, 31, 7, 5, 2, 3},
		d = {7, 7, 7, 7, 7, 7, 7},
		e = {4, 4, 4, 4};
	ToOut(numOfSubarrays(a, 3, 4));
	ToOut(numOfSubarrays(b, 1, 0));
	ToOut(numOfSubarrays(c, 3, 5));
	ToOut(numOfSubarrays(d, 7, 7));
	ToOut(numOfSubarrays(e, 4, 1));
}
