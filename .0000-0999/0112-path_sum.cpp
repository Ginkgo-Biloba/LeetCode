﻿#include "leetcode.hpp"

/* 112. 路径总和

给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

>              5
>             / \
>            4   8
>           /   / \
>          11  13  4
>         /  \      \
>        7    2      1
返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
*/

class Solution {
	bool dfs(TreeNode* node, int64_t val)
	{
		val -= node->val;
		if (!(node->left || node->right))
			return val == 0;
		bool b = false;
		if (!b && node->left)
			b = dfs(node->left, val);
		if (!b && node->right)
			b = dfs(node->right, val);
		return b;
	}

public:
	bool hasPathSum(TreeNode* root, int sum)
	{
		if (!root)
			return false;
		return dfs(root, sum);
	}
};

int main()
{
}
