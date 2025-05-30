﻿#include "leetcode.hpp"

/* 968. 监控二叉树

给定一个二叉树，我们在树的节点上安装摄像头。

节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。

计算监控树的所有节点所需的最小摄像头数量。

示例 1：
输入：[0,0,null,0,0]
输出：1
解释：如图所示，一台摄像头足以监控所有节点。
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/29/bst_cameras_01.png

示例 2：
输入：[0,0,null,0,null,0,null,null,0]
输出：2
解释：需要至少两个摄像头来监视树的所有节点。 上图显示了摄像头放置的有效位置之一。
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/29/bst_cameras_02.png

提示：
  给定树的节点数的范围是 [1, 1000]。
  每个节点的值都是 0。
*/

// 抄的
class Solution {
	int sum;

	// 0 叶子
	// 1 叶子的父节点，有相机；
	// 2 子节点有相机，可以被监控
	int dfs(TreeNode* root)
	{
		if (root == nullptr)
			return 2;
		int L = dfs(root->left);
		int R = dfs(root->right);
		if (L == 0 || R == 0) {
			++sum;
			return 1;
		}
		return (L == 1 || R == 1) ? 2 : 0;
	}

public:
	int minCameraCover(TreeNode* root)
	{
		int t = dfs(root);
		return sum + (t == 0);
	}
};

int main()
{
}
