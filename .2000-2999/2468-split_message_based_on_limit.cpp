﻿#include "leetcode.hpp"

/* 2468. 根据限制分割消息

给你一个字符串 message 和一个正整数 limit 。

你需要根据 limit 将 message 分割 成一个或多个 部分 。
每个部分的结尾都是 "<a/b>" ，其中 "b" 用分割出来的总数 替换， "a" 用当前部分所在的编号 替换 ，编号从 1 到 b 依次编号。
除此以外，除了最后一部分长度 小于等于 limit 以外，其他每一部分（包括结尾部分）的长度都应该 等于 limit 。

你需要确保分割后的结果数组，删掉每部分的结尾并 按顺序 连起来后，能够得到 message 。
同时，结果数组越短越好。

请你返回 message  分割后得到的结果数组。如果无法按要求分割 message ，返回一个空数组。

示例 1：
输入：message = "this is really a very awesome message", limit = 9
输出：["thi<1/14>","s i<2/14>","s r<3/14>","eal<4/14>","ly <5/14>","a v<6/14>","ery<7/14>"," aw<8/14>","eso<9/14>","me<10/14>"," m<11/14>","es<12/14>","sa<13/14>","ge<14/14>"]
解释：
前面 9 个部分分别从 message 中得到 3 个字符。
接下来的 5 个部分分别从 message 中得到 2 个字符。
这个例子中，包含最后一个部分在内，每个部分的长度都为 9 。
可以证明没有办法分割成少于 14 个部分。

示例 2：
输入：message = "short message", limit = 15
输出：["short mess<1/2>","age<2/2>"]
解释：
在给定限制下，字符串可以分成两个部分：
- 第一个部分包含 10 个字符，长度为 15 。
- 第二个部分包含 3 个字符，长度为 8 。

提示：
  1 <= message.length <= 10^4
  message 只包含小写英文字母和 ' ' 。
  1 <= limit <= 10^4
*/

int sz(int n)
{
	char buf[32];
	snprintf(buf, sizeof(buf), "%d", n);
	return static_cast<int>(strlen(buf));
}

vector<string> splitMessage(string s, int limit)
{
	int n = static_cast<int>(s.size());
	int parts = 1, a = 1;
	vector<string> ans;
	while (a + n + parts * (3 + sz(parts)) > parts * limit) {
		if (3 + sz(parts) * 2 >= limit)
			return ans;
		parts += 1;
		a += sz(parts);
	}
	char buf[128];
	int count = 1;
	for (int i = 0; i < n;) {
		snprintf(buf, sizeof(buf), "<%d/%d>", count++, parts);
		int left = limit - static_cast<int>(strlen(buf));
		string p;
		for (int k = 0; k < left && i < n; ++k)
			p += s[i++];
		p.append(buf, limit - left);
		ans.push_back(p);
	}
	return ans;
}

int main()
{
	ToOut(splitMessage("this is really a very awesome message", 9));
	ToOut(splitMessage("short message", 15));
}
