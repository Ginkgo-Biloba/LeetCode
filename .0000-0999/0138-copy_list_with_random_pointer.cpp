﻿#include "leetcode.hpp"

/* 138. 复制带随机指针的链表

给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的 深拷贝。

我们用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：
  val：一个表示 Node.val 的整数。
  random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。

示例 1：
输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]

示例 2：
输入：head = [[1,1],[2,1]]
输出：[[1,1],[2,1]]

示例 3：
输入：head = [[3,null],[3,0],[3,null]]
输出：[[3,null],[3,0],[3,null]]

示例 4：
输入：head = []
输出：[]
解释：给定的链表为空（空指针），因此返回 null。

提示：
  -10000 <= Node.val <= 10000
  Node.random 为空（null）或指向链表中的节点。
  节点数目不超过 1000 。
*/

// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val)
	{
		val = _val;
		next = NULL;
		random = NULL;
	}
};

Node* copyRandomList(Node* head)
{
	if (!head)
		return NULL;
	Node *a, *p, *b, *q = NULL, dummy(0);
	for (a = head; a; a = b) {
		// a p b
		p = new Node(a->val);
		b = a->next;
		a->next = p;
		p->next = b;
	}

	for (a = head; a;) {
		// a p ... b q
		if (a->random)
			a->next->random = a->random->next;
		a = a->next->next;
	}

	dummy.next = head->next;
	p = &dummy;
	for (a = head; a;) {
		// p a q b
		q = a->next;
		b = q->next;
		p->next = q;
		a->next = b;
		a = b;
		p = q;
	}
	q->next = NULL;

	return dummy.next;
}

int main()
{
}
