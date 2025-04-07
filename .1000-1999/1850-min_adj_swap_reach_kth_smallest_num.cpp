#include "leetcode.hpp"

/* 1850. 邻位交换的最小次数

给你一个表示大整数的字符串 num ，和一个整数 k 。

如果某个整数是 num 中各位数字的一个 排列 且它的 值大于 num ，则称这个整数为 妙数 。
可能存在很多妙数，但是只需要关注 值最小 的那些。
  例如，num = "5489355142" ：
  第 1 个最小妙数是 "5489355214"
  第 2 个最小妙数是 "5489355241"
  第 3 个最小妙数是 "5489355412"
  第 4 个最小妙数是 "5489355421"

返回要得到第 k 个 最小妙数 需要对 num 执行的 相邻位数字交换的最小次数 。

测试用例是按存在第 k 个最小妙数而生成的。

示例 1：
输入：num = "5489355142", k = 4
输出：2
解释：第 4 个最小妙数是 "5489355421" ，要想得到这个数字：
- 交换下标 7 和下标 8 对应的位："5489355142" -> "5489355412"
- 交换下标 8 和下标 9 对应的位："5489355412" -> "5489355421"

示例 2：
输入：num = "11112", k = 4
输出：4
解释：第 4 个最小妙数是 "21111" ，要想得到这个数字：
- 交换下标 3 和下标 4 对应的位："11112" -> "11121"
- 交换下标 2 和下标 3 对应的位："11121" -> "11211"
- 交换下标 1 和下标 2 对应的位："11211" -> "12111"
- 交换下标 0 和下标 1 对应的位："12111" -> "21111"

示例 3：
输入：num = "00123", k = 1
输出：1
解释：第 1 个最小妙数是 "00132" ，要想得到这个数字：
- 交换下标 3 和下标 4 对应的位："00123" -> "00132"

提示：
  2 <= num.length <= 1000
  1 <= k <= 1000
  num 仅由数字组成
*/

class Solution {
	void permutate(string& A)
	{
		int len = static_cast<int>(A.size());
		int i = len - 2, k;
		for (; i >= 0; --i) {
			if (A[i] < A[i + 1])
				break;
		}
		assert(i >= 0);
		for (k = len - 1; k > i; --k) {
			if (A[i] < A[k])
				break;
		}
		std::swap(A[i], A[k]);
		for (k = len - 1, ++i; i < k; ++i, --k)
			std::swap(A[i], A[k]);
	}

public:
	int getMinSwaps(string A, int k)
	{
		int len = static_cast<int>(A.size());
		int ans = 0;
		string B = A;
		while (k--)
			permutate(B);
		for (int i = 0; i < len; ++i) {
			if (A[i] == B[i])
				continue;
			k = i + 1;
			for (; k < len; ++k) {
				if (A[k] == B[i])
					break;
			}
			assert(k < len);
			ans += k - i;
			for (; k > i; --k)
				A[k] = A[k - 1];
			A[i] = B[i];
		}
		return ans;
	}
};

int main()
{
	Solution s;
	ToOut(s.getMinSwaps("5489355142", 4));
	ToOut(s.getMinSwaps("11112", 4));
	ToOut(s.getMinSwaps("00123", 4));
}
