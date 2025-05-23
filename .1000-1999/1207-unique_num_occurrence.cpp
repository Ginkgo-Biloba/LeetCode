﻿#include "leetcode.hpp"

/* 1207. 独一无二的出现次数

给你一个整数数组 arr，请你帮忙统计数组中每个数的出现次数。

如果每个数的出现次数都是独一无二的，就返回 true；否则返回 false。

示例 1：
输入：arr = [1,2,2,1,1,3]
输出：true
解释：在该数组中，1 出现了 3 次，2 出现了 2 次，3 只出现了 1 次。没有两个数的出现次数相同。

示例 2：
输入：arr = [1,2]
输出：false

示例 3：
输入：arr = [-3,0,1,-3,1,1,1,-3,10,0]
输出：true

提示：
  1 <= arr.length <= 1000
  -1000 <= arr[i] <= 1000
*/

bool uniqueOccurrences(vector<int>& arr)
{
	vector<int> buffer(3002);
	int *cnt = buffer.data() + 1000, *freq = cnt + 1001;
	for (int a : arr)
		cnt[a] += 1;
	for (int i = -1000; i <= 1000; ++i) {
		if (cnt[i] > 0 && freq[cnt[i]])
			return false;
		freq[cnt[i]] += 1;
	}
	return true;
}

int main()
{
}
