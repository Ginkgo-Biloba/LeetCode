﻿#include "leetcode.hpp"

/* 2155. 分组得分最高的所有下标

给你一个下标从 0 开始的二进制数组 nums ，数组长度为 n 。
nums 可以按下标 i（ 0 <= i <= n ）拆分成两个数组（可能为空）：numsleft 和 numsright 。

  numsleft 包含 nums 中从下标 0 到 i - 1 的所有元素（包括 0 和 i - 1 ），而 numsright 包含 nums 中从下标 i 到 n - 1 的所有元素（包括 i 和 n - 1 ）。
  如果 i == 0 ，numsleft 为 空 ，而 numsright 将包含 nums 中的所有元素。
  如果 i == n ，numsleft 将包含 nums 中的所有元素，而 numsright 为 空 。

下标 i 的 分组得分 为 numsleft 中 0 的个数和 numsright 中 1 的个数之 和 。

返回 分组得分 最高 的 所有不同下标 。
你可以按 任意顺序 返回答案。

示例 1：
输入：nums = [0,0,1,0]
输出：[2,4]
解释：按下标分组
- 0 ：numsleft 为 [] 。numsright 为 [0,0,1,0] 。得分为 0 + 1 = 1 。
- 1 ：numsleft 为 [0] 。numsright 为 [0,1,0] 。得分为 1 + 1 = 2 。
- 2 ：numsleft 为 [0,0] 。numsright 为 [1,0] 。得分为 2 + 1 = 3 。
- 3 ：numsleft 为 [0,0,1] 。numsright 为 [0] 。得分为 2 + 0 = 2 。
- 4 ：numsleft 为 [0,0,1,0] 。numsright 为 [] 。得分为 3 + 0 = 3 。
下标 2 和 4 都可以得到最高的分组得分 3 。
注意，答案 [4,2] 也被视为正确答案。

示例 2：
输入：nums = [0,0,0]
输出：[3]
解释：按下标分组
- 0 ：numsleft 为 [] 。numsright 为 [0,0,0] 。得分为 0 + 0 = 0 。
- 1 ：numsleft 为 [0] 。numsright 为 [0,0] 。得分为 1 + 0 = 1 。
- 2 ：numsleft 为 [0,0] 。numsright 为 [0] 。得分为 2 + 0 = 2 。
- 3 ：numsleft 为 [0,0,0] 。numsright 为 [] 。得分为 3 + 0 = 3 。
只有下标 3 可以得到最高的分组得分 3 。

示例 3：
输入：nums = [1,1]
输出：[0]
解释：按下标分组
- 0 ：numsleft 为 [] 。numsright 为 [1,1] 。得分为 0 + 2 = 2 。
- 1 ：numsleft 为 [1] 。numsright 为 [1] 。得分为 0 + 1 = 1 。
- 2 ：numsleft 为 [1,1] 。numsright 为 [] 。得分为 0 + 0 = 0 。
只有下标 0 可以得到最高的分组得分 2 。

提示：
  n == nums.length
  1 <= n <= 10^5
  nums[i] 为 0 或 1
*/

vector<int> maxScoreIndices(vector<int>& A)
{
	int n = static_cast<int>(A.size());
	vector<int> P;
	P.reserve(A.size() + 1);
	P.push_back(0);
	for (int i = 0; i < n; ++i)
		P[i + 1] = P[i] + A[i];
	int val = 0;
	for (int i = 0; i <= n; ++i) {
		int l = i - P[i];
		int r = P[n] - P[i];
		val = max(val, l + r);
	}
	vector<int> R;
	for (int i = 0; i <= n; ++i) {
		int l = i - P[i];
		int r = P[n] - P[i];
		if (val == l + r)
			R.push_back(i);
	}
	return R;
}

int main() { }
