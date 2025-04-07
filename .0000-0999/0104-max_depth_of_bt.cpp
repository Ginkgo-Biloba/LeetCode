﻿#include "leetcode.hpp"

/* 104. 二叉树的最大深度

给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

>    3
>   / \
>  9  20
>    /  \
>   15   7

返回它的最大深度 3 。
*/

int maxDepth(TreeNode* root)
{
	if (!root)
		return 0;
	vector<TreeNode*> A, B;
	int level = 0;
	A.push_back(root);
	for (; !A.empty(); ++level) {
		B.clear();
		for (auto t : A) {
			if (t->left)
				B.push_back(t->left);
			if (t->right)
				B.push_back(t->right);
		}
		B.swap(A);
	}
	return level;
}

int main()
{
}
