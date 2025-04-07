#include "leetcode.hpp"

/* 1952. 三除数

给你一个整数 n 。
如果 n 恰好有三个正除数 ，返回 true ；否则，返回 false 。

如果存在整数 k ，满足 n = k * m ，那么整数 m 就是 n 的一个 除数 。

示例 1：
输入：n = 2
输出：false
解释：2 只有两个除数：1 和 2 。

示例 2：
输入：n = 4
输出：true
解释：4 有三个除数：1、2 和 4 。

提示：
  1 <= n <= 10^4
*/

bool isThree(int n)
{
	int c = 0;
	for (int a = 1; a < n && c < 3; ++a) {
		int b = n / a;
		if (a > b)
			break;
		if (a * b == n)
			c += a != b;
	}
	return c == 3;
}

int main() { }
