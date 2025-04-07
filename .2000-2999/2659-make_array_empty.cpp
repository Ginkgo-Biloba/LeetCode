#include "leetcode.hpp"

/* 2659. 将数组清空

给你一个包含若干 互不相同 整数的数组 nums ，你需要执行以下操作 直到数组为空 ：
  如果数组中第一个元素是当前数组中的 最小值 ，则删除它。
  否则，将第一个元素移动到数组的 末尾 。

请你返回需要多少个操作使 nums 为空。

示例 1：
输入：nums = [3,4,-1]
输出：5
Operation	Array
1	[4, -1, 3]
2	[-1, 3, 4]
3	[3, 4]
4	[4]
5	[]

示例 2：
输入：nums = [1,2,4,3]
输出：5
Operation	Array
1	[2, 4, 3]
2	[4, 3]
3	[3, 4]
4	[4]
5	[]

示例 3：
输入：nums = [1,2,3]
输出：3
Operation	Array
1	[2, 3]
2	[3]
3	[]

提示：
  1 <= nums.length <= 10^5
  -10^9 <= nums[i] <= 10^9
  nums 中的元素 互不相同 。
*/

// https://leetcode.cn/problems/make-array-empty/solutions/2250783/shu-zhuang-shu-zu-mo-ni-pythonjavacgo-by-ygvb/
// 抄的
long long countOperationsToEmptyArray(
	vector<int> const& A)
{
	int n = static_cast<int>(A.size());
	long long ans = n;
	vector<int> index(n);
	for (int i = 0; i < n; ++i)
		index[i] = i;
	std::sort(index.begin(), index.end(),
		[&A](int i, int k) { return A[i] < A[k]; });
	for (int i = 1; i < n; ++i)
		if (index[i] < index[i - 1])
			ans += n - i;
	return ans;
}

int main()
{
	ToOut(countOperationsToEmptyArray({3, 4, -1}));
	ToOut(countOperationsToEmptyArray({1, 2, 4, 3}));
	ToOut(countOperationsToEmptyArray({1, 2, 3}));
}
