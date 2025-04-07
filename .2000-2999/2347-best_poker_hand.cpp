#include "leetcode.hpp"

/* 2347. 最好的扑克手牌

给你一个整数数组 ranks 和一个字符数组 suit 。
你有 5 张扑克牌，第 i 张牌大小为 ranks[i] ，花色为 suits[i] 。

下述是从好到坏你可能持有的 手牌类型 ：
  "Flush"：同花，五张相同花色的扑克牌。
  "Three of a Kind"：三条，有 3 张大小相同的扑克牌。
  "Pair"：对子，两张大小一样的扑克牌。
  "High Card"：高牌，五张大小互不相同的扑克牌。

请你返回一个字符串，表示给定的 5 张牌中，你能组成的 最好手牌类型 。

注意：返回的字符串 大小写 需与题目描述相同。

示例 1：
输入：ranks = [13,2,3,1,9], suits = ["a","a","a","a","a"]
输出："Flush"
解释：5 张扑克牌的花色相同，所以返回 "Flush" 。

示例 2：
输入：ranks = [4,4,2,4,4], suits = ["d","a","a","b","c"]
输出："Three of a Kind"
解释：第一、二和四张牌组成三张相同大小的扑克牌，所以得到 "Three of a Kind" 。
注意我们也可以得到 "Pair" ，但是 "Three of a Kind" 是更好的手牌类型。
有其他的 3 张牌也可以组成 "Three of a Kind" 手牌类型。

示例 3：
输入：ranks = [10,10,2,12,9], suits = ["a","b","c","a","d"]
输出："Pair"
解释：第一和第二张牌大小相同，所以得到 "Pair" 。
我们无法得到 "Flush" 或者 "Three of a Kind" 。

提示：
  ranks.length == suits.length == 5
  1 <= ranks[i] <= 13
  'a' <= suits[i] <= 'd'
  任意两张扑克牌不会同时有相同的大小和花色。
*/

string bestHand(
	vector<int> const& ranks, vector<char> const& suits)
{
	int S0 = 0;
	int count[14] = {0};
	for (int i = 0; i < 5; ++i) {
		S0 += suits[i] == suits[0];
		count[ranks[i]] += 1;
	}
	if (S0 == 5) return "Flush";
	int eq = 0;
	for (int i = 1; i <= 13; ++i)
		eq = max(eq, count[i]);
	return eq >= 3 ? "Three of a Kind"
		: eq == 2    ? "Pair"
								 : "High Card";
}

int main()
{
	vector<int>
		r1 = {13, 2, 3, 1, 9},
		r2 = {4, 4, 2, 4, 4},
		r3 = {10, 10, 2, 12, 9};
	vector<char>
		s1 = {'a', 'a', 'a', 'a', 'a'},
		s2 = {'d', 'a', 'a', 'b', 'c'},
		s3 = {'a', 'b', 'c', 'a', 'd'};
	ToOut(bestHand(r1, s1));
	ToOut(bestHand(r2, s2));
	ToOut(bestHand(r3, s3));
}
