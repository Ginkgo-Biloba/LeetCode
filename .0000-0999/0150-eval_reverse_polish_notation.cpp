﻿#include "leetcode.hpp"

/* 150. 逆波兰表达式求值

根据逆波兰表示法，求表达式的值。

有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

说明：
  整数除法只保留整数部分。
  给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

示例 1：
输入: ["2", "1", "+", "3", "*"]
输出: 9
解释: ((2 + 1) * 3) = 9

示例 2：
输入: ["4", "13", "5", "/", "+"]
输出: 6
解释: (4 + (13 / 5)) = 6

示例 3：
输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
输出: 22
解释:
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/

int evalRPN(vector<string>& tokens)
{
	vector<int> A;
	for (string& s : tokens) {
		if (isdigit(s[0])
			|| (s.size() > 1 && isdigit(s[1]))) {
			A.push_back(atoi(s.c_str()));
			continue;
		}
		int a = A.back();
		A.pop_back();
		int b = A.back();
		A.pop_back();
		if (s[0] == '+')
			b += a;
		else if (s[0] == '-')
			b -= a;
		else if (s[0] == '*')
			b *= a;
		else if (s[0] == '/')
			b /= a;
		else
			assert(false && "invalid RPN");
		A.push_back(b);
	}
	assert(A.size() == 1);
	return A[0];
}

int main()
{
	vector<string>
		a = {"2", "1", "+", "3", "*"},
		b = {"4", "13", "5", "/", "+"},
		c = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
	ToOut(evalRPN(a));
	ToOut(evalRPN(b));
	ToOut(evalRPN(c));
}
