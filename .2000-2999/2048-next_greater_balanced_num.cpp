#include "leetcode.hpp"

/* 2048. 下一个更大的数值平衡数

如果整数  x 满足：对于每个数位 d ，这个数位 恰好 在 x 中出现 d 次。
那么整数 x 就是一个 数值平衡数 。

给你一个整数 n ，请你返回 严格大于 n 的 最小数值平衡数 。

示例 1：
输入：n = 1
输出：22
解释：
22 是一个数值平衡数，因为：
- 数字 2 出现 2 次
这也是严格大于 1 的最小数值平衡数。

示例 2：
输入：n = 1000
输出：1333
解释：
1333 是一个数值平衡数，因为：
- 数字 1 出现 1 次。
- 数字 3 出现 3 次。
这也是严格大于 1000 的最小数值平衡数。
注意，1022 不能作为本输入的答案，因为数字 0 的出现次数超过了 0 。

示例 3：
输入：n = 3000
输出：3133
解释：
3133 是一个数值平衡数，因为：
- 数字 1 出现 1 次。
- 数字 3 出现 3 次。
这也是严格大于 3000 的最小数值平衡数。

提示：
  0 <= n <= 10^6
*/

vector<int> A;

class Solution {
public:
	Solution()
	{
		if (A.size())
			return;
		for (int i = 1; i <= 1224444; ++i) {
			int c[10] = {0};
			for (int n = i; n; n /= 10)
				c[n % 10] += 1;
			for (int b = 1; b <= 9; ++b)
				c[0] += (c[b] && c[b] != b);
			if (!c[0])
				A.push_back(i);
		}
	}

	int nextBeautifulNumber(int n)
	{
		auto it = upper_bound(A.begin(), A.end(), n);
		return *it;
	}
};

int main()
{
	Solution s;
	ToOut(s.nextBeautifulNumber(1));
	ToOut(s.nextBeautifulNumber(1000));
	ToOut(s.nextBeautifulNumber(3000));
}
