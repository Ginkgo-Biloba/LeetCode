﻿#include "leetcode.hpp"

/* 1648. 销售价值减少的颜色球

你有一些球的库存 inventory ，里面包含着不同颜色的球。
一个顾客想要 任意颜色 总数为 orders 的球。

这位顾客有一种特殊的方式衡量球的价值：每个球的价值是目前剩下的 同色球 的数目。
比方说还剩下 6 个黄球，那么顾客买第一个黄球的时候该黄球的价值为 6 。
这笔交易以后，只剩下 5 个黄球了，所以下一个黄球的价值为 5 （也就是球的价值随着顾客购买同色球是递减的）

给你整数数组 inventory ，其中 inventory[i] 表示第 i 种颜色球一开始的数目。同时给你整数 orders ，表示顾客总共想买的球数目。
你可以按照 任意顺序 卖球。

请你返回卖了 orders 个球以后 最大 总价值之和。
由于答案可能会很大，请你返回答案对 10^9 + 7 取余数 的结果。

示例 1：
https://assets.leetcode.com/uploads/2020/11/05/jj.gif
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/11/08/jj.gif
输入：inventory = [2,5], orders = 4
输出：14
解释：卖 1 个第一种颜色的球（价值为 2 )，卖 3 个第二种颜色的球（价值为 5 + 4 + 3）。
最大总和为 2 + 5 + 4 + 3 = 14 。

示例 2：
输入：inventory = [3,5], orders = 6
输出：19
解释：卖 2 个第一种颜色的球（价值为 3 + 2），卖 4 个第二种颜色的球（价值为 5 + 4 + 3 + 2）。
最大总和为 3 + 2 + 5 + 4 + 3 + 2 = 19 。

示例 3：
输入：inventory = [2,8,4,10,6], orders = 20
输出：110

示例 4：
输入：inventory = [1000000000], orders = 1000000000
输出：21
解释：卖 1000000000 次第一种颜色的球，总价值为 500000000500000000 。 500000000500000000 对 10^9 + 7 取余为 21 。

提示：
  1 <= inventory.length <= 10^5
  1 <= inventory[i] <= 10^9
  1 <= orders <= min(sum(inventory[i]), 10^9)
*/

static int64_t const mod = static_cast<int64_t>(1e9 + 7);

class Solution {
	int64_t get(int64_t order, int64_t a, int64_t k)
	{
		int64_t d = order / k;
		int64_t s = d * (a + a - d + 1) / 2;
		s = (s % mod) * k % mod;
		s += (a - d) * (order - d * k);
		return s % mod;
	}

public:
	int maxProfit(vector<int>& A, int orders)
	{
		int64_t sum = 0;
		int len = static_cast<int>(A.size());
		sort(A.begin(), A.end());
		for (int i = len - 1; i > 0 && orders > 0; --i) {
			int dif = A[i] - A[i - 1];
			int num = orders;
			if (orders / (len - i) >= dif)
				num = dif * (len - i);
			orders -= num;
			sum = sum + get(num, A[i], len - i);
			sum %= mod;
		}
		sum = sum + get(orders, A[0], len);
		return static_cast<int>(sum % mod);
	}
};

int main()
{
	vector<int>
		a = {2, 5},
		b = {3, 5},
		c = {2, 8, 4, 10, 6},
		d = {1000000000};
	Solution s;
	ToOut(s.maxProfit(a, 4));
	ToOut(s.maxProfit(b, 6));
	ToOut(s.maxProfit(c, 20));
	ToOut(s.maxProfit(d, 1000000000));
}
