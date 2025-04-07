#include "leetcode.hpp"

/* 2197. 替换数组中的非互质数

给你一个整数数组 nums 。请你对数组执行下述操作：

  从 nums 中找出 任意 两个 相邻 的 非互质 数。
  如果不存在这样的数，终止 这一过程。
  否则，删除这两个数，并 替换 为它们的 最小公倍数（Least Common Multiple，LCM）。
  只要还能找出两个相邻的非互质数就继续 重复 这一过程。

返回修改后得到的 最终 数组。
可以证明的是，以 任意 顺序替换相邻的非互质数都可以得到相同的结果。

生成的测试用例可以保证最终数组中的值 小于或者等于 10^8 。

两个数字 x 和 y 满足 非互质数 的条件是：GCD(x, y) > 1 ，其中 GCD(x, y) 是 x 和 y 的 最大公约数 。

示例 1 ：
输入：nums = [6,4,3,2,7,6,2]
输出：[12,7,6]
解释：
- (6, 4) 是一组非互质数，且 LCM(6, 4) = 12 。得到 nums = [12,3,2,7,6,2] 。
- (12, 3) 是一组非互质数，且 LCM(12, 3) = 12 。得到 nums = [12,2,7,6,2] 。
- (12, 2) 是一组非互质数，且 LCM(12, 2) = 12 。得到 nums = [12,7,6,2] 。
- (6, 2) 是一组非互质数，且 LCM(6, 2) = 6 。得到 nums = [12,7,6] 。
现在，nums 中不存在相邻的非互质数。
因此，修改后得到的最终数组是 [12,7,6] 。
注意，存在其他方法可以获得相同的最终数组。

示例 2 ：
输入：nums = [2,2,1,1,3,3,3]
输出：[2,1,1,3]
解释：
- (3, 3) 是一组非互质数，且 LCM(3, 3) = 3 。得到 nums = [2,2,1,1,3,3] 。
- (3, 3) 是一组非互质数，且 LCM(3, 3) = 3 。得到 nums = [2,2,1,1,3] 。
- (2, 2) 是一组非互质数，且 LCM(2, 2) = 2 。得到 nums = [2,1,1,3] 。
现在，nums 中不存在相邻的非互质数。
因此，修改后得到的最终数组是 [2,1,1,3] 。
注意，存在其他方法可以获得相同的最终数组。

提示：
  1 <= nums.length <= 10^5
  1 <= nums[i] <= 10^5
  生成的测试用例可以保证最终数组中的值 小于或者等于 10^8 。
*/

int gcd(int a, int b)
{
	while (b) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

vector<int> replaceNonCoprimes1(vector<int> const& nums)
{
	vector<int> ans;
	int n = static_cast<int>(nums.size());
	int val = nums[0];
	for (int i = 1; i < n;) {
		bool ok = false;
		do {
			ok = false;
			for (; i < n; ++i) {
				int x = gcd(val, nums[i]);
				if (x == 1)
					break;
				val = val / x * nums[i];
				ok = true;
			}
			if (!ok) {
				ans.push_back(val);
				if (i < n)
					val = nums[i++];
				else
					val = -1;
				break;
			}
			ok = false;
			while (ans.size()) {
				int x = gcd(val, ans.back());
				if (x == 1)
					break;
				val = val / x * ans.back();
				ans.pop_back();
				ok = true;
			}
		} while (ok);
	}
	if (val > 0)
		ans.push_back(val);
	return ans;
}

vector<int> replaceNonCoprimes(vector<int> const& nums)
{
	vector<int> ans;
	for (int val : nums) {
		ans.push_back(val);
		for (size_t i = ans.size(); i >= 2; --i) {
			int a = ans[i - 1];
			int b = ans[i - 2];
			int x = gcd(a, b);
			if (x == 1)
				break;
			ans.pop_back();
			ans.back() *= a / x;
		}
	}
	return ans;
}

int main()
{
	vector<int> a = {8303, 361, 8303, 361, 437, 361, 8303, 8303, 8303, 6859, 19, 19, 361, 70121, 70121, 70121, 70121, 70121, 70121, 70121, 70121, 70121, 70121, 70121, 70121, 70121, 70121, 70121, 70121, 1271, 31, 961, 31, 7, 2009, 7, 2009, 2009, 49, 7, 7, 8897, 1519, 31, 1519, 217};
	ToOut(replaceNonCoprimes(a));
	ToOut(replaceNonCoprimes({6, 4, 3, 2, 7, 6, 2}));
	ToOut(replaceNonCoprimes({2, 2, 1, 1, 3, 3, 3}));
}
