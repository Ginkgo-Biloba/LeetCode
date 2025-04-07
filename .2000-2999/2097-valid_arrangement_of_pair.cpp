#include "leetcode.hpp"

/* 2097. 合法重新排列数对

给你一个下标从 0 开始的二维整数数组 pairs ，其中 pairs[i] = [starti, endi] 。
如果 pairs 的一个重新排列，满足对每一个下标 i （ 1 <= i < pairs.length ）都有 endi-1 == starti ，那么我们就认为这个重新排列是 pairs 的一个 合法重新排列 。

请你返回 任意一个 pairs 的合法重新排列。

注意：数据保证至少存在一个 pairs 的合法重新排列。

示例 1：
输入：pairs = [[5,1],[4,5],[11,9],[9,4]]
输出：[[11,9],[9,4],[4,5],[5,1]]
解释：
输出的是一个合法重新排列，因为每一个 endi-1 都等于 starti 。
end0 = 9 == 9 = start1
end1 = 4 == 4 = start2
end2 = 5 == 5 = start3

示例 2：
输入：pairs = [[1,3],[3,2],[2,1]]
输出：[[1,3],[3,2],[2,1]]
解释：
输出的是一个合法重新排列，因为每一个 endi-1 都等于 starti 。
end0 = 3 == 3 = start1
end1 = 2 == 2 = start2
重新排列后的数组 [[2,1],[1,3],[3,2]] 和 [[3,2],[2,1],[1,3]] 都是合法的。

示例 3：
输入：pairs = [[1,2],[1,3],[2,1]]
输出：[[1,2],[2,1],[1,3]]
解释：
输出的是一个合法重新排列，因为每一个 endi-1 都等于 starti 。
end0 = 2 == 2 = start1
end1 = 1 == 1 = start2

提示：
  1 <= pairs.length <= 10^5
  pairs[i].length == 2
  0 <= starti, endi <= 10^9
  starti != endi
  pairs 中不存在一模一样的数对。
  至少 存在 一个合法的 pairs 重新排列。
*/

// https://leetcode.com/problems/valid-arrangement-of-pairs/solutions/1618885/iterative-and-recursive/
// 抄的
vector<vector<int>> validArrangement(vector<vector<int>>& pairs)
{
	unordered_map<int, vector<int>> adj;
	unordered_map<int, int> deg;
	for (auto& p : pairs) {
		adj[p[0]].push_back(p[1]);
		deg[p[0]] += 1;
		deg[p[1]] -= 1;
	}
	int head = pairs[0][0];
	for (auto& kv : deg)
		if (kv.second > 0) {
			head = kv.first;
			break;
		}
	vector<int> route, stack;
	stack.push_back(head);
	while (!(stack.empty())) {
		while (!adj[stack.back()].empty()) {
			int i = stack.back();
			stack.push_back(adj[i].back());
			adj[i].pop_back();
		}
		route.push_back(stack.back());
		stack.pop_back();
	}
	vector<vector<int>> ret;
	for (size_t i = route.size() - 1; i--;)
		ret.push_back({route[i + 1], route[i]});
	return ret;
}

int main() { }
