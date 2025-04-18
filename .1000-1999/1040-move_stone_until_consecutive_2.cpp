﻿#include "leetcode.hpp"

/* 1040. 移动石子直到连续 II

在一个长度无限的数轴上，第 i 颗石子的位置为 stones[i]。
如果一颗石子的位置最小/最大，那么该石子被称作端点石子。

每个回合，你可以将一颗端点石子拿起并移动到一个未占用的位置，使得该石子不再是一颗端点石子。

值得注意的是，如果石子像 stones = [1,2,5] 这样，你将无法移动位于位置 5 的端点石子，因为无论将它移动到任何位置（例如 0 或 3），该石子都仍然会是端点石子。

当你无法进行任何移动时，即，这些石子的位置连续时，游戏结束。

要使游戏结束，你可以执行的最小和最大移动次数分别是多少？
以长度为 2 的数组形式返回答案：answer = [minimum_moves, maximum_moves] 。

示例 1：
输入：[7,4,9]
输出：[1,2]
解释：
我们可以移动一次，4 -> 8，游戏结束。
或者，我们可以移动两次 9 -> 5，4 -> 6，游戏结束。

示例 2：
输入：[6,5,4,3,10]
输出：[2,3]
解释：
我们可以移动 3 -> 8，接着是 10 -> 7，游戏结束。
或者，我们可以移动 3 -> 7, 4 -> 8, 5 -> 9，游戏结束。
注意，我们无法进行 10 -> 2 这样的移动来结束游戏，因为这是不合要求的移动。

示例 3：
输入：[100,101,104,102,103]
输出：[0,0]

提示：
  3 <= stones.length <= 10^4
  1 <= stones[i] <= 10^9
  stones[i] 的值各不相同。
*/

// https://leetcode.com/problems/moving-stones-until-consecutive-ii/discuss/289357/c%2B%2B-with-picture
// 抄的
vector<int> numMovesStonesII(vector<int>& A)
{
	int n = static_cast<int>(A.size());
	sort(A.begin(), A.end());
	int hi = max(A[n - 1] - A[1] - n + 2, A[n - 2] - A[0] - n + 2);
	int lo = n;
	for (int i = 0, k = 0; k < n; ++k) {
		while (A[k] - A[i] + 1 > n)
			++i;
		int store = k - i + 1;
		if (store == n - 1 && A[k] - A[i] == n - 2)
			lo = min(lo, 2);
		else
			lo = min(lo, n - store);
	}
	return vector<int> {lo, hi};
}

int main()
{
	vector<int>
		a = {7, 4, 9},
		b = {6, 5, 4, 3, 10},
		c = {100, 101, 104, 102, 103};
	ToOut(numMovesStonesII(a));
	ToOut(numMovesStonesII(b));
	ToOut(numMovesStonesII(c));
}
