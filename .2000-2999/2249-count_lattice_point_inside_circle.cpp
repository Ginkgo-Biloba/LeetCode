#include "leetcode.hpp"

/* 2249. 统计圆内格点数目

给你一个二维整数数组 circles ，其中 circles[i] = [xi, yi, ri] 表示网格上圆心为 (xi, yi) 且半径为 ri 的第 i 个圆，返回出现在 至少一个 圆内的 格点数目 。

注意：
  格点 是指整数坐标对应的点。
  圆周上的点 也被视为出现在圆内的点。

示例 1：
https://assets.leetcode.com/uploads/2022/03/02/exa-11.png
输入：circles = [[2,2,1]]
输出：5
解释：
给定的圆如上图所示。
出现在圆内的格点为 (1, 2)、(2, 1)、(2, 2)、(2, 3) 和 (3, 2)，在图中用绿色标识。
像 (1, 1) 和 (1, 3) 这样用红色标识的点，并未出现在圆内。
因此，出现在至少一个圆内的格点数目是 5 。

示例 2：
https://assets.leetcode.com/uploads/2022/03/02/exa-22.png
输入：circles = [[2,2,2],[3,4,1]]
输出：16
解释：
给定的圆如上图所示。
共有 16 个格点出现在至少一个圆内。
其中部分点的坐标是 (0, 2)、(2, 0)、(2, 4)、(3, 2) 和 (4, 4) 。

提示：
  1 <= circles.length <= 200
  circles[i].length == 3
  1 <= xi, yi <= 100
  1 <= ri <= min(xi, yi)
*/

static int square(int x) { return x * x; }

int countLatticePoints(vector<vector<int>>& circles)
{
	int ans = 0;
	int const lo = -100, hi = 200;
	for (int x = lo; x <= hi; ++x)
		for (int y = lo; y <= hi; ++y)
			for (auto& c : circles) {
				int d2 = square(c[0] - x) + square(c[1] - y);
				if (d2 <= square(c[2])) {
					++ans;
					break;
				}
			}
	return ans;
}

int main()
{
	vector<vector<int>>
		a = {{2, 2, 1}},
		b = {{2, 2, 2}, {3, 4, 1}};
	ToOut(countLatticePoints(a));
	ToOut(countLatticePoints(b));
}
