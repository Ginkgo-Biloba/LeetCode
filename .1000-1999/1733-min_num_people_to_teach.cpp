﻿#include "leetcode.hpp"

/* 1733. 需要教语言的最少人数

在一个由 m 个用户组成的社交网络里，我们获取到一些用户之间的好友关系。
两个用户之间可以相互沟通的条件是他们都掌握同一门语言。

给你一个整数 n ，数组 languages 和数组 friendships ，它们的含义如下：
  总共有 n 种语言，编号从 1 到 n 。
  languages[i] 是第 i 位用户掌握的语言集合。
  friendships[i] = [u​​​​​​i​​​, v​​​​​​i] 表示 u​​​​​​​​​​​i​​​​​ 和 vi 为好友关系。

你可以选择 一门 语言并教会一些用户，使得所有好友之间都可以相互沟通。
请返回你 最少 需要教会多少名用户。
请注意，好友关系没有传递性，也就是说如果 x 和 y 是好友，且 y 和 z 是好友， x 和 z 不一定是好友。

示例 1：
输入：n = 2, languages = [[1],[2],[1,2]], friendships = [[1,2],[1,3],[2,3]]
输出：1
解释：你可以选择教用户 1 第二门语言，也可以选择教用户 2 第一门语言。

示例 2：
输入：n = 3, languages = [[2],[1,3],[1,2],[3]], friendships = [[1,4],[1,2],[3,4],[2,3]]
输出：2
解释：教用户 1 和用户 3 第三门语言，需要教 2 名用户。

提示：
  2 <= n <= 500
  languages.length == m
  1 <= m <= 500
  1 <= languages[i].length <= n
  1 <= languages[i][j] <= n
  1 <= u​​​​​​i < v​​​​​​i <= languages.length
  1 <= friendships.length <= 500
  所有的好友关系 (u​​​​​i, v​​​​​​i) 都是唯一的。
  languages[i] 中包含的值互不相同。
*/

int minimumTeachings(int n, vector<vector<int>>& L, vector<vector<int>>& F)
{
	vector<array<int, 2>> C;
	for (auto& A : L)
		sort(A.begin(), A.end());
	for (auto& f : F) {
		bool can = false;
		int A = f[0] - 1, B = f[1] - 1;
		auto itstart = L[B].begin(), itend = L[B].end();
		for (auto& a : L[A]) {
			auto it = lower_bound(itstart, itend, a);
			if (it != itend && (*it) == a) {
				can = true;
				break;
			}
		}
		if (!can)
			C.push_back({A, B});
	}

	vector<int> S;
	for (auto& c : C) {
		S.push_back(c[0]);
		S.push_back(c[1]);
	}
	sort(S.begin(), S.end());
	S.erase(unique(S.begin(), S.end()), S.end());

	int all = 0;
	for (; n > 0; --n) {
		int cur = 0;
		for (int s : S) {
			auto it = lower_bound(L[s].begin(), L[s].end(), n);
			if (it != L[s].end() && (*it) == n)
				++cur;
		}
		all = max(all, cur);
	}
	return static_cast<int>(S.size()) - all;
}

int main()
{
	vector<vector<int>>
		a = {{1}, {2}, {1, 2}},
		b = {{1, 2}, {1, 3}, {2, 3}},
		c = {{2}, {1, 3}, {1, 2}, {3}},
		d = {{1, 4}, {1, 2}, {3, 4}, {2, 3}};
	ToOut(minimumTeachings(2, a, b));
	ToOut(minimumTeachings(3, c, d));
}
