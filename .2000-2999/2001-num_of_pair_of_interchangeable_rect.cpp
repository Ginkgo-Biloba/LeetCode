﻿#include "leetcode.hpp"

/* 2001. 可互换矩形的组数

用一个下标从 0 开始的二维整数数组 rectangles 来表示 n 个矩形，其中 rectangles[i] = [widthi, heighti] 表示第 i 个矩形的宽度和高度。

如果两个矩形 i 和 j（i < j）的宽高比相同，则认为这两个矩形 可互换 。
更规范的说法是，两个矩形满足 widthi/heighti == widthj/heightj（使用实数除法而非整数除法），则认为这两个矩形 可互换 。

计算并返回 rectangles 中有多少对 可互换 矩形。

示例 1：
输入：rectangles = [[4,8],[3,6],[10,20],[15,30]]
输出：6
解释：下面按下标（从 0 开始）列出可互换矩形的配对情况：
- 矩形 0 和矩形 1 ：4/8 == 3/6
- 矩形 0 和矩形 2 ：4/8 == 10/20
- 矩形 0 和矩形 3 ：4/8 == 15/30
- 矩形 1 和矩形 2 ：3/6 == 10/20
- 矩形 1 和矩形 3 ：3/6 == 15/30
- 矩形 2 和矩形 3 ：10/20 == 15/30

示例 2：
输入：rectangles = [[4,5],[7,8]]
输出：0
解释：不存在成对的可互换矩形。

提示：
  n == rectangles.length
  1 <= n <= 10^5
  rectangles[i].length == 2
  1 <= widthi, heighti <= 10^5
*/

long long interchangeableRectangles1(vector<vector<int>>& rectangles)
{
	map<int64_t, int64_t> M;
	int64_t ans = 0;
	for (auto& r : rectangles) {
		int a = r[0], b = r[1];
		while (b) {
			int t = a % b;
			a = b;
			b = t;
		}
		b = r[1] / a;
		a = r[0] / a;
		M[(static_cast<int64_t>(a) << 20) + b] += 1;
	}
	for (auto& p : M)
		ans += p.second * (p.second - 1) / 2;
	return ans;
}

long long interchangeableRectangles(vector<vector<int>>& rectangles)
{
	vector<pair<int, int>> R;
	for (auto& r : rectangles) {
		int a = r[0], b = r[1];
		while (b) {
			int t = a % b;
			a = b;
			b = t;
		}
		R.emplace_back(r[0] / a, r[1] / a);
	}
	long long sum = 0;
	int h = 0, i = 1;
	int len = static_cast<int>(R.size());
	sort(R.begin(), R.end());
	for (; i <= len; ++i) {
		if (i < len && R[i - 1] == R[i])
			continue;
		int64_t k = i - h;
		sum += k * (k - 1) / 2;
		h = i;
	}
	return sum;
}

int main() { }
