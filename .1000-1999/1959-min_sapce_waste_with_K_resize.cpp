﻿#include "leetcode.hpp"

/* 1959. K 次调整数组大小浪费的最小总空间

你正在设计一个动态数组。
给你一个下标从 0 开始的整数数组 nums ，其中 nums[i] 是 i 时刻数组中的元素数目。
除此以外，你还有一个整数 k ，表示你可以 调整 数组大小的 最多 次数（每次都可以调整成 任意 大小）。

t 时刻数组的大小 sizet 必须大于等于 nums[t] ，因为数组需要有足够的空间容纳所有元素。
t 时刻 浪费的空间 为 sizet - nums[t] ，总 浪费空间为满足 0 <= t < nums.length 的每一个时刻 t 浪费的空间 之和 。

在调整数组大小不超过 k 次的前提下，请你返回 最小总浪费空间 。

注意：数组最开始时可以为 任意大小 ，且 不计入 调整大小的操作次数。

示例 1：
输入：nums = [10,20], k = 0
输出：10
解释：size = [20,20].
我们可以让数组初始大小为 20 。
总浪费空间为 (20 - 10) + (20 - 20) = 10 。

示例 2：
输入：nums = [10,20,30], k = 1
输出：10
解释：size = [20,20,30].
我们可以让数组初始大小为 20 ，然后时刻 2 调整大小为 30 。
总浪费空间为 (20 - 10) + (20 - 20) + (30 - 30) = 10 。

示例 3：
输入：nums = [10,20,15,30,20], k = 2
输出：15
解释：size = [10,20,20,30,30].
我们可以让数组初始大小为 10 ，时刻 1 调整大小为 20 ，时刻 3 调整大小为 30 。
总浪费空间为 (10 - 10) + (20 - 20) + (20 - 15) + (30 - 30) + (30 - 20) = 15 。

提示：
  1 <= nums.length <= 200
  1 <= nums[i] <= 10^6
  0 <= k <= nums.length - 1
*/

int minSpaceWastedKResizing(vector<int>& A, int k)
{
	int n = static_cast<int>(A.size());
	vector<int> pre(n), cur(n);
	int ext = 0, sum = 0;
	for (int i = 0; i < n; ++i) {
		ext = max(ext, A[i]);
		sum = sum + A[i];
		cur[i] = ext * (i + 1) - sum;
	}

	while (k--) {
		copy(cur.begin(), cur.end(), pre.begin());
		for (int i = 0; i < n; ++i) {
			ext = sum = 0;
			for (int j = i - 1; j >= 0; --j) {
				ext = max(ext, A[j + 1]);
				sum = sum + A[j + 1];
				cur[i] = min(cur[i], pre[j] + ext * (i - j) - sum);
			}
		}
	}
	return cur[n - 1];
}

int main()
{
	vector<int>
		a = {10, 20},
		b = {10, 20, 30},
		c = {10, 20, 15, 30, 20};
	ToOut(minSpaceWastedKResizing(b, 1));
	ToOut(minSpaceWastedKResizing(a, 0));
	ToOut(minSpaceWastedKResizing(c, 2));
}
