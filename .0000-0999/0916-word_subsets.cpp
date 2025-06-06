﻿#include "leetcode.hpp"

/* 916. 单词子集

我们给出两个单词数组 A 和 B。每个单词都是一串小写字母。

现在，如果 b 中的每个字母都出现在 a 中，包括重复出现的字母，那么称单词 b 是单词 a 的子集。
例如，“wrr” 是 “warrior” 的子集，但不是 “world” 的子集。

如果对 B 中的每一个单词 b，b 都是 a 的子集，那么我们称 A 中的单词 a 是通用的。

你可以按任意顺序以列表形式返回 A 中所有的通用单词。

示例 1：
输入：A = ["amazon","apple","facebook","google","leetcode"], B = ["e","o"]
输出：["facebook","google","leetcode"]

示例 2：
输入：A = ["amazon","apple","facebook","google","leetcode"], B = ["l","e"]
输出：["apple","google","leetcode"]

示例 3：
输入：A = ["amazon","apple","facebook","google","leetcode"], B = ["e","oo"]
输出：["facebook","google"]

示例 4：
输入：A = ["amazon","apple","facebook","google","leetcode"], B = ["lo","eo"]
输出：["google","leetcode"]

示例 5：
输入：A = ["amazon","apple","facebook","google","leetcode"], B = ["ec","oc","ceo"]
输出：["facebook","leetcode"]

提示：

    1 <= A.length, B.length <= 10000
    1 <= A[i].length, B[i].length <= 10
    A[i] 和 B[i] 只由小写字母组成。
    A[i] 中所有的单词都是独一无二的，也就是说不存在 i != j 使得 A[i] == A[j]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-subsets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

vector<string> wordSubsets(vector<string>& A, vector<string>& B)
{
	vector<string> C;
	char cur[26], sb[26];
	memset(sb, 0, sizeof(sb));

	for (string const& s : B) {
		memset(cur, 0, sizeof(cur));
		for (char c : s)
			++(cur[c - 'a']);
		for (int i = 0; i < 26; ++i)
			sb[i] = max(sb[i], cur[i]);
	}

	for (string const& s : A) {
		memset(cur, 0, sizeof(cur));
		for (char c : s)
			++(cur[c - 'a']);
		int i = 0;
		for (; i < 26; ++i) {
			if (cur[i] < sb[i])
				break;
		}
		if (i == 26)
			C.push_back(s);
	}

	return C;
}

int main()
{
	vector<string>
		a0 = {"amazon", "apple", "facebook", "google", "leetcode"},
		b0 = {"e", "o"},
		b1 = {"l", "e"},
		b2 = {"e", "oo"},
		b3 = {"lo", "eo"},
		b4 = {"ec", "oc", "ceo"};
	ToOut(wordSubsets(a0, b0));
	ToOut(wordSubsets(a0, b1));
	ToOut(wordSubsets(a0, b2));
	ToOut(wordSubsets(a0, b3));
	ToOut(wordSubsets(a0, b4));
}
