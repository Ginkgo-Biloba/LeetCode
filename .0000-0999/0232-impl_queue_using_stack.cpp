﻿#include "leetcode.hpp"

/* 232. 用栈实现队列

使用栈实现队列的下列操作：

  push(x) -- 将一个元素放入队列的尾部。
  pop() -- 从队列首部移除元素。
  peek() -- 返回队列首部的元素。
  empty() -- 返回队列是否为空。

示例:

MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);
queue.peek();  // 返回 1
queue.pop();   // 返回 1
queue.empty(); // 返回 false

说明:
  你只能使用标准的栈操作 -- 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
  你所使用的语言也许不支持栈。
  你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
  假设所有操作都是有效的（例如，一个空的队列不会调用 pop 或者 peek 操作）。
*/

class MyQueue {
	vector<int> a, b;

	void b2a()
	{
		if (a.empty())
			while (b.size()) {
				a.push_back(b.back());
				b.pop_back();
			}
	}

public:
	/** Initialize your data structure here. */
	MyQueue()
	{
	}

	/** Push element x to the back of queue. */
	void push(int x)
	{
		b.push_back(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop()
	{
		b2a();
		int x = a.back();
		a.pop_back();
		return x;
	}

	/** Get the front element. */
	int peek()
	{
		b2a();
		return a.back();
	}

	/** Returns whether the queue is empty. */
	bool empty()
	{
		return a.empty() && b.empty();
	}
};

int main()
{
	MyQueue q;
	q.push(1);
	q.push(2);
	ToOut(q.peek());
	ToOut(q.pop());
	q.push(3);
	ToOut(q.pop());
	ToOut(q.empty());
}
