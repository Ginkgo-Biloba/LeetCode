﻿#include "leetcode.hpp"

/* 1888. 使二进制字符串字符交替的最少反转次数

给你一个二进制字符串 s 。
你可以按任意顺序执行以下两种操作任意次：
  类型 1 ：删除 字符串 s 的第一个字符并将它 添加 到字符串结尾。
  类型 2 ：选择 字符串 s 中任意一个字符并将该字符 反转 ，也就是如果值为 '0' ，则反转得到 '1' ，反之亦然。

请你返回使 s 变成 交替 字符串的前提下， 类型 2 的 最少 操作次数 。

我们称一个字符串是 交替 的，需要满足任意相邻字符都不同。
  比方说，字符串 "010" 和 "1010" 都是交替的，但是字符串 "0100" 不是。

示例 1：
输入：s = "111000"
输出：2
解释：执行第一种操作两次，得到 s = "100011" 。
然后对第三个和第六个字符执行第二种操作，得到 s = "101010" 。

示例 2：
输入：s = "010"
输出：0
解释：字符串已经是交替的。

示例 3：
输入：s = "1110"
输出：1
解释：对第二个字符执行第二种操作，得到 s = "1010" 。

提示：
  1 <= s.length <= 10^5
  s[i] 要么是 '0' ，要么是 '1' 。
*/

class Solution {
	int box(string const& s, int b)
	{
		int len = static_cast<int>(s.size());
		int nh1 = len / 2 - 1;
		int ans = len, sum = 0;
		int c = b;
		for (int i = 0; i < nh1; ++i) {
			sum += s[i] != c;
			c = '1' + '0' - c;
		}
		for (int i = nh1; i < len; ++i) {
			sum += s[i] != c;
			ans = min(ans, sum);
			sum -= s[i - nh1] != b;
			c = '1' + '0' - c;
			b = '1' + '0' - b;
		}
		return ans;
	}

public:
	int minFlips(string s)
	{
		string t = s + s;
		return min(box(t, '0'), box(t, '1'));
	}
};

int main()
{
	Solution s;
	ToOut(s.minFlips("111000"));
	ToOut(s.minFlips("010"));
	ToOut(s.minFlips("1110"));
	ToOut(s.minFlips("110"));
	ToOut(s.minFlips("01001001101"));
}
