#include "leetcode.hpp"

/* 556. 下一个更大元素 III

给定一个32位正整数 n，你需要找到最小的32位整数，其与 n 中存在的位数完全相同，并且其值大于n。
如果不存在这样的32位整数，则返回-1。

示例 1:

输入: 12
输出: 21

示例 2:

输入: 21
输出: -1
*/

int nextGreaterElement(int n)
{
	int b[16], i = 15;
	for (; n > 0; --i) {
		b[i] = n % 10;
		n /= 10;
	}
	++i;
	std::next_permutation(b + i, b + 16);
	int64_t N = 0;
	for (; i < 16; ++i) {
		N *= 10;
		N += b[i];
	}
	if (N > n && N <= INT_MAX)
		n = static_cast<int>(N);
	else
		n = -1;
	return n;
}

int main()
{
	ToOut(nextGreaterElement(1999999999));
}
