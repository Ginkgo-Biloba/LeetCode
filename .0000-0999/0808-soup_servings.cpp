﻿#include "leetcode.hpp"

/* 808. 分汤

有 A 和 B 两种类型的汤。一开始每种类型的汤有 N 毫升。有四种分配操作：

    提供 100ml 的汤A 和 0ml 的汤B。
    提供 75ml 的汤A 和 25ml 的汤B。
    提供 50ml 的汤A 和 50ml 的汤B。
    提供 25ml 的汤A 和 75ml 的汤B。

当我们把汤分配给某人之后，汤就没有了。每个回合，我们将从四种概率同为0.25的操作中进行分配选择。
如果汤的剩余量不足以完成某次操作，我们将尽可能分配。当两种类型的汤都分配完时，停止操作。

注意不存在先分配100 ml汤B的操作。

需要返回的值：汤A先分配完的概率 + 汤A和汤B同时分配完的概率 / 2。

示例:
输入: N = 50
输出: 0.625
解释:
如果我们选择前两个操作，A将首先变为空。对于第三个操作，A和B会同时变为空。对于第四个操作，B将首先变为空。
所以A变为空的总概率加上A和B同时变为空的概率的一半是 0.25 *(1 + 1 + 0.5 + 0)= 0.625。

注释:
  0 <= N <= 10^9。
  返回值在 10^-6 的范围将被认为是正确的。
*/

// https://leetcode-cn.com/problems/soup-servings/solution/fen-tang-by-leetcode/
// 抄的
int M(int x)
{
	return x < 0 ? 0 : x;
}

double soupServings(int N)
{
	N = (N + 24) / 25;
	if (N > 500)
		return 1.0;

	vector<double> P(512 * 512);
	auto at = [](int y, int x) { return y * 512 + x; };

	for (int s = 0; s <= 2 * N; ++s)
		for (int i = 0; i <= N; ++i) {
			int k = s - i;
			if (k < 0 || k > N)
				continue;
			double d = 0;
			if (i == 0)
				d = 1;
			if (i == 0 && k == 0)
				d = 0.5;
			if (i > 0 && k > 0) {
				d = 0.25 * (P[at(M(i - 4), k)] + P[at(M(i - 3), M(k - 1))] + P[at(M(i - 2), M(k - 2))] + P[at(M(i - 1), M(k - 3))]);
			}
			P[at(i, k)] = d;
		}

	return P[at(N, N)];
}

int main()
{
	ToOut(soupServings(50));
}
