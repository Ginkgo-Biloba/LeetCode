#include "leetcode.hpp"

/* 202. 快乐数

编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果 可以变为  1，那么这个数就是快乐数。

如果 n 是快乐数就返回 True ；不是，则返回 False 。

示例 1：
输入：n = 19
输出：true
解释：
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1

示例 2：
输入：n = 2
输出：false

提示：
  1 <= n <= 2^31 - 1
*/

int next(int n)
{
	int a = 0, b;
	while (n) {
		b = n % 10;
		n = n / 10;
		a += b * b;
	}
	return a;
}

bool isHappy_Org(int n)
{
	unordered_set<int> s;
	s.insert(n);
	while (n != 1) {
		n = next(n);
		if (!(s.insert(n).second))
			break;
	}
	return n == 1;
}

// https://leetcode.com/problems/happy-number/discuss/56917/My-solution-in-C(-O(1)-space-and-no-magic-math-property-involved-)
// 抄的
bool isHappy(int n)
{
	if (n == 1)
		return true;
	int a = n, b = next(n);
	while ((a != b) && (b != 1)) {
		a = next(a);
		b = next(b);
		b = next(b);
	}
	return b == 1;
}

int main()
{
	ToOut(isHappy(19));
}
