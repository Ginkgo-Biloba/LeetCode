﻿#include "leetcode.hpp"

/* 954. 二倍数对数组

给定一个长度为偶数的整数数组 A，只有对 A 进行重组后可以满足
  对于每个 0 <= i < len(A) / 2，都有 A[2 * i + 1] = 2 * A[2 * i]
时，返回 true；否则，返回 false。

示例 1：
输入：[3,1,3,6]
输出：false

示例 2：
输入：[2,1,2,6]
输出：false

示例 3：
输入：[4,-2,2,-4]
输出：true
解释：我们可以用 [-2,-4] 和 [2,4] 这两组组成 [-2,-4,2,4] 或是 [2,4,-2,-4]

示例 4：
输入：[1,2,4,16,8,4]
输出：false

提示：
  0 <= A.length <= 30000
  A.length 为偶数
  -100000 <= A[i] <= 100000
*/

// https://leetcode.com/problems/array-of-doubled-pairs/discuss/203183/JavaC%2B%2BPython-Match-from-the-Smallest-or-Biggest-100
// 抄的
bool canReorderDoubled(vector<int>& A)
{
	unordered_map<int, int> cnt;
	vector<int> key;

	for (int a : A)
		++(cnt[a]);
	for (auto const& kv : cnt)
		key.push_back(kv.first);

	sort(key.begin(), key.end(),
		[](int a, int b) { return abs(a) < abs(b); });

	for (int k : key) {
		if (cnt[k] > cnt[2 * k])
			return false;
		cnt[2 * k] -= cnt[k];
	}
	return true;
}

int main()
{
	vector<int>
		a = {3, 1, 3, 6},
		b = {3, 1, 3, 6},
		c = {4, -2, 2, -4},
		d = {1, 2, 4, 16, 8, 4};
	ToOut(canReorderDoubled(a));
	ToOut(canReorderDoubled(b));
	ToOut(canReorderDoubled(c));
	ToOut(canReorderDoubled(d));
}
