﻿#include "leetcode.hpp"

/* 496. 下一个更大元素 I

给定两个没有重复元素的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。找到 nums1 中每个元素在 nums2 中的下一个比其大的值。

nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出-1。

示例 1:

输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
输出: [-1,3,-1]
解释:
    对于num1中的数字4，你无法在第二个数组中找到下一个更大的数字，因此输出 -1。
    对于num1中的数字1，第二个数组中数字1右边的下一个较大数字是 3。
    对于num1中的数字2，第二个数组中没有下一个更大的数字，因此输出 -1。

示例 2:

输入: nums1 = [2,4], nums2 = [1,2,3,4].
输出: [3,-1]
解释:
    对于num1中的数字2，第二个数组中的下一个较大数字是3。
    对于num1中的数字4，第二个数组中没有下一个更大的数字，因此输出 -1。

注意:
    nums1和nums2中所有元素是唯一的。
    nums1和nums2 的数组大小都不超过1000。
*/

vector<int> nextGreaterElement(
	vector<int>& check,
	vector<int>& nums)
{
	int len = static_cast<int>(nums.size());
	std::unordered_map<int, int> lut;
	lut.reserve(len);
	vector<int> stk;
	stk.reserve(len);
	for (int i = len - 1; i >= 0; --i) {
		while (!stk.empty() && stk.back() < nums[i])
			stk.pop_back();
		lut[nums[i]] = (stk.empty() ? -1 : stk.back());
		stk.push_back(nums[i]);
	}
	stk.clear();
	for (int c : check)
		stk.push_back(lut[c]);
	return stk;
}

int main()
{
	vector<int> nums1 = {4, 1, 2};
	vector<int> nums2 = {1, 3, 4, 2};
	ToOut(nextGreaterElement(nums1, nums2));
}
