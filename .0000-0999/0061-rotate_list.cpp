﻿#include "leetcode.hpp"

/* 61. 旋转链表

给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:
输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL

示例 2:
输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL
*/

ListNode* rotateRight(ListNode* head, int k)
{
	int len = 0;
	ListNode *p = head, *q;
	for (; p; p = p->next)
		++len;
	if (len < 2)
		return head;
	k %= len;
	if (k == 0)
		return head;
	// 不减是左移
	k = len - k;
	q = head;
	for (; k > 0; --k) {
		p = q;
		q = q->next;
	}
	// 断开
	p->next = NULL;
	p = q;
	while (p->next)
		p = p->next;
	// 尾部接到开头
	p->next = head;
	return q;
}

int main()
{
}
