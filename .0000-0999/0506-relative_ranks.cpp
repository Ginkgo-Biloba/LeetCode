﻿#include "leetcode.hpp"

/* 506. 相对名次

给出 N 名运动员的成绩，找出他们的相对名次并授予前三名对应的奖牌。前三名运动员将会被分别授予 “金牌”，“银牌” 和“ 铜牌”（"Gold Medal", "Silver Medal", "Bronze Medal"）。

(注：分数越高的选手，排名越靠前。)

示例 1:
输入: [5, 4, 3, 2, 1]
输出: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
解释: 前三名运动员的成绩为前三高的，因此将会分别被授予 “金牌”，“银牌”和“铜牌” ("Gold Medal", "Silver Medal" and "Bronze Medal").
余下的两名运动员，我们只需要通过他们的成绩计算将其相对名次即可。

提示:
    N 是一个正整数并且不会超过 10000。
    所有运动员的成绩都不相同。
*/

vector<string> findRelativeRanks(vector<int>& nums)
{
	vector<int> rank;
	vector<string> ans;
	int len = static_cast<int>(nums.size());
	rank.reserve(len);
	ans.resize(len);

	for (int i = 0; i < len; ++i)
		rank.push_back(i);
	std::sort(rank.begin(), rank.end(),
		[&nums](int x, int y) -> bool {
			return nums[x] > nums[y];
		});

	if (len > 0)
		string("Gold Medal").swap(ans[rank[0]]);
	if (len > 1)
		string("Silver Medal").swap(ans[rank[1]]);
	if (len > 2)
		string("Bronze Medal").swap(ans[rank[2]]);
	for (int i = 3; i < len; ++i)
		std::to_string(i + 1).swap(ans[rank[i]]);

	return ans;
}

int main()
{
	vector<int> nums = {10, 3, 8, 9, 4};
	ToOut(findRelativeRanks(nums));
}
