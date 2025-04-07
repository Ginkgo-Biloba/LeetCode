#include "leetcode.hpp"

/* 2086. 从房屋收集雨水需要的最少水桶数

给你一个下标从 0 开始的字符串 street 。
street 中每个字符要么是表示房屋的 'H' ，要么是表示空位的 '.' 。

你可以在 空位 放置水桶，从相邻的房屋收集雨水。
位置在 i - 1 或者 i + 1 的水桶可以收集位置为 i 处房屋的雨水。
一个水桶如果相邻两个位置都有房屋，那么它可以收集 两个 房屋的雨水。

在确保 每个 房屋旁边都 至少 有一个水桶的前提下，请你返回需要的 最少 水桶数。
如果无解请返回 -1 。

示例 1：
输入：street = "H..H"
输出：2
解释：
我们可以在下标为 1 和 2 处放水桶。
"H..H" -> "HBBH"（'B' 表示放置水桶）。
下标为 0 处的房屋右边有水桶，下标为 3 处的房屋左边有水桶。
所以每个房屋旁边都至少有一个水桶收集雨水。

示例 2：
输入：street = ".H.H."
输出：1
解释：
我们可以在下标为 2 处放置一个水桶。
".H.H." -> ".HBH."（'B' 表示放置水桶）。
下标为 1 处的房屋右边有水桶，下标为 3 处的房屋左边有水桶。
所以每个房屋旁边都至少有一个水桶收集雨水。

示例 3：
输入：street = ".HHH."
输出：-1
解释：
没有空位可以放置水桶收集下标为 2 处的雨水。
所以没有办法收集所有房屋的雨水。

示例 4：
输入：street = "H"
输出：-1
解释：
没有空位放置水桶。
所以没有办法收集所有房屋的雨水。

示例 5：
输入：street = "."
输出：0
解释：
没有房屋需要收集雨水。
所以需要 0 个水桶。

提示：
  1 <= street.length <= 10^5
  street[i] 要么是 'H' ，要么是 '.' 。

2086. Minimum Number of Food Buckets to Feed the Hamsters

You are given a 0-indexed string hamsters where hamsters[i] is either:
  'H' indicating that there is a hamster at index i, or
  '.' indicating that index i is empty.

You will add some number of food buckets at the empty indices in order to feed the hamsters.
A hamster can be fed if there is at least one food bucket to its left or to its right.
More formally, a hamster at index i can be fed if you place a food bucket at index i - 1 and/or at index i + 1.

Return the minimum number of food buckets you should place at empty indices to feed all the hamsters or -1 if it is impossible to feed all of them.

Example 1:
https://assets.leetcode.com/uploads/2022/11/01/example1.png
Input: hamsters = "H..H"
Output: 2
Explanation: We place two food buckets at indices 1 and 2.
It can be shown that if we place only one food bucket, one of the hamsters will not be fed.

Example 2:
https://assets.leetcode.com/uploads/2022/11/01/example2.png
Input: hamsters = ".H.H."
Output: 1
Explanation: We place one food bucket at index 2.

Example 3:
https://assets.leetcode.com/uploads/2022/11/01/example3.png
Input: hamsters = ".HHH."
Output: -1
Explanation: If we place a food bucket at every empty index as shown, the hamster at index 2 will not be able to eat.

Constraints:
  1 <= hamsters.length <= 10^5
  hamsters[i] is either'H' or '.'.
*/

int minimumBuckets(string s)
{
	int n = static_cast<int>(s.size());
	int ans = 0, x = -2;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '.')
			continue;
		if (x == i - 1)
			continue;
		bool l = (i > 0) && (s[i - 1] == '.');
		bool r = (i < n - 1) && (s[i + 1] == '.');
		if (!(l || r))
			return -1;
		x = r ? i + 1 : i - 1;
		++ans;
	}
	return ans;
}

int main() { }
