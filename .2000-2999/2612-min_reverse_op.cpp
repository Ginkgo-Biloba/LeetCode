#include "leetcode.hpp"

/* 2612. 最少翻转操作数

给定一个整数 n 和一个整数 p，它们表示一个长度为 n 且除了下标为 p 处是 1 以外，其他所有数都是 0 的数组 arr。
同时给定一个整数数组 banned ，它包含数组中的一些限制位置。

在 arr 上进行下列操作：
  如果单个 1 不在 banned 中的位置上，反转大小为 k 的 子数组。
  返回一个包含 n 个结果的整数数组 answer，其中第 i 个结果是将 1 放到位置 i 处所需的 最少 翻转操作次数，如果无法放到位置 i 处，此数为 -1 。

示例 1：
输入：n = 4, p = 0, banned = [1,2], k = 4
输出：[0,-1,-1,1]
解释：
一开始 1 位于位置 0，因此我们需要在位置 0 上的操作数是 0。
我们不能将 1 放置在被禁止的位置上，所以位置 1 和 2 的答案是 -1。
执行大小为 4 的操作以反转整个数组。
在一次操作后，1 位于位置 3，因此位置 3 的答案是 1。

示例 2：
输入：n = 5, p = 0, banned = [2,4], k = 3
输出：[0,-1,-1,-1,-1]
解释：
一开始 1 位于位置 0，因此我们需要在位置 0 上的操作数是 0。
我们不能在 [0, 2] 的子数组位置上执行操作，因为位置 2 在 banned 中。
由于 1 不能够放置在位置 2 上，使用更多操作将 1 放置在其它位置上是不可能的。

示例 3：
输入：n = 4, p = 2, banned = [0,1,3], k = 1
输出：[-1,-1,0,-1]
解释：
执行大小为 1 的操作，且 1 永远不会改变位置。

提示：
  1 <= n <= 10^5
  0 <= p <= n - 1
  0 <= banned.length <= n - 1
  0 <= banned[i] <= n - 1
  1 <= k <= n
  banned[i] != p
  banned 中的值 互不相同 。
*/

// https://leetcode.cn/problems/minimum-reverse-operations/description/
// 抄的
vector<int> minReverseOperations(
	int n, int p, vector<int> const& banned, int k)
{
	vector<int> ans(n, -1);
	// 处理特殊情况 k = 1
	if (k == 1) {
		ans[p] = 0;
		return ans;
	}
	vector<bool> ban(n, false);
	for (int x : banned) ban[x] = true;

	// 把除了 p 和 banned 的所有位置，按奇偶性放进两个 set 里
	// 这些就是我们还没被跳到的位置
	set<int> st[2];
	for (int i = 0; i < n; i++)
		if (i != p && !ban[i])
			st[i % 2].insert(i);

	// bfs
	vector<int> Q;
	Q.push_back(p);
	ans[p] = 0;
	for (size_t i = 0; i < Q.size(); ++i) {
		int cur = Q[i];
		// 计算可以跳的范围
		int L, R;
		L = max(-(k - 1), k - 1 - cur * 2);
		R = min(k - 1, -(k - 1) + (n - cur - 1) * 2);

		// 寻找第一个大于等于 now + L 的位置，并开始枚举后面连续的位置
		int x = (cur + (k - 1)) % 2;
		auto it = st[x].lower_bound(cur + L);
		while (it != st[x].end()) {
			// 遇到了第一个大于 now + R 的位置，结束枚举
			if (*it > cur + R) break;
			// 这个位置还没被跳过，但是可以从 now 一步跳过来
			// 更新答案，并从 set<int> 里去掉
			ans[*it] = ans[cur] + 1;
			Q.push_back(*it);
			it = st[x].erase(it);
		}
	}
	return ans;
}

int main()
{
	ToOut(minReverseOperations(4, 0, {1, 2}, 4));
	ToOut(minReverseOperations(5, 0, {2, 4}, 3));
	ToOut(minReverseOperations(4, 2, {0, 1, 3}, 1));
}
