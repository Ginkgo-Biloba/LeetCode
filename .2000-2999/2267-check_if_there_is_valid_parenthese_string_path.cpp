#include "leetcode.hpp"

/* 2267. 检查是否有合法括号字符串路径

一个括号字符串是一个 非空 且只包含 '(' 和 ')' 的字符串。
如果下面 任意 条件为 真 ，那么这个括号字符串就是 合法的 。

  字符串是 () 。
  字符串可以表示为 AB（A 连接 B），A 和 B 都是合法括号序列。
  字符串可以表示为 (A) ，其中 A 是合法括号序列。

给你一个 m x n 的括号网格图矩阵 grid 。
网格图中一个 合法括号路径 是满足以下所有条件的一条路径：

  路径开始于左上角格子 (0, 0) 。
  路径结束于右下角格子 (m - 1, n - 1) 。
  路径每次只会向 下 或者向 右 移动。
  路径经过的格子组成的括号字符串是 合法 的。

如果网格图中存在一条 合法括号路径 ，请返回 true ，否则返回 false 。

示例 1：
https://assets.leetcode.com/uploads/2022/03/15/example1drawio.png
输入：grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]
输出：true
解释：上图展示了两条路径，它们都是合法括号字符串路径。
第一条路径得到的合法字符串是 "()(())" 。
第二条路径得到的合法字符串是 "((()))" 。
注意可能有其他的合法括号字符串路径。

示例 2：
https://assets.leetcode.com/uploads/2022/03/15/example2drawio.png
输入：grid = [[")",")"],["(","("]]
输出：false
解释：两条可行路径分别得到 "))(" 和 ")((" 。由于它们都不是合法括号字符串，我们返回 false 。

提示：
  m == grid.length
  n == grid[i].length
  1 <= m, n <= 100
  grid[i][j] 要么是 '(' ，要么是 ')' 。
*/

struct uint128 {
	uint64_t hi, lo;
};

// https://leetcode.cn/problems/check-if-there-is-a-valid-parentheses-string-path/solutions/1/by-heltion-mwgj/
bool hasValidPath(vector<vector<char>> const& grid)
{
	int cols = static_cast<int>(grid[0].size());
	vector<uint128> dp(cols);
	dp[0].lo = 1;
	for (auto& line : grid)
		for (int w = 0; w < cols; ++w) {
			if (w > 0) {
				// dp[w] |= dp[w - 1];
				dp[w].hi |= dp[w - 1].hi;
				dp[w].lo |= dp[w - 1].lo;
			}
			if (line[w] == '(') {
				// dp[w] <<= 1;
				dp[w].hi = (dp[w].hi << 1) | (dp[w].lo >> 63);
				dp[w].lo <<= 1;
			} else {
				// dp[w] >>= 1;
				dp[w].lo = (dp[w].lo >> 1) | (dp[w].hi << 63);
				dp[w].hi >>= 1;
			}
		}
	return static_cast<bool>(dp.back().lo & 1);
}

int main()
{
	vector<vector<char>>
		a = {{'(', '(', '('}, {')', '(', ')'}, {'(', '(', ')'}, {'(', '(', ')'}},
		b = {{')', ')'}, {'(', '('}};
	ToOut(hasValidPath(a));
	ToOut(hasValidPath(b));
}
