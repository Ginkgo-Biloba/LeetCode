﻿#include "leetcode.hpp"

/* 179. 最大数

给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。

示例 1:
输入: [10,2]
输出: 210

示例 2:
输入: [3,30,34,5,9]
输出: 9534330

说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。
*/

struct Compare {
	char buf[48];
	char *ab, *ba;
	Compare()
	{
		ab = buf;
		ba = buf + 24;
	}
	bool operator()(int a, int b) const
	{
		sprintf(ab, "%d%d", a, b);
		sprintf(ba, "%d%d", b, a);
		return strcmp(ab, ba) > 0;
	}
};

string largestNumber(vector<int>& nums)
{
	string s;
	char buf[24];
	sort(nums.begin(), nums.end(), Compare());
	for (int n : nums) {
		sprintf(buf, "%d", n);
		s.append(buf);
	}
	if (s[0] == '0')
		s.assign(1, '0');
	return s;
}

int main()
{
	vector<int>
		a = {10, 2},
		b = {3, 30, 34, 5, 9};
	ToOut(largestNumber(a));
	ToOut(largestNumber(b));
}
