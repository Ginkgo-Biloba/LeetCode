﻿#include "leetcode.hpp"

/* 814. 二叉树剪枝

给定二叉树根结点 root ，此外树的每个结点的值要么是 0，要么是 1。
返回移除了所有不包含 1 的子树的原二叉树。
节点 X 的子树为 X 本身，以及所有 X 的后代。

示例1:
输入: [1,null,0,0,1]
输出: [1,null,0,null,1]
解释:
https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_2.png
只有红色节点满足条件“所有不包含 1 的子树”。
右图为返回的答案。

示例2:
输入: [1,0,1,0,0,0,1]
输出: [1,null,1,null,1]
https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_1.png

示例3:
输入: [1,1,0,1,1,0,1,0]
输出: [1,1,0,1,1,null,1]
https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/05/1028.png

说明:
  给定的二叉树最多有 100 个节点。
  每个节点的值只会为 0 或 1 。
*/

// https://leetcode.com/problems/binary-tree-pruning/discuss/122730/C%2B%2BJavaPython-Self-Explaining-Solution-and-2-lines
TreeNode* pruneTree(TreeNode* root)
{
	if (!root) return NULL;
	root->left = pruneTree(root->left);
	root->right = pruneTree(root->right);
	if (!root->left && !root->right && root->val == 0) return NULL;
	return root;
}

int main()
{
}
