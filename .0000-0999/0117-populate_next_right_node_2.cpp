﻿#include "leetcode.hpp"

/* 117. 填充每个节点的下一个右侧节点指针 II

给定一个二叉树

struct Node
{
  int val;
  Node *left;
  Node *right;
  Node *next;
}

填充它的每个 next 指针，让这个指针指向其下一个右侧节点。
如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

进阶：
  你只能使用常量级额外空间。
  使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。

示例：
https://assets.leetcode.com/uploads/2019/02/15/117_sample.png
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/02/15/117_sample.png

输入：root = [1,2,3,4,5,null,7]
输出：[1,#,2,3,#,4,5,7,#]
解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。

提示：
  树中的节点数小于 6000
  -100 <= node.val <= 100
*/

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node()
		: val(0)
		, left(NULL)
		, right(NULL)
		, next(NULL)
	{
	}

	Node(int _val)
		: val(_val)
		, left(NULL)
		, right(NULL)
		, next(NULL)
	{
	}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val)
		, left(_left)
		, right(_right)
		, next(_next)
	{
	}
};

// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/discuss/37828/O(1)-space-O(n)-complexity-Iterative-Solution/153962
// 抄的
class Solution {
public:
	Node* connect(Node* root)
	{
		Node dummy(0);
		Node *head = root, *cur, *ptr;
		while (head) {
			dummy.next = NULL;
			ptr = &dummy;
			for (cur = head; cur; cur = cur->next) {
				if (cur->left) {
					ptr->next = cur->left;
					ptr = cur->left;
				}
				if (cur->right) {
					ptr->next = cur->right;
					ptr = cur->right;
				}
			}
			head = dummy.next;
		}
		return root;
	}
};

int main()
{
}
