#include "leetcode.hpp"

/* 1931. 用三种不同颜色为网格涂色

给你两个整数 m 和 n 。构造一个 m x n 的网格，其中每个单元格最开始是白色。
请你用 红、绿、蓝 三种颜色为每个单元格涂色。所有单元格都需要被涂色。

涂色方案需要满足：不存在相邻两个单元格颜色相同的情况 。
返回网格涂色的方法数。
因为答案可能非常大， 返回 对 10^9 + 7 取余 的结果。

示例 1：
https://assets.leetcode.com/uploads/2021/06/22/colorthegrid.png
输入：m = 1, n = 1
输出：3
解释：如上图所示，存在三种可能的涂色方案。

示例 2：
https://assets.leetcode.com/uploads/2021/06/22/copy-of-colorthegrid.png
输入：m = 1, n = 2
输出：6
解释：如上图所示，存在六种可能的涂色方案。

示例 3：
输入：m = 5, n = 5
输出：580986

提示：
  1 <= m <= 5
  1 <= n <= 1000
*/

int colorTheGrid(int m, int n)
{
	int const mod = static_cast<int>(1e9 + 7);
	int limit = 1;
	for (int i = 0; i < m; ++i)
		limit *= 3;

	/* 选择能用的 mask，每 3 bit 表示一个颜色 */
	vector<int> mask;
	for (int i = 0; i < limit; ++i) {
		int pre = -1, cur = 0;
		int src = i, dst = 0;
		for (int k = 0; k < m; ++k) {
			cur = src % 3;
			src = src / 3;
			if (cur == pre) {
				dst = -1;
				break;
			}
			dst = (dst << 3) | (1 << cur);
			pre = cur;
		}
		if (dst > 0)
			mask.push_back(dst);
	}

	/* 以这个 mask 结尾的可能的方案数量 */
	int len = static_cast<int>(mask.size());
	vector<int> pre(len), cur(len, 1);
	// printf("valid state: %d\n", len);
	while (--n) {
		pre.swap(cur);
		memset(cur.data(), 0, len * sizeof(cur[0]));
		for (int i = 0; i < len; ++i)
			for (int k = i + 1; k < len; ++k)
				if (!(mask[i] & mask[k])) {
					cur[i] = (cur[i] + pre[k]) % mod;
					cur[k] = (cur[k] + pre[i]) % mod;
				}
	}

	int sum = 0;
	for (int i = 0; i < len; ++i)
		sum = (sum + cur[i]) % mod;
	return sum;
}

int main()
{
	ToOut(colorTheGrid(1, 1));
	ToOut(colorTheGrid(1, 2));
	ToOut(colorTheGrid(5, 5));
}
