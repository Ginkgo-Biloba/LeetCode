﻿#include "leetcode.hpp"

/* 2453. 摧毁一系列目标

给你一个下标从 0 开始的数组 nums ，它包含若干正整数，表示数轴上你需要摧毁的目标所在的位置。
同时给你一个整数 space 。

你有一台机器可以摧毁目标。
给机器 输入 nums[i] ，这台机器会摧毁所有位置在 nums[i] + c * space 的目标，其中 c 是任意非负整数。你想摧毁 nums 中 尽可能多 的目标。

请你返回在摧毁数目最多的前提下，nums[i] 的 最小值 。

示例 1：
输入：nums = [3,7,8,1,1,5], space = 2
输出：1
解释：如果我们输入 nums[3] ，我们可以摧毁位于 1,3,5,7,9,... 这些位置的目标。
这种情况下， 我们总共可以摧毁 5 个目标（除了 nums[2]）。
没有办法摧毁多于 5 个目标，所以我们返回 nums[3] 。

示例 2：
输入：nums = [1,3,5,2,4,6], space = 2
输出：1
解释：输入 nums[0] 或者 nums[3] 都会摧毁 3 个目标。
没有办法摧毁多于 3 个目标。
由于 nums[0] 是最小的可以摧毁 3 个目标的整数，所以我们返回 1 。

示例 3：
输入：nums = [6,2,5], space = 100
输出：2
解释：无论我们输入哪个数字，都只能摧毁 1 个目标。输入的最小整数是 nums[1] 。

提示：
  1 <= nums.length <= 10^5
  1 <= nums[i] <= 10^9
  1 <= space <= 10^9
*/

int destroyTargets(vector<int> const& nums, int space)
{
	unordered_map<int, pair<int, int>> u;
	for (int i : nums) {
		int key = i % space;
		auto it = u.find(key);
		if (it == u.end())
			u[key] = {1, i};
		else {
			it->second.first += 1;
			it->second.second = min(it->second.second, i);
		}
	}
	int cnt = 0, ans = -1;
	for (auto& it : u) {
		if (cnt == it.second.first)
			ans = min(ans, it.second.second);
		if (cnt < it.second.first) {
			cnt = it.second.first;
			ans = it.second.second;
		}
	}
	return ans;
}

int main()
{
	ToOut(destroyTargets({3, 7, 8, 1, 1, 5}, 2));
	ToOut(destroyTargets({1, 3, 5, 2, 4, 6}, 2));
	ToOut(destroyTargets({6, 2, 5}, 100));
}
