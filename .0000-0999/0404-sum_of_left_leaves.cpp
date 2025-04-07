﻿#include "leetcode.hpp"

/* 404. 左叶子之和

给定二叉树的根节点 root ，返回所有左叶子之和。

示例 1：
https://assets.leetcode.com/uploads/2021/04/08/leftsum-tree.jpg
输入: root = [3,9,20,null,null,15,7]
输出: 24
解释: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24

示例 2:
输入: root = [1]
输出: 0

提示:
  节点数在 [1, 1000] 范围内
  -1000 <= Node.val <= 1000
*/

class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root)
	{
		if (!root)
			return 0;
		if (root->left && !(root->left->left) && !(root->left->right))
			return root->left->val + sumOfLeftLeaves(root->right);
		else
			return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
	}
};

int main() { }
