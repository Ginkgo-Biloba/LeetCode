﻿#include "leetcode.hpp"

/* 99. 恢复二叉搜索树

二叉搜索树中的两个节点被错误地交换。

请在不改变其结构的情况下，恢复这棵树。

示例 1:
输入: [1,3,null,null,2]
>   1
>  /
> 3
>  \
>   2

输出: [3,1,null,null,2]
>   3
>  /
> 1
>  \
>   2

示例 2:
输入: [3,1,4,null,null,2]
>   3
>  / \
> 1   4
>    /
>   2

输出: [2,1,4,null,null,3]
>   2
>  / \
> 1   4
>    /
>   3

进阶:
  使用 O(n) 空间复杂度的解法很容易实现。
  你能想出一个只使用常数空间的解决方案吗？
*/

// https://leetcode.com/problems/recover-binary-search-tree/discuss/32559/Detail-Explain-about-How-Morris-Traversal-Finds-two-Incorrect-Pointer
// 抄的，Morris 遍历
void recoverTree(TreeNode* cur)
{
	pair<TreeNode*, TreeNode*> T;
	TreeNode *pre = NULL, *tmp = NULL;
	while (cur) {
		if (cur->left) {
			tmp = cur->left;
			while (tmp->right && tmp->right != cur)
				tmp = tmp->right;
			if (tmp->right) {
				if (pre && pre->val > cur->val) {
					if (!T.first)
						T.first = pre;
					T.second = cur;
				}
				pre = cur;
				tmp->right = NULL;
				cur = cur->right;
			} else {
				tmp->right = cur;
				cur = cur->left;
			}
		} else {
			if (pre && pre->val > cur->val) {
				if (!T.first)
					T.first = pre;
				T.second = cur;
			}
			pre = cur;
			cur = cur->right;
		}
	}
	if (T.first && T.second) {
		int t = T.first->val;
		T.first->val = T.second->val;
		T.second->val = t;
	}
}

int main()
{
}
