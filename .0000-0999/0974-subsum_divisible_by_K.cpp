﻿#include "leetcode.hpp"

/* 974. 和可被 K 整除的子数组

给定一个整数数组 A，返回其中元素之和可被 K 整除的（连续、非空）子数组的数目。

示例：
输入：A = [4,5,0,-2,-3,1], K = 5
输出：7
解释：
有 7 个子数组满足其元素之和可被 K = 5 整除：
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

提示：
  1 <= A.length <= 30000
  -10000 <= A[i] <= 10000
  2 <= K <= 10000
*/

int subarraysDivByK(vector<int>& A, int K)
{
	int len = static_cast<int>(A.size());
	int num = 0, cur = 0;
	vector<int> mod(K);
	// 可以跟空字符串搭配，也就是只有当前数字
	mod[0] = 1;

	for (int i = 0; i < len; ++i) {
		// C++ 整数除法向 0 取整，所以 (-2)/5=0...(-2)
		cur = (cur + A[i]) % K;
		// (-2)+5=3
		if (cur < 0)
			cur += K;
		num += mod[cur];
		mod[cur] += 1;
	}

	return num;
}

int main()
{
	vector<int> a = {4, 5, 0, -2, -3, 1};
	ToOut(subarraysDivByK(a, 5));
}
