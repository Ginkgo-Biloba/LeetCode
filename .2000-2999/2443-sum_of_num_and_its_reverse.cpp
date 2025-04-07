﻿#include "leetcode.hpp"

/* 2443. 反转之后的数字和

给你一个 非负 整数 num 。
如果存在某个 非负 整数 k 满足 k + reverse(k) = num  ，则返回 true ；否则，返回 false 。

reverse(k) 表示 k 反转每个数位后得到的数字。

示例 1：
输入：num = 443
输出：true
解释：172 + 271 = 443 ，所以返回 true 。

示例 2：
输入：num = 63
输出：false
解释：63 不能表示为非负整数及其反转后数字之和，返回 false 。

示例 3：
输入：num = 181
输出：true
解释：140 + 041 = 181 ，所以返回 true 。注意，反转后的数字可能包含前导零。

提示：
  0 <= num <= 10^5
*/

bool sumOfNumberAndReverse(int num)
{
	for (int i = num / 2; i < num; ++i) {
		int r = 0;
		for (int n = i; n; n /= 10)
			r = r * 10 + n % 10;
		if (r + i == num)
			return true;
	}
	return false;
}

int main()
{
	ToOut(sumOfNumberAndReverse(443));
	ToOut(sumOfNumberAndReverse(63));
	ToOut(sumOfNumberAndReverse(181));
}
