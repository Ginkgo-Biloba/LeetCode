#include "leetcode.hpp"

/* 2491. 划分技能点相等的团队

给你一个正整数数组 skill ，数组长度为 偶数 n ，其中 skill[i] 表示第 i 个玩家的技能点。
将所有玩家分成 n / 2 个 2 人团队，使每一个团队的技能点之和 相等 。

团队的 化学反应 等于团队中玩家的技能点 乘积 。

返回所有团队的 化学反应 之和，如果无法使每个团队的技能点之和相等，则返回 -1 。

示例 1：
输入：skill = [3,2,5,1,3,4]
输出：22
解释：
将玩家分成 3 个团队 (1, 5), (2, 4), (3, 3) ，每个团队的技能点之和都是 6 。
所有团队的化学反应之和是 1 * 5 + 2 * 4 + 3 * 3 = 5 + 8 + 9 = 22 。

示例 2：
输入：skill = [3,4]
输出：12
解释：
两个玩家形成一个团队，技能点之和是 7 。
团队的化学反应是 3 * 4 = 12 。

示例 3：
输入：skill = [1,1,2,3]
输出：-1
解释：
无法将玩家分成每个团队技能点都相等的若干个 2 人团队。

提示：
  2 <= skill.length <= 10^5
  skill.length 是偶数
  1 <= skill[i] <= 1000
*/

long long dividePlayers(vector<int> skill)
{
	int n = static_cast<int>(skill.size());
	std::sort(skill.begin(), skill.end());
	int need = -1;
	long long sum = 0;
	for (int i = 0, k = n - 1; i < k; ++i, --k) {
		int a = skill[i], b = skill[k];
		if (i == 0)
			need = a + b;
		if (a + b != need)
			return -1;
		sum += a * b;
	}
	return sum;
}

int main()
{
	ToOut(dividePlayers({3, 2, 5, 1, 3, 4}));
	ToOut(dividePlayers({3, 4}));
	ToOut(dividePlayers({1, 1, 2, 3}));
}
