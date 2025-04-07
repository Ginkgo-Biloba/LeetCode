﻿#include "leetcode.hpp"

/* 71. 简化路径

以 Unix 风格给出一个文件的绝对路径，你需要简化它。
或者换句话说，将其转换为规范路径。

在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；
此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；
两者都可以是复杂相对路径的组成部分。

请注意，返回的规范路径必须始终以斜杠 / 开头，并且两个目录名之间必须只有一个斜杠 /。
最后一个目录名（如果存在）不能以 / 结尾。
此外，规范路径必须是表示绝对路径的最短字符串。

示例 1
输入："/home/"
输出："/home"
解释：注意，最后一个目录名后面没有斜杠。

示例 2：
输入："/../"
输出："/"
解释：从根目录向上一级是不可行的，因为根是你可以到达的最高级。

示例 3：
输入："/home//foo/"
输出："/home/foo"
解释：在规范路径中，多个连续斜杠需要用一个斜杠替换。

示例 4：
输入："/a/./b/../../c/"
输出："/c"

示例 5：
输入："/a/../../b/../c//.//"
输出："/c"

示例 6：
输入："/a//b////c/d//././/.."
输出："/a/b/c"
*/

string simplifyPath(string A)
{
	vector<string> S;
	int len = static_cast<int>(A.length());
	for (int i = 0; i < len;) {
		int k = i + 1;
		while ((k < len)
			&& ((A[i] == '/' && A[k] == '/')
				|| (A[i] != '/' && A[k] != '/')))
			++k;
		if (A[i] == '.') {
			if (k == i + 1)
				;
			else if (k == i + 2) {
				if (S.size())
					S.pop_back();
			}
			// Unix 可以用 ... 作为文件夹名？？？
			else
				S.push_back(A.substr(i, k - i));
		} else if (A[i] == '/')
			;
		else
			S.push_back(A.substr(i, k - i));
		i = k;
	}

	A.assign(1, '/');
	len = static_cast<int>(S.size());
	for (int i = 0; i < len; ++i) {
		A += S[i];
		if (i < len - 1)
			A.push_back('/');
	}
	return A;
}

int main()
{
	ToOut(simplifyPath("/home/"));
	ToOut(simplifyPath("/../"));
	ToOut(simplifyPath("/home//foo/"));
	ToOut(simplifyPath("/a/./b/../../c/"));
	ToOut(simplifyPath("/a/../../b/../c//.//"));
	ToOut(simplifyPath("/a//b////c/d//././/.."));
	ToOut(simplifyPath("/abc/..."));
	ToOut(simplifyPath("/../"));
	ToOut(simplifyPath("/..hidden"));
}
