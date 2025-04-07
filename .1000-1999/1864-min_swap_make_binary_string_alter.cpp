#include "leetcode.hpp"

/* 1864. 构成交替字符串需要的最小交换次数

给你一个二进制字符串 s ，现需要将其转化为一个 交替字符串 。
请你计算并返回转化所需的 最小 字符交换次数，如果无法完成转化，返回 -1 。

交替字符串 是指：相邻字符之间不存在相等情况的字符串。
例如，字符串 "010" 和 "1010" 属于交替字符串，但 "0100" 不是。

任意两个字符都可以进行交换，不必相邻 。

示例 1：
输入：s = "111000"
输出：1
解释：交换位置 1 和 4："111000" -> "101010" ，字符串变为交替字符串。

示例 2：
输入：s = "010"
输出：0
解释：字符串已经是交替字符串了，不需要交换。

示例 3：
输入：s = "1110"
输出：-1

提示：
  1 <= s.length <= 1000
  s[i] 的值为 '0' 或 '1'
*/

int distance(string const& s, string const& t)
{
	int d = 0;
	for (size_t i = s.size(); i--;)
		d += s[i] != t[i];
	return d / 2;
}

int minSwaps(string s)
{
	int len = static_cast<int>(s.size());
	int C[2] = {0, 0};
	for (int i = 0; i < len; ++i)
		C[s[i] - '0'] += 1;
	if (abs(C[0] - C[1]) > 1)
		return -1;
	string p;
	if (C[0] < C[1])
		p.push_back('1');
	for (int i = min(C[0], C[1]); i--;)
		p.append("01");
	if (C[1] < C[0])
		p.push_back('0');
	string q = p;
	reverse(q.begin(), q.end());
	return min(distance(s, p), distance(s, q));
}

int main()
{
}
