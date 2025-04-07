#include "leetcode.hpp"

/* 2271. 毯子覆盖的最多白色砖块数

给你一个二维整数数组 tiles ，其中 tiles[i] = [li, ri] ，表示所有在 li <= j <= ri 之间的每个瓷砖位置 j 都被涂成了白色。

同时给你一个整数 carpetLen ，表示可以放在 任何位置 的一块毯子的长度。

请你返回使用这块毯子，最多 可以盖住多少块瓷砖。

示例 1：
https://assets.leetcode.com/uploads/2022/03/25/example1drawio3.png
输入：tiles = [[1,5],[10,11],[12,18],[20,25],[30,32]], carpetLen = 10
输出：9
解释：将毯子从瓷砖 10 开始放置。
总共覆盖 9 块瓷砖，所以返回 9 。
注意可能有其他方案也可以覆盖 9 块瓷砖。
可以看出，瓷砖无法覆盖超过 9 块瓷砖。

示例 2：
https://assets.leetcode.com/uploads/2022/03/24/example2drawio.png
输入：tiles = [[10,11],[1,1]], carpetLen = 2
输出：2
解释：将毯子从瓷砖 10 开始放置。
总共覆盖 2 块瓷砖，所以我们返回 2 。

提示：
  1 <= tiles.length <= 5 * 10^4
  tiles[i].length == 2
  1 <= li <= ri <= 10^9
  1 <= carpetLen <= 10^9
  tiles 互相 不会重叠 。
*/

int maximumWhiteTiles(
	vector<vector<int>>& tiles, int carpetLen)
{
	std::sort(tiles.begin(), tiles.end());
	int n = static_cast<int>(tiles.size());
	int ans = 0, cur = 0, k = 0;
	for (int i = 0; i < n; ++i) {
		if (i > 0)
			cur -= tiles[i - 1][1] - tiles[i - 1][0] + 1;
		for (; k < n; ++k) {
			if (tiles[i][0] + carpetLen <= tiles[k][1])
				break;
			cur += tiles[k][1] - tiles[k][0] + 1;
		}
		if (k == n) {
			ans = max(ans, cur);
			break;
		}
		int extra = tiles[i][0] + carpetLen - tiles[k][0];
		ans = max(ans, cur + max(0, extra));
	}
	return ans;
}

int main()
{
	vector<vector<int>>
		a = {{1, 5}, {10, 11}, {12, 18}, {20, 25}, {30, 32}},
		b = {{10, 11}, {1, 1}};
	ToOut(maximumWhiteTiles(a, 10));
	ToOut(maximumWhiteTiles(b, 2));
}
