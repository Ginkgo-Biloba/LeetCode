﻿#include "leetcode.hpp"

/* 83. 删除排序链表中的重复元素

给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:
输入: 1->1->2
输出: 1->2

示例 2:
输入: 1->1->2->3->3
输出: 1->2->3
*/

ListNode* deleteDuplicates(ListNode* head)
{
	if (!head)
		return head;
	ListNode root {head->val - 1, head};
	ListNode *p = &root, *q = head;
	for (; q; q = q->next) {
		if (!(q->next) || (q->val != q->next->val)) {
			p->next->val = q->val;
			p = p->next;
		}
	}
	p->next = nullptr;
	return root.next;
}

int main()
{
}
