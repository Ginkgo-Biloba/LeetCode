#include "leetcode.hpp"

/* 2251. 花期内花的数目

给你一个下标从 0 开始的二维整数数组 flowers ，其中 flowers[i] = [starti, endi] 表示第 i 朵花的 花期 从 starti 到 endi （都 包含）。
同时给你一个下标从 0 开始大小为 n 的整数数组 people ，people[i] 是第 i 个人来看花的时间。

请你返回一个大小为 n 的整数数组 answer ，其中 answer[i]是第 i 个人到达时在花期内花的 数目 。

示例 1：
https://assets.leetcode.com/uploads/2022/03/02/ex1new.jpg
输入：flowers = [[1,6],[3,7],[9,12],[4,13]], people = [2,3,7,11]
输出：[1,2,2,2]
解释：上图展示了每朵花的花期时间，和每个人的到达时间。
对每个人，我们返回他们到达时在花期内花的数目。

示例 2：
https://assets.leetcode.com/uploads/2022/03/02/ex2new.jpg
输入：flowers = [[1,10],[3,3]], people = [3,3,2]
输出：[2,2,1]
解释：上图展示了每朵花的花期时间，和每个人的到达时间。
对每个人，我们返回他们到达时在花期内花的数目。

提示：
  1 <= flowers.length <= 5 * 10^4
  flowers[i].length == 2
  1 <= starti <= endi <= 10^9
  1 <= people.length <= 5 * 10^4
  1 <= people[i] <= 10^9
*/

vector<int> fullBloomFlowers1(
	vector<vector<int>>& flowers, vector<int>& people)
{
	int nbFlower = static_cast<int>(flowers.size());
	int nbPeople = static_cast<int>(people.size());
	vector<int> pidx(people.size()), ans(people.size());
	for (int i = 0; i < nbPeople; ++i)
		pidx[i] = i;
	std::sort(pidx.begin(), pidx.end(),
		[&people](int a, int b) -> bool { return people[a] < people[b]; });

	priority_queue<int, vector<int>, std::greater<int>> bloom;
	std::sort(flowers.begin(), flowers.end());
	for (int i = 0, f = 0; i < nbPeople; ++i) {
		int clock = people[pidx[i]];
		for (; f < nbFlower && flowers[f][0] <= clock; ++f)
			bloom.push(flowers[f][1]);
		while (!bloom.empty() && bloom.top() < clock)
			bloom.pop();
		ans[pidx[i]] = static_cast<int>(bloom.size());
	}
	return ans;
}

vector<int> fullBloomFlowers(
	vector<vector<int>>& flowers, vector<int>& people)
{
	vector<int> L, R;
	for (auto& f : flowers) {
		L.push_back(f[0]);
		R.push_back(f[1]);
	}
	std::sort(L.begin(), L.end());
	std::sort(R.begin(), R.end());
	vector<int> ans;
	for (int p : people) {
		ptrdiff_t a = std::upper_bound(L.begin(), L.end(), p) - L.begin();
		ptrdiff_t b = std::lower_bound(R.begin(), R.end(), p) - R.begin();
		ans.push_back(static_cast<int>(a - b));
	}
	return ans;
}

int main()
{
	vector<vector<int>>
		f1 = {{1, 6}, {3, 7}, {9, 12}, {4, 13}},
		f2 = {{1, 10}, {3, 3}};
	vector<int>
		p1 = {2, 3, 7, 11},
		p2 = {3, 3, 2};
	ToOut(fullBloomFlowers(f1, p1));
	ToOut(fullBloomFlowers(f2, p2));
}
