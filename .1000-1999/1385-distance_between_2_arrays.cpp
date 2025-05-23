﻿#include "leetcode.hpp"

/* 1385. 两个数组间的距离值

给你两个整数数组 arr1，arr2 和一个整数 d，请你返回两个数组之间的 距离值 。

「距离值」 定义为符合此描述的元素数目：
对于元素 arr1[i] ，不存在任何元素 arr2[j] 满足 |arr1[i]-arr2[j]| <= d 。

示例 1：
输入：arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
输出：2
解释：
对于 arr1[0]=4 我们有：
|4-10|=6 > d=2
|4-9|=5 > d=2
|4-1|=3 > d=2
|4-8|=4 > d=2
对于 arr1[1]=5 我们有：
|5-10|=5 > d=2
|5-9|=4 > d=2
|5-1|=4 > d=2
|5-8|=3 > d=2
对于 arr1[2]=8 我们有：
|8-10|=2 <= d=2
|8-9|=1 <= d=2
|8-1|=7 > d=2
|8-8|=0 <= d=2

示例 2：
输入：arr1 = [1,4,2,3], arr2 = [-4,-3,6,10,20,30], d = 3
输出：2

示例 3：
输入：arr1 = [2,1,100,3], arr2 = [-5,-2,10,-3,7], d = 6
输出：1

提示：
  1 <= arr1.length, arr2.length <= 500
  -10^3 <= arr1[i], arr2[j] <= 10^3
  0 <= d <= 100
*/

int findTheDistanceValue_org(vector<int>& A, vector<int>& B, int d)
{
	int ans = 0;
	sort(B.begin(), B.end());
	auto ib0 = B.begin(), ib1 = B.end();
	for (int a : A) {
		auto it = lower_bound(ib0, ib1, a);
		if (it != ib1 && abs(*it - a) <= d)
			continue;
		if (it != ib0 && abs(*(it - 1) - a) <= d)
			continue;
		++ans;
	}
	return ans;
}

int findTheDistanceValue(vector<int>& A, vector<int>& B, int d)
{
	int const limit = 1000;
	vector<int> buf(2 * limit + 2);
	int* P = buf.data() + limit + 1;
	int ans = 0;
	for (int b : B)
		P[b] = 1;
	for (int i = -limit; i <= limit; ++i)
		P[i] += P[i - 1];
	for (int a : A) {
		int L = max(-limit, a - d);
		int R = min(+limit, a + d);
		ans += (P[L - 1] == P[R]);
	}
	return ans;
}

int main()
{
	vector<int>
		a = {4, 5, 8},
		b = {10, 9, 1, 8},
		c = {1, 4, 2, 3},
		d = {-4, -3, 6, 10, 20, 30},
		e = {2, 1, 100, 3},
		f = {-5, -2, 10, -3, 7};
	ToOut(findTheDistanceValue(a, b, 2));
	ToOut(findTheDistanceValue(c, d, 3));
	ToOut(findTheDistanceValue(e, f, 6));
}
