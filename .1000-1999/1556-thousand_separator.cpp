#include "leetcode.hpp"

/* 1556. 千位分隔数

给你一个整数 n，请你每隔三位添加点（即 "." 符号）作为千位分隔符，并将结果以字符串格式返回。

示例 1：
输入：n = 987
输出："987"

示例 2：
输入：n = 1234
输出："1.234"

示例 3：
输入：n = 123456789
输出："123.456.789"

示例 4：
输入：n = 0
输出："0"

提示：
  0 <= n < 2^31
*/

string thousandSeparator(int n)
{
	string s;
	if (n == 0) {
		s.push_back('0');
		return s;
	}
	for (int i = 1; n; ++i) {
		int d = n % 10 + '0';
		n /= 10;
		s.push_back(static_cast<char>(d));
		if ((i % 3 == 0) && n)
			s.push_back('.');
	}
	reverse(s.begin(), s.end());
	return s;
}

int main()
{
	ToOut(thousandSeparator(1));
	ToOut(thousandSeparator(12));
	ToOut(thousandSeparator(123));
	ToOut(thousandSeparator(1234));
	ToOut(thousandSeparator(12345));
	ToOut(thousandSeparator(123456));
	ToOut(thousandSeparator(1234567));
}
