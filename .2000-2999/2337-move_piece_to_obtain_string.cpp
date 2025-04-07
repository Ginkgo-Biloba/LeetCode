#include "leetcode.hpp"

/* 2337. 移动片段得到字符串

给你两个字符串 start 和 target ，长度均为 n 。
每个字符串 仅 由字符 'L'、'R' 和 '_' 组成，其中：

  字符 'L' 和 'R' 表示片段，其中片段 'L' 只有在其左侧直接存在一个 空位 时才能向 左 移动，而片段 'R' 只有在其右侧直接存在一个 空位 时才能向 右 移动。
  字符 '_' 表示可以被 任意 'L' 或 'R' 片段占据的空位。

如果在移动字符串 start 中的片段任意次之后可以得到字符串 target ，返回 true ；否则，返回 false 。

示例 1：
输入：start = "_L__R__R_", target = "L______RR"
输出：true
解释：可以从字符串 start 获得 target ，需要进行下面的移动：
- 将第一个片段向左移动一步，字符串现在变为 "L___R__R_" 。
- 将最后一个片段向右移动一步，字符串现在变为 "L___R___R" 。
- 将第二个片段向右移动三步，字符串现在变为 "L______RR" 。
可以从字符串 start 得到 target ，所以返回 true 。

示例 2：
输入：start = "R_L_", target = "__LR"
输出：false
解释：字符串 start 中的 'R' 片段可以向右移动一步得到 "_RL_" 。
但是，在这一步之后，不存在可以移动的片段，所以无法从字符串 start 得到 target 。

示例 3：
输入：start = "_R", target = "R_"
输出：false
解释：字符串 start 中的片段只能向右移动，所以无法从字符串 start 得到 target 。

提示：
  n == start.length == target.length
  1 <= n <= 10^5
  start 和 target 由字符 'L'、'R' 和 '_' 组成
*/

bool canChange(string start, string target)
{
	int n = static_cast<int>(start.size());
	for (int is = 0, it = 0; is < n || it < n; ++is, ++it) {
		while (is < n && start[is] == '_') ++is;
		while (it < n && target[it] == '_') ++it;
		if (is == n || it == n) return is == it;
		int ch = start[is];
		if (ch != target[it]) return false;
		if (ch == 'L' && is < it) return false;
		if (ch == 'R' && is > it) return false;
	}
	return true;
}

int main()
{
	ToOut(canChange("_L__R__R_", "L______RR"));
	ToOut(canChange("R_L_", "__LR"));
	ToOut(canChange("_R", "R_"));
	ToOut(canChange("R__", "_LR"));
	ToOut(canChange("R__L", "_LR_"));
	ToOut(canChange("_L", "LR"));
}
