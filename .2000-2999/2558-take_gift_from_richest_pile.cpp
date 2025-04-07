﻿#include "leetcode.hpp"

/* 2558. 从数量最多的堆取走礼物

给你一个整数数组 gifts ，表示各堆礼物的数量。

每一秒，你需要执行以下操作：
  选择礼物数量最多的那一堆。
  如果不止一堆都符合礼物数量最多，从中选择任一堆即可。
  将堆中的礼物数量减少到堆中原来礼物数量的平方根，向下取整。
  返回在 k 秒后剩下的礼物数量。

示例 1：
输入：gifts = [25,64,9,4,100], k = 4
输出：29
解释：
按下述方式取走礼物：
- 在第一秒，选中最后一堆，剩下 10 个礼物。
- 接着第二秒选中第二堆礼物，剩下 8 个礼物。
- 然后选中第一堆礼物，剩下 5 个礼物。
- 最后，再次选中最后一堆礼物，剩下 3 个礼物。
最后剩下的礼物数量分别是 [5,8,9,4,3] ，所以，剩下礼物的总数量是 29 。

示例 2：
输入：gifts = [1,1,1,1], k = 4
输出：4
解释：
在本例中，不管选中哪一堆礼物，都必须剩下 1 个礼物。
也就是说，你无法获取任一堆中的礼物。
所以，剩下礼物的总数量是 4 。

提示：
  1 <= gifts.length <= 10^3
  1 <= gifts[i] <= 10^9
  1 <= k <= 10^3
*/

long long pickGifts(vector<int> A, int k)
{
	std::make_heap(A.begin(), A.end());
	while (k--) {
		std::pop_heap(A.begin(), A.end());
		A.back() = static_cast<int>(std::sqrt(A.back()));
		std::push_heap(A.begin(), A.end());
	}
	long long ans = 0;
	for (int i : A) ans += i;
	return ans;
}

int main()
{
	ToOut(pickGifts({25, 64, 9, 4, 100}, 4));
	ToOut(pickGifts({1, 1, 1, 1}, 4));
}
