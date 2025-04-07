#include "leetcode.hpp"

/* 2564. 子字符串异或查询

给你一个 二进制字符串 s 和一个整数数组 queries ，其中 queries[i] = [firsti, secondi] 。

对于第 i 个查询，找到 s 的 最短子字符串 ，它对应的 十进制值 val 与 firsti 按位异或 得到 secondi ，换言之，val ^ firsti == secondi 。

第 i 个查询的答案是子字符串 [lefti, righti] 的两个端点（下标从 0 开始），如果不存在这样的子字符串，则答案为 [-1, -1] 。如果有多个答案，请你选择 lefti 最小的一个。

请你返回一个数组 ans ，其中 ans[i] = [lefti, righti] 是第 i 个查询的答案。

子字符串 是一个字符串中一段连续非空的字符序列。

示例 1：
输入：s = "101101", queries = [[0,5],[1,2]]
输出：[[0,2],[2,3]]
解释：第一个查询，端点为 [0,2] 的子字符串为 "101" ，对应十进制数字 5 ，且 5 ^ 0 = 5 ，所以第一个查询的答案为 [0,2]。第二个查询中，端点为 [2,3] 的子字符串为 "11" ，对应十进制数字 3 ，且 3 ^ 1 = 2 。所以第二个查询的答案为 [2,3] 。

示例 2：
输入：s = "0101", queries = [[12,8]]
输出：[[-1,-1]]
解释：这个例子中，没有符合查询的答案，所以返回 [-1,-1] 。

示例 3：
输入：s = "1", queries = [[4,5]]
输出：[[0,0]]
解释：这个例子中，端点为 [0,0] 的子字符串对应的十进制值为 1 ，且 1 ^ 4 = 5 。所以答案为 [0,0] 。

提示：
  1 <= s.length <= 10^4
  s[i] 要么是 '0' ，要么是 '1' 。
  1 <= queries.length <= 10^5
  0 <= firsti, secondi <= 10^9
*/

vector<vector<int>> substringXorQueries(string s,
	vector<vector<int>> const& queries)
{
	unordered_map<int, pair<int, int>> u;
	int n = static_cast<int>(s.size());
	for (int h = n; h--;) {
		int val = 0;
		if (s[h] == '0') {
			u[0] = {h, h};
			continue;
		}
		for (int i = h, iend = min(h + 32, n); i < iend; ++i) {
			val = val * 2 + (s[i] - '0');
			u[val] = {h, i};
		}
	}
	int nbQ = static_cast<int>(queries.size());
	vector<vector<int>> ans(nbQ);
	for (int i = 0; i < nbQ; ++i) {
		int val = queries[i][0] ^ queries[i][1];
		auto it = u.find(val);
		if (it == u.end())
			ans[i] = {-1, -1};
		else
			ans[i] = {it->second.first, it->second.second};
	}
	return ans;
}

int main()
{
	ToOut(substringXorQueries("101101", {{0, 5}, {1, 2}}));
	ToOut(substringXorQueries("0101", {{12, 8}}));
	ToOut(substringXorQueries("1", {{4, 5}}));
	ToOut(substringXorQueries("111010110",
		{{4, 2}, {3, 3}, {6, 4}, {9, 9}, {10, 28}, {0, 470}, {5, 83}, {10, 28}, {8, 15}, {6, 464}, {0, 3}, {5, 8}, {7, 7}, {8, 8}, {6, 208}, {9, 15}, {2, 2}, {9, 95}}));
}
