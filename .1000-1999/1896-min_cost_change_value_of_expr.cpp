#include "leetcode.hpp"

/* 1896. 反转表达式值的最少操作次数

给你一个 有效的 布尔表达式，用字符串 expression 表示。
这个字符串包含字符 '1'，'0'，'&'（按位 与 运算），'|'（按位 或 运算），'(' 和 ')' 。

  比方说，"()1|1" 和 "(1)&()" 不是有效 布尔表达式。
  而 "1"， "(((1))|(0))" 和 "1|(0&(1))" 是 有效 布尔表达式。

你的目标是将布尔表达式的 值 反转 （也就是将 0 变为 1 ，或者将 1 变为 0），请你返回达成目标需要的 最少操作 次数。

  比方说，如果表达式 expression = "1|1|(0&0)&1" ，它的 值 为 1|1|(0&0)&1 = 1|1|0&1 = 1|0&1 = 1&1 = 1 。
  我们想要执行操作将 新的 表达式的值变成 0 。

可执行的 操作 如下：

  将一个 '1' 变成一个 '0' 。
  将一个 '0' 变成一个 '1' 。
  将一个 '&' 变成一个 '|' 。
  将一个 '|' 变成一个 '&' 。

注意：'&' 的 运算优先级 与 '|' 相同 。
计算表达式时，括号优先级 最高 ，然后按照 从左到右 的顺序运算。

示例 1：
输入：expression = "1&(0|1)"
输出：1
解释：我们可以将 "1&(0|1)" 变成 "1&(0&1)" ，执行的操作为将一个 '|' 变成一个 '&' ，执行了 1 次操作。
新表达式的值为 0 。

示例 2：
输入：expression = "(0&0)&(0&0&0)"
输出：3
解释：我们可以将 "(0&0)&(0&0&0)" 变成 "(0|1)|(0&0&0)" ，执行了 3 次操作。
新表达式的值为 1 。

示例 3：
输入：expression = "(0|(1|0&1))"
输出：1
解释：我们可以将 "(0|(1|0&1))" 变成 "(0|(0|0&1))" ，执行了 1 次操作。
新表达式的值为 0 。

提示：
  1 <= expression.length <= 10^5
  expression 只包含 '1'，'0'，'&'，'|'，'(' 和 ')'
  所有括号都有与之匹配的对应括号。
  不会有空的括号（也就是说 "()" 不是 expression 的子字符串）。
*/

// https://leetcode.com/problems/minimum-cost-to-change-the-final-value-of-expression/discuss/1269086/Very-Easy-to-understand-C%2B%2B-No-Recursion-Ask-Doubts-in-Comments
// 抄的
int minOperationsToFlip(string E)
{
	vector<pair<int, int>> S;
	pair<int, int> p;
	for (int e : E) {
		// 表达式没有值因此改编它的代价为 0？
		if (e == '(' || e == '&' || e == '|') {
			S.push_back({e, 0});
			continue;
		}

		if (e == ')') {
			p = S.back();
			S.pop_back();
			S.pop_back();
		} else {
			// 当我们遇到 '0'/'1' 的时候，存储当前值和改变它的代价
			p = {e, 1};
		}

#define cpack(o, a, b) (((o) << 16) + ((a) << 8) + (b))
		while (S.size() && (S.back().first == '&' || S.back().first == '|')) {
			int op = S.back().first;
			S.pop_back();
			int v2 = p.first;
			int c2 = p.second;
			int v1 = S.back().first;
			int c1 = S.back().second;
			S.pop_back();
			op = cpack(op, v1, v2);

			if (op == cpack('&', '1', '1')) p = {'1', min(c1, c2)};
			if (op == cpack('&', '1', '0')) p = {'0', 1};
			if (op == cpack('&', '0', '1')) p = {'0', 1};
			if (op == cpack('&', '0', '0')) p = {'0', 1 + min(c1, c2)};
			if (op == cpack('|', '1', '1')) p = {'1', 1 + min(c1, c2)};
			if (op == cpack('|', '1', '0')) p = {'1', 1};
			if (op == cpack('|', '0', '1')) p = {'1', 1};
			if (op == cpack('|', '0', '0')) p = {'0', min(c1, c2)};
		}
		S.push_back(p);
	}
	return S.back().second;
}

int main()
{
}
