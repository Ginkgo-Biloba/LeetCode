﻿#include "leetcode.hpp"

/* 2570. 合并两个二维数组 - 求和法

给你两个 二维 整数数组 nums1 和 nums2.

nums1[i] = [idi, vali] 表示编号为 idi 的数字对应的值等于 vali 。
nums2[i] = [idi, vali] 表示编号为 idi 的数字对应的值等于 vali 。
每个数组都包含 互不相同 的 id ，并按 id 以 递增 顺序排列。

请你将两个数组合并为一个按 id 以递增顺序排列的数组，并符合下述条件：

只有在两个数组中至少出现过一次的 id 才能包含在结果数组内。
每个 id 在结果数组中 只能出现一次 ，并且其对应的值等于两个数组中该 id 所对应的值求和。如果某个数组中不存在该 id ，则假定其对应的值等于 0 。
返回结果数组。返回的数组需要按 id 以递增顺序排列。

示例 1：
输入：nums1 = [[1,2],[2,3],[4,5]], nums2 = [[1,4],[3,2],[4,1]]
输出：[[1,6],[2,3],[3,2],[4,6]]
解释：结果数组中包含以下元素：
- id = 1 ，对应的值等于 2 + 4 = 6 。
- id = 2 ，对应的值等于 3 。
- id = 3 ，对应的值等于 2 。
- id = 4 ，对应的值等于5 + 1 = 6 。

示例 2：
输入：nums1 = [[2,4],[3,6],[5,5]], nums2 = [[1,3],[4,3]]
输出：[[1,3],[2,4],[3,6],[4,3],[5,5]]
解释：不存在共同 id ，在结果数组中只需要包含每个 id 和其对应的值。

提示：
  1 <= nums1.length, nums2.length <= 200
  nums1[i].length == nums2[j].length == 2
  1 <= idi, vali <= 1000
  数组中的 id 互不相同
  数据均按 id 以严格递增顺序排列
*/

vector<vector<int>> mergeArrays(
	vector<vector<int>> const& A, vector<vector<int>> const& B)
{
	int alen = static_cast<int>(A.size());
	int blen = static_cast<int>(B.size());
	vector<vector<int>> ans;
	for (int a = 0, b = 0; a < alen || b < blen;) {
		if (a == alen)
			ans.push_back(B[b++]);
		else if (b == blen)
			ans.push_back(A[a++]);
		else {
			if (A[a][0] == B[b][0])
				ans.push_back({A[a][0], A[a++][1] + B[b++][1]});
			else if (A[a][0] < B[b][0])
				ans.push_back(A[a++]);
			else
				ans.push_back(B[b++]);
		}
	}
	return ans;
}

int main()
{
	ToOut(mergeArrays(
		{{1, 2}, {2, 3}, {4, 5}},
		{{1, 4}, {3, 2}, {4, 1}}));
	ToOut(mergeArrays(
		{{2, 4}, {3, 6}, {5, 5}},
		{{1, 3}, {4, 3}}));
}
