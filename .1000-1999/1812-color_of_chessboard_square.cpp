﻿#include "leetcode.hpp"

/* 1812. 判断国际象棋棋盘中一个格子的颜色

给你一个坐标 coordinates ，它是一个字符串，表示国际象棋棋盘中一个格子的坐标。
下图是国际象棋棋盘示意图。

https://assets.leetcode.com/uploads/2021/02/19/screenshot-2021-02-20-at-22159-pm.png
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/04/03/chessboard.png

如果所给格子的颜色是白色，请你返回 true，如果是黑色，请返回 false 。

给定坐标一定代表国际象棋棋盘上一个存在的格子。坐标第一个字符是字母，第二个字符是数字。

示例 1：
输入：coordinates = "a1"
输出：false
解释：如上图棋盘所示，"a1" 坐标的格子是黑色的，所以返回 false 。

示例 2：
输入：coordinates = "h3"
输出：true
解释：如上图棋盘所示，"h3" 坐标的格子是白色的，所以返回 true 。

示例 3：
输入：coordinates = "c7"
输出：false

提示：
  coordinates.length == 2
  'a' <= coordinates[0] <= 'h'
  '1' <= coordinates[1] <= '8'
*/

bool squareIsWhite(string coordinates)
{
	int a = coordinates[0] - 'a';
	int b = coordinates[1] - '0';
	return !!((a & 1) ^ (b & 1));
}

int main()
{
}
