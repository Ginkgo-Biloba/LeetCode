﻿#include "leetcode.hpp"

/* 222. 完全二叉树的节点个数

给出一个完全二叉树，求出该树的节点个数。

说明：

完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。
若最底层为第 h 层，则该层包含 1~ 2h 个节点。

示例:

输入:
>     1
>    / \
>   2   3
>  / \  /
> 4  5 6

输出: 6
*/

// https://leetcode.com/problems/count-complete-tree-nodes/discuss/61958/Concise-Java-solutions-O(log(n)2)
// 抄的
int countNodes(TreeNode* root)
{
	if (!root)
		return 0;
	TreeNode *a = root, *b = root;
	int h = 0;
	for (; b; ++h) {
		a = a->left;
		b = b->right;
	}
	return a
		? 1 + countNodes(root->left) + countNodes(root->right)
		: (1 << h) - 1;
}

int main()
{
}
