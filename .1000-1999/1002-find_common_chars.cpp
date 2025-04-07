﻿#include "leetcode.hpp"

/* 1002. 查找常用字符

给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。
例如，如果一个字符在每个字符串中出现 3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。

你可以按任意顺序返回答案。

示例 1：
输入：["bella","label","roller"]
输出：["e","l","l"]

示例 2：
输入：["cool","lock","cook"]
输出：["c","o"]

提示：
  1 <= A.length <= 100
  1 <= A[i].length <= 100
  A[i][j] 是小写字母
*/

vector<string> commonChars(vector<string>& A)
{
	int num[26], cur[26];
	memset(num, 0x3f, sizeof(num));
	for (string const& a : A) {
		memset(cur, 0, sizeof(cur));
		for (char c : a)
			++(cur[c - 'a']);
		for (int i = 0; i < 26; ++i)
			num[i] = min(num[i], cur[i]);
	}

	vector<string> ans;
	char s[2] = {0, 0};
	for (int i = 0; i < 26; ++i) {
		int n = num[i];
		s[0] = static_cast<char>(i + 'a');
		while (n--)
			ans.emplace_back(s);
	}
	return ans;
}

int main()
{
	vector<string>
		a = {"bella", "label", "roller"},
		b = {"cool", "lock", "cook"};
	ToOut(commonChars(a));
	ToOut(commonChars(b));
}
