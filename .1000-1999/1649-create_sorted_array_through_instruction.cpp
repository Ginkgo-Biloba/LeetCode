﻿#include "leetcode.hpp"

/* 1649. 通过指令创建有序数组

给你一个整数数组 instructions ，你需要根据 instructions 中的元素创建一个有序数组。
一开始你有一个空的数组 nums ，你需要 从左到右 遍历 instructions 中的元素，将它们依次插入 nums 数组中。
每一次插入操作的 代价 是以下两者的 较小值 ：
  nums 中 严格小于  instructions[i] 的数字数目。
  nums 中 严格大于  instructions[i] 的数字数目。

比方说，如果要将 3 插入到 nums = [1,2,3,5] ，那么插入操作的 代价 为 min(2, 1) (元素 1 和  2 小于 3 ，元素 5 大于 3 ），插入后 nums 变成 [1,2,3,3,5] 。

请你返回将 instructions 中所有元素依次插入 nums 后的 总最小代价 。
由于答案会很大，请将它对 10^9 + 7 取余 后返回。

示例 1：
输入：instructions = [1,5,6,2]
输出：1
解释：一开始 nums = [] 。
插入 1 ，代价为 min(0, 0) = 0 ，现在 nums = [1] 。
插入 5 ，代价为 min(1, 0) = 0 ，现在 nums = [1,5] 。
插入 6 ，代价为 min(2, 0) = 0 ，现在 nums = [1,5,6] 。
插入 2 ，代价为 min(1, 2) = 1 ，现在 nums = [1,2,5,6] 。
总代价为 0 + 0 + 0 + 1 = 1 。

示例 2:
输入：instructions = [1,2,3,6,5,4]
输出：3
解释：一开始 nums = [] 。
插入 1 ，代价为 min(0, 0) = 0 ，现在 nums = [1] 。
插入 2 ，代价为 min(1, 0) = 0 ，现在 nums = [1,2] 。
插入 3 ，代价为 min(2, 0) = 0 ，现在 nums = [1,2,3] 。
插入 6 ，代价为 min(3, 0) = 0 ，现在 nums = [1,2,3,6] 。
插入 5 ，代价为 min(3, 1) = 1 ，现在 nums = [1,2,3,5,6] 。
插入 4 ，代价为 min(3, 2) = 2 ，现在 nums = [1,2,3,4,5,6] 。
总代价为 0 + 0 + 0 + 0 + 1 + 2 = 3 。

示例 3：
输入：instructions = [1,3,3,3,2,4,2,1,2]
输出：4
解释：一开始 nums = [] 。
插入 1 ，代价为 min(0, 0) = 0 ，现在 nums = [1] 。
插入 3 ，代价为 min(1, 0) = 0 ，现在 nums = [1,3] 。
插入 3 ，代价为 min(1, 0) = 0 ，现在 nums = [1,3,3] 。
插入 3 ，代价为 min(1, 0) = 0 ，现在 nums = [1,3,3,3] 。
插入 2 ，代价为 min(1, 3) = 1 ，现在 nums = [1,2,3,3,3] 。
插入 4 ，代价为 min(5, 0) = 0 ，现在 nums = [1,2,3,3,3,4] 。
​​​​​插入 2 ，代价为 min(1, 4) = 1 ，现在 nums = [1,2,2,3,3,3,4] 。
插入 1 ，代价为 min(0, 6) = 0 ，现在 nums = [1,1,2,2,3,3,3,4] 。
插入 2 ，代价为 min(2, 4) = 2 ，现在 nums = [1,1,2,2,2,3,3,3,4] 。
总代价为 0 + 0 + 0 + 0 + 1 + 0 + 1 + 0 + 2 = 4 。

提示：
  1 <= instructions.length <= 10^5
  1 <= instructions[i] <= 10^5
*/

int createSortedArray(vector<int>& A)
{
	int const mod = static_cast<int>(1e9 + 7);
	int const buf = static_cast<int>(1e5 + 1);
	int len = static_cast<int>(A.size());
	int sum = 0;
	Fenwick L(buf + 1), G(buf + 1);
	for (int i = 0; i < len; ++i) {
		int a = L.get(A[i] - 1);
		int b = G.get(buf - A[i] - 1);
		sum = (sum + min(a, b)) % mod;
		L.add(A[i], 1);
		G.add(buf - A[i], 1);
	}
	return sum;
}

int main()
{
	vector<int>
		a = {1, 5, 6, 2},
		b = {1, 2, 3, 6, 5, 4},
		c = {1, 3, 3, 3, 2, 4, 2, 1, 2};
	ToOut(createSortedArray(a));
	ToOut(createSortedArray(b));
	ToOut(createSortedArray(c));
}
