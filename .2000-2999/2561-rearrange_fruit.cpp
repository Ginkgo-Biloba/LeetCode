#include "leetcode.hpp"

/* 2561. 重排水果

你有两个果篮，每个果篮中有 n 个水果。
给你两个下标从 0 开始的整数数组 basket1 和 basket2 ，用以表示两个果篮中每个水果的交换成本。
你想要让两个果篮相等。为此，可以根据需要多次执行下述操作：

  选中两个下标 i 和 j ，并交换 basket1 中的第 i 个水果和 basket2 中的第 j 个水果。
  交换的成本是 min(basket1i,basket2j) 。

根据果篮中水果的成本进行排序，如果排序后结果完全相同，则认为两个果篮相等。

返回使两个果篮相等的最小交换成本，如果无法使两个果篮相等，则返回 -1 。

示例 1：
输入：basket1 = [4,2,2,2], basket2 = [1,4,1,2]
输出：1
解释：交换 basket1 中下标为 1 的水果和 basket2 中下标为 0 的水果，交换的成本为 1 。此时，basket1 = [4,1,2,2] 且 basket2 = [2,4,1,2] 。重排两个数组，发现二者相等。

示例 2：
输入：basket1 = [2,3,4,1], basket2 = [3,2,5,1]
输出：-1
解释：可以证明无法使两个果篮相等。

提示：
  basket1.length == bakste2.length
  1 <= basket1.length <= 10^5
  1 <= basket1i,basket2i <= 10^9
*/

long long minCost(vector<int> A, vector<int> B)
{
	int n = static_cast<int>(A.size());
	int minval = INT_MAX;
	unordered_map<int, int> D;
	for (int i : A) D[i] += 1;
	for (int i : B) D[i] -= 1;
	A.clear();
	B.clear();
	for (auto& it : D) {
		minval = min(minval, it.first);
		if (it.second % 2)
			return -1;
		for (int i = 0; i < it.second; i += 2)
			A.push_back(it.first);
		for (int i = 0; i > it.second; i -= 2)
			B.push_back(it.first);
	}
	std::sort(A.begin(), A.end());
	std::sort(B.begin(), B.end());
	long long ans = 0;
	n = static_cast<int>(A.size());
	for (int i = 0; i < n; ++i)
		ans += min(2 * minval, min(A[i], B[n - 1 - i]));
	return ans;
}

int main()
{
	ToOut(minCost({4, 2, 2, 2}, {1, 4, 1, 2}));
	ToOut(minCost({2, 3, 4, 1}, {3, 2, 5, 1}));
	ToOut(minCost(
		{84, 80, 43, 8, 80, 88, 43, 14, 100, 88},
		{32, 32, 42, 68, 68, 100, 42, 84, 14, 8}));
}
