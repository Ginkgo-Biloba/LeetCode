#include "leetcode.hpp"

/* 2035. 将数组分成两个数组并最小化数组和的差


给你一个长度为 2 * n 的整数数组。你需要将 nums 分成 两个 长度为 n 的数组，分别求出两个数组的和，并 最小化 两个数组和之 差的绝对值 。
nums 中每个元素都需要放入两个数组之一。

请你返回 最小 的数组和之差。

示例 1：
https://assets.leetcode.com/uploads/2021/10/02/ex1.png
输入：nums = [3,9,7,3]
输出：2
解释：最优分组方案是分成 [3,9] 和 [7,3] 。
数组和之差的绝对值为 abs((3 + 9) - (7 + 3)) = 2 。

示例 2：

输入：nums = [-36,36]
输出：72
解释：最优分组方案是分成 [-36] 和 [36] 。
数组和之差的绝对值为 abs((-36) - (36)) = 72 。

示例 3：
https://assets.leetcode.com/uploads/2021/10/02/ex3.png
输入：nums = [2,-1,0,4,-2,-9]
输出：0
解释：最优分组方案是分成 [2,4,-9] 和 [-1,0,-2] 。
数组和之差的绝对值为 abs((2 + 4 + -9) - (-1 + 0 + -2)) = 0 。

提示：
  1 <= n <= 15
  nums.length == 2 * n
  -10^7 <= nums[i] <= 10^7
*/

// https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/discuss/1513298/C%2B%2B-Meet-In-Middle
// 抄的
int minimumDifference(vector<int>& A)
{
	int len = static_cast<int>(A.size());
	int N = len / 2, M = 1 << N;
	vector<vector<int>> L(N + 1), R(N + 1);
	for (int m = 0; m < M; ++m) {
		int n = 0, l = 0, r = 0;
		for (int i = 0; i < N; ++i)
			if (m & (1 << i)) {
				++n;
				l += A[i];
				r += A[i + N];
			}
		L[n].push_back(l);
		R[n].push_back(r);
	}
	for (int n = 0; n <= N; ++n)
		sort(R[n].begin(), R[n].end());

	int sum = 0, ans = 0;
	for (int i = 0; i < len; ++i)
		sum += A[i];
	ans = abs(sum - 2 * L[N][0]);
	// ans = min(abs(sum - 2 * L[N][0]), abs(sum - 2 * R[N][0]));
	for (int n = 1; n < N; ++n)
		for (int l : L[n]) {
			int r = (sum - 2 * l) / 2;
			auto& Q = R[N - n];
			auto it = lower_bound(Q.begin(), Q.end(), r);
			if (it != Q.end())
				ans = min(ans, abs(sum - 2 * (l + *it)));
			if (it != Q.begin()) {
				--it;
				ans = min(ans, abs(sum - 2 * (l + *it)));
			}
		}
	return ans;
}

int main()
{
	vector<int>
		A = {3, 9, 7, 3},
		B = {-36, 36},
		C = {2, -1, 0, 4, -2, -9};
	ToOut(minimumDifference(A));
	ToOut(minimumDifference(B));
	ToOut(minimumDifference(C));
}
