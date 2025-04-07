#include "leetcode.hpp"

/* 1998. 数组的最大公因数排序

给你一个整数数组 nums ，你可以在 nums 上执行下述操作 任意次 ：

  如果 gcd(nums[i], nums[j]) > 1 ，交换 nums[i] 和 nums[j] 的位置。
  其中 gcd(nums[i], nums[j]) 是 nums[i] 和 nums[j] 的最大公因数。

如果能使用上述交换方式将 nums 按 非递减顺序 排列，返回 true ；否则，返回 false 。

示例 1：
输入：nums = [7,21,3]
输出：true
解释：可以执行下述操作完成对 [7,21,3] 的排序：
- 交换 7 和 21 因为 gcd(7,21) = 7 。nums = [21,7,3]
- 交换 21 和 3 因为 gcd(21,3) = 3 。nums = [3,7,21]

示例 2：
输入：nums = [5,2,6,2]
输出：false
解释：无法完成排序，因为 5 不能与其他元素交换。

示例 3：
输入：nums = [10,5,9,3,15]
输出：true
解释：
可以执行下述操作完成对 [10,5,9,3,15] 的排序：
- 交换 10 和 15 因为 gcd(10,15) = 5 。nums = [15,5,9,3,10]
- 交换 15 和 3 因为 gcd(15,3) = 3 。nums = [3,5,9,15,10]
- 交换 10 和 15 因为 gcd(10,15) = 5 。nums = [3,5,9,10,15]

提示：
  1 <= nums.length <= 3 * 10^4
  2 <= nums[i] <= 10^5
*/

class Solution {
	vector<int> prime, parent, buffer;

	int find(int x)
	{
		int n = parent[x];
		if (parent[n] == n)
			return n;
		buffer.clear();
		buffer.push_back(x);
		while (parent[n] != n) {
			buffer.push_back(n);
			n = parent[n];
		}
		for (int p : buffer)
			parent[p] = n;
		return n;
	}

	void merge(int a, int b)
	{
		a = find(a);
		b = find(b);
		parent[max(a, b)] = min(a, b);
	}

	void get_prime(int limit)
	{
		// 只需要 sqrt(limit + 1) 以内的质数
		limit = (int)sqrt(limit + 1.0);
		vector<char> q(limit + 1);
		for (int i = 2; i <= limit; ++i) {
			if (q[i])
				continue;
			for (int k = i * i; k <= limit; k += i)
				q[k] = 1;
		}
		prime.clear();
		for (int i = 2; i <= limit; ++i)
			if (!q[i])
				prime.push_back(i);
	}

public:
	bool gcdSort(vector<int>& A)
	{
		int limit = 0;
		int len = static_cast<int>(A.size());
		for (int x : A)
			limit = max(limit, x);

		get_prime(limit);
		parent.resize(limit + 1);
		for (int i = 0; i <= limit; ++i)
			parent[i] = i;

		for (int x : A) {
			int n = x;
			for (int p : prime) {
				if (p * p > n)
					break;
				if (n % p == 0) {
					merge(p, x);
					while (n % p == 0)
						n /= p;
				}
			}
			if (n > 1)
				merge(n, x);
		}

		vector<int> B = A;
		sort(B.begin(), B.end());
		for (int i = 0; i < len; ++i) {
			int a = find(A[i]);
			int b = find(B[i]);
			if (a != b)
				return false;
		}
		return true;
	}
};

int main()
{
	Solution s;
	vector<int>
		a = {7, 21, 3},
		b = {5, 2, 6, 2},
		c = {10, 5, 9, 3, 15},
		d = {16, 21, 21, 19, 7, 22, 20, 24, 4, 11},
		e = {10, 3, 9, 6, 8};
	ToOut(s.gcdSort(a));
	ToOut(s.gcdSort(b));
	ToOut(s.gcdSort(c));
	ToOut(s.gcdSort(d));
	ToOut(s.gcdSort(e));
}
