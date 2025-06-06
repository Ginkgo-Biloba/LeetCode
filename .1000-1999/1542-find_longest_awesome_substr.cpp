﻿#include "leetcode.hpp"

/* 1542. 找出最长的超赞子字符串

给你一个字符串 s 。
请返回 s 中最长的 超赞子字符串 的长度。

「超赞子字符串」需满足满足下述两个条件：
  该字符串是 s 的一个非空子字符串
  进行任意次数的字符交换后，该字符串可以变成一个回文字符串

示例 1：
输入：s = "3242415"
输出：5
解释："24241" 是最长的超赞子字符串，交换其中的字符后，可以得到回文 "24142"

示例 2：
输入：s = "12345678"
输出：1

示例 3：
输入：s = "213123"
输出：6
解释："213123" 是最长的超赞子字符串，交换其中的字符后，可以得到回文 "231132"

示例 4：
输入：s = "00"
输出：2

提示：
  1 <= s.length <= 10^5
  s 仅由数字组成
*/

int longestAwesome(string s)
{
	int len = static_cast<int>(s.length());
	int cur = 0, tmp, ans = 0;
	vector<int> idx(1024, len);
	idx[0] = -1;
	for (int i = 0; i < len; ++i) {
		int d = s[i] - '0';
		cur ^= (1 << d);
		ans = max(ans, i - idx[cur]);
		for (d = 0; d < 10; ++d) {
			tmp = cur ^ (1 << d);
			ans = max(ans, i - idx[tmp]);
		}
		// if already have, just nothing happend
		idx[cur] = min(idx[cur], i);
	}
	return ans;
}

int main()
{
	ToOut(longestAwesome("3242415"));
	ToOut(longestAwesome("12345678"));
	ToOut(longestAwesome("213123"));
	ToOut(longestAwesome("00"));
}
