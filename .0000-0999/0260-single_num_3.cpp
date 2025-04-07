﻿#include "leetcode.hpp"

/* 260. 只出现一次的数字 III

给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。

示例 :

输入: [1,2,1,3,2,5]
输出: [3,5]

注意：
  结果输出的顺序并不重要，对于上面的例子， [5, 3] 也是正确答案。
  你的算法应该具有线性时间复杂度。
  你能否仅使用常数空间复杂度来实现？
*/

vector<int> singleNumber(vector<int>& A)
{
	int len = static_cast<int>(A.size());
	int n0 = 0, n1 = 0;
	unsigned mask = 0;
	for (int i = 0; i < len; ++i)
		mask ^= A[i];
	mask = mask & (~(mask - 1));
	for (int i = 0; i < len; ++i) {
		if (A[i] & mask)
			n0 ^= A[i];
		else
			n1 ^= A[i];
	}
	return {n0, n1};
}

int main()
{
	vector<int>
		a = {1, 2, 1, 3, 2, 5},
		b = {INT_MAX, INT_MIN};
	ToOut(singleNumber(a));
	ToOut(singleNumber(b));
}
