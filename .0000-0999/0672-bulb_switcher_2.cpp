﻿#include "leetcode.hpp"

/* 672. 灯泡开关 Ⅱ

现有一个房间，墙上挂有 n 只已经打开的灯泡和 4 个按钮。
在进行了 m 次未知操作后，你需要返回这 n 只灯泡可能有多少种不同的状态。

假设这 n 只灯泡被编号为 [1, 2, 3 ..., n]，这 4 个按钮的功能如下：
  将所有灯泡的状态反转（即开变为关，关变为开）
  将编号为偶数的灯泡的状态反转
  将编号为奇数的灯泡的状态反转
  将编号为 3k+1 的灯泡的状态反转（k = 0, 1, 2, ...)

示例 1:
输入: n = 1, m = 1.
输出: 2
说明: 状态为: [开], [关]

示例 2:
输入: n = 2, m = 1.
输出: 3
说明: 状态为: [开, 关], [关, 开], [关, 关]

示例 3:
输入: n = 3, m = 1.
输出: 4
说明: 状态为: [关, 开, 关], [开, 关, 开], [关, 关, 关], [关, 开, 开].

注意： n 和 m 都属于 [0, 1000].。
*/

// https://leetcode-cn.com/problems/bulb-switcher-ii/solution/deng-pao-kai-guan-ii-by-leetcode/
// 抄的
int flipLights(int n, int m)
{
	int const result[] = {2, 3, 4, 2, 4, 7, 2, 4, 8};
	n = std::min(n, 3);
	m = std::min(m, 3);
	if (m == 0)
		return 1;
	return result[(m - 1) * 3 + n - 1];
}

int main()
{
	ToOut(flipLights(1, 1));
	ToOut(flipLights(2, 1));
	ToOut(flipLights(3, 1));
}
