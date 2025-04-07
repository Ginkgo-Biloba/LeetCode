#include "leetcode.hpp"

/* 1825. 求出 MK 平均值

给你两个整数 m 和 k ，以及数据流形式的若干整数。
你需要实现一个数据结构，计算这个数据流的 MK 平均值 。

MK 平均值 按照如下步骤计算：
  如果数据流中的整数少于 m 个，MK 平均值 为 -1 ，否则将数据流中最后 m 个元素拷贝到一个独立的容器中。
  从这个容器中删除最小的 k 个数和最大的 k 个数。
  计算剩余元素的平均值，并 向下取整到最近的整数 。

请你实现 MKAverage 类：
  MKAverage(int m, int k) 用一个空的数据流和两个整数 m 和 k 初始化 MKAverage 对象。
  void addElement(int num) 往数据流中插入一个新的元素 num 。
  int calculateMKAverage() 对当前的数据流计算并返回 MK 平均数 ，结果需 向下取整到最近的整数 。

示例 1：

输入：
["MKAverage", "addElement", "addElement", "calculateMKAverage", "addElement", "calculateMKAverage", "addElement", "addElement", "addElement", "calculateMKAverage"]
[[3, 1], [3], [1], [], [10], [], [5], [5], [5], []]
输出：
[null, null, null, -1, null, 3, null, null, null, 5]

解释：
MKAverage obj = new MKAverage(3, 1);
obj.addElement(3);        // 当前元素为 [3]
obj.addElement(1);        // 当前元素为 [3,1]
obj.calculateMKAverage(); // 返回 -1 ，因为 m = 3 ，但数据流中只有 2 个元素
obj.addElement(10);       // 当前元素为 [3,1,10]
obj.calculateMKAverage(); // 最后 3 个元素为 [3,1,10]
                          // 删除最小以及最大的 1 个元素后，容器为 [3]
                          // [3] 的平均值等于 3/1 = 3 ，故返回 3
obj.addElement(5);        // 当前元素为 [3,1,10,5]
obj.addElement(5);        // 当前元素为 [3,1,10,5,5]
obj.addElement(5);        // 当前元素为 [3,1,10,5,5,5]
obj.calculateMKAverage(); // 最后 3 个元素为 [5,5,5]
                          // 删除最小以及最大的 1 个元素后，容器为 [5]
                          // [5] 的平均值等于 5/1 = 5 ，故返回 5

提示：
  3 <= m <= 105
  1 <= k*2 < m
  1 <= num <= 105
  addElement 与 calculateMKAverage 总操作次数不超过 105 次。
*/

class MKAverage {
	static constexpr int lb = 17;
	static constexpr int hb = 9;

	vector<int> lo, hi, A;
	vector<int64_t> hs;
	int m, k, count;

	int64_t get(int idx)
	{
		int64_t sum = 0;
		int j = 0;
		for (; j < (1 << hb); ++j) {
			if (hi[j] > idx)
				break;
			idx -= hi[j];
			sum += hs[j];
		}
		// 这个 k 只能跑 (1 << (lb - hb))
		for (j <<= (lb - hb); j < (1 << lb); ++j) {
			if (idx == 0)
				break;
			int need = min(idx, lo[j]);
			sum += static_cast<int64_t>(j) * need;
			idx -= need;
		}
		return sum;
	}

public:
	MKAverage(int _m, int _k)
		: m(_m), k(_k), count(0)
	{
		lo.resize(1 << lb);
		hi.resize(1 << hb);
		hs.resize(1 << hb);
	}

	void addElement(int x)
	{
		A.push_back(x);
		lo[x] += 1;
		hi[x >> (lb - hb)] += 1;
		hs[x >> (lb - hb)] += x;
		if (count >= m) {
			x = A[count - m];
			lo[x] -= 1;
			hi[x >> (lb - hb)] -= 1;
			hs[x >> (lb - hb)] -= x;
		}
		++count;
	}

	int calculateMKAverage()
	{
		if (count < m)
			return -1;
		int64_t a = get(k);
		int64_t b = get(m - k);
		int64_t c = (b - a) / (m - k - k);
		return static_cast<int>(c);
	}
};

int main()
{
	MKAverage m(3, 1);
	m.addElement(3);
	m.addElement(1);
	ToOut(m.calculateMKAverage());
	m.addElement(10);
	ToOut(m.calculateMKAverage());
	m.addElement(5);
	m.addElement(5);
	m.addElement(5);
	ToOut(m.calculateMKAverage());
}
