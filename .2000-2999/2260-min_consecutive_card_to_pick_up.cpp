#include "leetcode.hpp"

/* 2260. 必须拿起的最小连续卡牌数

给你一个整数数组 cards ，其中 cards[i] 表示第 i 张卡牌的 值 。
如果两张卡牌的值相同，则认为这一对卡牌 匹配 。

返回你必须拿起的最小连续卡牌数，以使在拿起的卡牌中有一对匹配的卡牌。
如果无法得到一对匹配的卡牌，返回 -1 。

示例 1：
输入：cards = [3,4,2,3,4,7]
输出：4
解释：拿起卡牌 [3,4,2,3] 将会包含一对值为 3 的匹配卡牌。注意，拿起 [4,2,3,4] 也是最优方案。

示例 2：
输入：cards = [1,0,5,3]
输出：-1
解释：无法找出含一对匹配卡牌的一组连续卡牌。

提示：
  1 <= cards.length <= 10^5
  0 <= cards[i] <= 10^6
*/

int minimumCardPickup(vector<int> const& cards)
{
	int n = static_cast<int>(cards.size());
	vector<int> index(n);
	for (int i = 0; i < n; ++i)
		index[i] = i;
	std::sort(index.begin(), index.end(),
		[&cards](int a, int b) -> bool { return std::tie(cards[a], a) < std::tie(cards[b], b); });
	int ans = n + 1;
	for (int i = 1; i < n; ++i) {
		if (cards[index[i - 1]] == cards[index[i]])
			ans = min(ans, index[i] - index[i - 1] + 1);
	}
	return ans > n ? -1 : ans;
}

int main()
{
	ToOut(minimumCardPickup({3, 4, 2, 3, 4, 7}));
	ToOut(minimumCardPickup({1, 0, 5, 3}));
	ToOut(minimumCardPickup({1, 2, 1}));
}
