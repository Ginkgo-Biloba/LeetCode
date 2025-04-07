﻿#include "leetcode.hpp"

/* 881. 救生艇

第 i 个人的体重为 people[i]，每艘船可以承载的最大重量为 limit。

每艘船最多可同时载两人，但条件是这些人的重量之和最多为 limit。

返回载到每一个人所需的最小船数。(保证每个人都能被船载)。

示例 1：
输入：people = [1,2], limit = 3
输出：1
解释：1 艘船载 (1, 2)

示例 2：
输入：people = [3,2,2,1], limit = 3
输出：3
解释：3 艘船分别载 (1, 2), (2) 和 (3)

示例 3：
输入：people = [3,5,3,4], limit = 5
输出：4
解释：4 艘船分别载 (3), (3), (4), (5)

提示：
  1 <= people.length <= 50000
  1 <= people[i] <= limit <= 30000
*/

int numRescueBoats(vector<int>& people, int limit)
{
	int step = 0;
	int L = 0, R = static_cast<int>(people.size()) - 1;
	sort(people.begin(), people.end());
	for (; L <= R; ++step) {
		if (people[R] + people[L] <= limit) {
			++L;
			--R;
		} else
			--R;
	}
	return step;
}

int main()
{
	vector<int>
		a = {1, 2},
		b = {3, 2, 2, 1},
		c = {3, 5, 3, 4};
	ToOut(numRescueBoats(a, 3));
	ToOut(numRescueBoats(b, 3));
	ToOut(numRescueBoats(c, 5));
}
