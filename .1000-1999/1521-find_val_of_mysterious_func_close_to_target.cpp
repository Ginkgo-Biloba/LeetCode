﻿#include "leetcode.hpp"

/* 5467. 找到最接近目标值的函数值

https://assets.leetcode.com/uploads/2020/07/09/change.png
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/07/19/change.png

func(arr, l, r)
{
  if (r < l)
    return -1000000000;
  ans = arr[l]
  for (i = l + 1; i <= r; i++)
    ans = ans & arr[i]
  return ans
}

Winston 构造了一个如上所示的函数 func 。
他有一个整数数组 arr 和一个整数 target ，他想找到让 |func(arr, l, r) - target| 最小的 l 和 r 。

请你返回 |func(arr, l, r) - target| 的最小值。

请注意， func 的输入参数 l 和 r 需要满足 0 <= l, r < arr.length 。

示例 1：
输入：arr = [9,12,3,7,15], target = 5
输出：2
解释：所有可能的 [l,r] 数对包括 [[0,0],[1,1],[2,2],[3,3],[4,4],[0,1],[1,2],[2,3],[3,4],[0,2],[1,3],[2,4],[0,3],[1,4],[0,4]]， Winston 得到的相应结果为 [9,12,3,7,15,8,0,3,7,0,0,3,0,0,0] 。最接近 5 的值是 7 和 3，所以最小差值为 2 。

示例 2：
输入：arr = [1000000,1000000,1000000], target = 1
输出：999999
解释：Winston 输入函数的所有可能 [l,r] 数对得到的函数值都为 1000000 ，所以最小差值为 999999 。

示例 3：
输入：arr = [1,2,4,8,16], target = 0
输出：0

提示：
  1 <= arr.length <= 10^5
  1 <= arr[i] <= 10^6
  0 <= target <= 10^7
*/

int closestToTarget(vector<int>& A, int target)
{
	int d = abs(A[0] - target);
	// 去重不需要 set，因为里面的数字是单调增的
	vector<int> Q, R;
	Q.reserve(33);
	R.reserve(33);
	for (int a : A) {
		R.clear();
		for (int q : Q)
			R.push_back(q & a);
		// a 是 R 里面最大的一个
		R.push_back(a);
		// 去重
		Q.clear();
		int rlen = static_cast<int>(R.size());
		for (int k = 0; k < rlen; ++k)
			if ((k == 0) || (R[k - 1] != R[k])) {
				Q.push_back(R[k]);
				d = min(d, abs(R[k] - target));
			}
	}
	return d;
}

int main()
{
	vector<int>
		a = {9, 12, 3, 7, 15},
		b = {70, 15, 21, 96};
	ToOut(closestToTarget(a, 5));
	ToOut(closestToTarget(b, 4));
}
