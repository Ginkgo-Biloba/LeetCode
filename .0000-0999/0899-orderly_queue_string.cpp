﻿#include "leetcode.hpp"

/* 899. 有序队列

给出了一个由小写字母组成的字符串 S。然后，我们可以进行任意次数的移动。

在每次移动中，我们选择前 K 个字母中的一个（从左侧开始），将其从原位置移除，并放置在字符串的末尾。

返回我们在任意次数的移动之后可以拥有的按字典顺序排列的最小字符串。

示例 1：
输入：S = "cba", K = 1
输出："acb"
解释：
在第一步中，我们将第一个字符（“c”）移动到最后，获得字符串 “bac”。
在第二步中，我们将第一个字符（“b”）移动到最后，获得最终结果 “acb”。

示例 2：
输入：S = "baaca", K = 3
输出："aaabc"
解释：
在第一步中，我们将第一个字符（“b”）移动到最后，获得字符串 “aacab”。
在第二步中，我们将第三个字符（“c”）移动到最后，获得最终结果 “aaabc”。

提示：
  1 <= K <= S.length <= 1000
  S 只由小写字母组成。
*/

// https://leetcode-cn.com/problems/orderly-queue/solution/you-xu-dui-lie-by-leetcode/
// 抄的
string orderlyQueue(string S, int K)
{
	if (K > 1) {
		sort(S.begin(), S.end());
		return S;
	}
	string T = S + S;
	size_t t = 0, len = S.size();
	char const* ptr = T.c_str();
	for (size_t i = 1; i < len; ++i) {
		if (strncmp(ptr + t, ptr + i, len) > 0)
			t = i;
	}
	return T.substr(t, len);
}

int main()
{
	ToOut(orderlyQueue("cba", 1).c_str());
	ToOut(orderlyQueue("baaca", 3).c_str());
}
