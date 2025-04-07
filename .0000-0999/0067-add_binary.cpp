﻿#include "leetcode.hpp"

/* 67. 二进制求和

给你两个二进制字符串，返回它们的和（用二进制表示）。

输入为 非空 字符串且只包含数字 1 和 0。

示例 1:
输入: a = "11", b = "1"
输出: "100"

示例 2:
输入: a = "1010", b = "1011"
输出: "10101"

提示：
  每个字符串仅由字符 '0' 或 '1' 组成。
  1 <= a.length, b.length <= 10^4
  字符串如果不是 "0" ，就都不含前导零。
*/

string addBinary(string A, string B)
{
	if (A.length() < B.length())
		A.swap(B);
	int a = static_cast<int>(A.length());
	int b = static_cast<int>(B.length());
	string C;
	int v = 0;
	C.reserve(a + 1);
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	for (int i = 0; i < b; ++i) {
		v += A[i] + B[i] - (2 * '0');
		A[i] = static_cast<char>((v & 1) + '0');
		v >>= 1;
	}
	for (int i = b; i < a; ++i) {
		v += A[i] - '0';
		A[i] = static_cast<char>((v & 1) + '0');
		v >>= 1;
	}
	if (v)
		A.push_back('1');
	reverse(A.begin(), A.end());
	return A;
}

int main()
{
	ToOut(addBinary("11", "1"));
	ToOut(addBinary("1010", "1011"));
}
