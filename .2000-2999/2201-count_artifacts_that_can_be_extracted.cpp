﻿#include "leetcode.hpp"

/* 2201. 统计可以提取的工件

存在一个 n x n 大小、下标从 0 开始的网格，网格中埋着一些工件。
给你一个整数 n 和一个下标从 0 开始的二维整数数组 artifacts ，artifacts 描述了矩形工件的位置，其中 artifacts[i] = [r1i, c1i, r2i, c2i] 表示第 i 个工件在子网格中的填埋情况：

  (r1i, c1i) 是第 i 个工件 左上 单元格的坐标，且
  (r2i, c2i) 是第 i 个工件 右下 单元格的坐标。

你将会挖掘网格中的一些单元格，并清除其中的填埋物。
如果单元格中埋着工件的一部分，那么该工件这一部分将会裸露出来。
如果一个工件的所有部分都都裸露出来，你就可以提取该工件。

给你一个下标从 0 开始的二维整数数组 dig ，其中 dig[i] = [ri, ci] 表示你将会挖掘单元格 (ri, ci) ，返回你可以提取的工件数目。

生成的测试用例满足：
  不存在重叠的两个工件。
  每个工件最多只覆盖 4 个单元格。
  dig 中的元素互不相同。

示例 1：
输入：n = 2, artifacts = [[0,0,0,0],[0,1,1,1]], dig = [[0,0],[0,1]]
输出：1
解释：
不同颜色表示不同的工件。挖掘的单元格用 'D' 在网格中进行标记。
有 1 个工件可以提取，即红色工件。
蓝色工件在单元格 (1,1) 的部分尚未裸露出来，所以无法提取该工件。
因此，返回 1 。

示例 2：
输入：n = 2, artifacts = [[0,0,0,0],[0,1,1,1]], dig = [[0,0],[0,1],[1,1]]
输出：2
解释：红色工件和蓝色工件的所有部分都裸露出来（用 'D' 标记），都可以提取。因此，返回 2 。

提示：
  1 <= n <= 1000
  1 <= artifacts.length, dig.length <= min(n2, 10^5)
  artifacts[i].length == 4
  dig[i].length == 2
  0 <= r1i, c1i, r2i, c2i, ri, ci <= n - 1
  r1i <= r2i
  c1i <= c2i
  不存在重叠的两个工件
  每个工件 最多 只覆盖 4 个单元格
  dig 中的元素互不相同
*/

int digArtifacts(int /* n */,
	vector<vector<int>> const& artifacts,
	vector<vector<int>> const& dig)
{
	int ans = 0;
	vector<uint64_t> gone;
	for (auto& d : dig)
		gone.push_back(static_cast<uint64_t>(d[0])
			| (static_cast<uint64_t>(d[1]) << 32));
	std::sort(gone.begin(), gone.end());
	for (auto& art : artifacts) {
		int r1 = art[0], c1 = art[1];
		int r2 = art[2], c2 = art[3];
		int ok = 1;
		for (int r = r1; r <= r2; ++r)
			for (int c = c1; c <= c2; ++c) {
				uint64_t val = static_cast<uint64_t>(r)
					| (static_cast<uint64_t>(c) << 32);
				if (!std::binary_search(gone.begin(), gone.end(), val))
					ok = 0;
			}
		ans += ok;
	}
	return ans;
}

int main()
{
	vector<vector<int>>
		art = {{0, 2, 0, 5}, {0, 1, 1, 1}, {3, 0, 3, 3}, {4, 4, 4, 4}, {2, 1, 2, 4}},
		dig = {{0, 2}, {0, 3}, {0, 4}, {2, 0}, {2, 1}, {2, 2}, {2, 5}, {3, 0}, {3, 1}, {3, 3}, {3, 4}, {4, 0}, {4, 3}, {4, 5}, {5, 0}, {5, 1}, {5, 2}, {5, 4}, {5, 5}};
	ToOut(digArtifacts(6, art, dig));
}
