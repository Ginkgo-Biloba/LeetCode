#include "leetcode.hpp"

/* 120. 三角形最小路径和

给定一个三角形，找出自顶向下的最小路径和。
每一步只能移动到下一行中相邻的结点上。

例如，给定三角形：

> [
>      [2],
>     [3,4],
>    [6,5,7],
>   [4,1,8,3]
> ]

自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

说明：
如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
*/

inline int adds(int a, int b)
{
	return a < INT_MAX - b ? a + b : INT_MAX;
}

int minimumTotal(vector<vector<int>>& triangle)
{
	int rows = static_cast<int>(triangle.size());
	if (rows == 0)
		return 0;
	if (rows == 1)
		return triangle[0][0];
	int ans = INT_MAX;
	for (int h = 1; h < rows; ++h) {
		int* A = triangle[h - 1].data();
		int* B = triangle[h].data();
		B[0] = adds(B[0], A[0]);
		B[h] = adds(B[h], A[h - 1]);
		for (int w = 1; w < h; ++w)
			B[w] = adds(B[w], min(A[w - 1], A[w]));
	}
	for (int w = 0; w <= rows; ++w)
		ans = min(ans, triangle[rows - 1][w]);
	return ans;
}

int main()
{
	ToOut(minimumTotal({{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}}));
}
