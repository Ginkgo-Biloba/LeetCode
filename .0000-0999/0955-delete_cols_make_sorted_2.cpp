﻿#include "leetcode.hpp"

/* 955. 删列造序 II

给定由 N 个小写字母字符串组成的数组 A，其中每个字符串长度相等。

选取一个删除索引序列，对于 A 中的每个字符串，删除对应每个索引处的字符。

比如，有 A = ["abcdef", "uvwxyz"]，删除索引序列 {0, 2, 3}，删除后 A 为["bef", "vyz"]。

假设，我们选择了一组删除索引 D，那么在执行删除操作之后，最终得到的数组的元素是按 字典序（A[0] <= A[1] <= A[2] ... <= A[A.length - 1]）排列的，然后请你返回 D.length 的最小可能值。

示例 1：
输入：["ca","bb","ac"]
输出：1
解释：
删除第一列后，A = ["a", "b", "c"]。
现在 A 中元素是按字典排列的 (即，A[0] <= A[1] <= A[2])。
我们至少需要进行 1 次删除，因为最初 A 不是按字典序排列的，所以答案是 1。

示例 2：
输入：["xc","yb","za"]
输出：0
解释：
A 的列已经是按字典序排列了，所以我们不需要删除任何东西。
注意 A 的行不需要按字典序排列。
也就是说，A[0][0] <= A[0][1] <= ... 不一定成立。

示例 3：
输入：["zyx","wvu","tsr"]
输出：3
解释：
我们必须删掉每一列。

提示：
  1 <= A.length <= 100
  1 <= A[i].length <= 100
*/

// https://leetcode.com/problems/delete-columns-to-make-sorted-ii/discuss/203182/JavaC%2B%2BPython-Greedy-Solution-O(MN)
// 抄的
int minDeletionSize(vector<string>& A)
{
	int rows = static_cast<int>(A.size());
	int cols = static_cast<int>(A[0].size());
	int h, w, sum = 0;
	// 表示当前行字典序是否在上一行后面。首行没用到
	vector<char> sorted(rows);

	for (w = 0; w < cols; ++w) {
		for (h = 1; h < rows; ++h)
			if (!sorted[h] && A[h - 1][w] > A[h][w]) {
				// 删掉这一列
				++sum;
				break;
			}
		if (h < rows)
			continue;
		// 不需要删除，更新排序
		for (h = 1; h < rows; ++h) {
			if (A[h - 1][w] < A[h][w])
				sorted[h] = 1;
		}
	}

	return sum;
}

int main()
{
	vector<string>
		a = {"ca", "bb", "ac"},
		b = {"xc", "yb", "za"},
		c = {"zyx", "wvu", "tsr"};
	ToOut(minDeletionSize(a));
	ToOut(minDeletionSize(b));
	ToOut(minDeletionSize(c));
}
