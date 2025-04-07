#include "leetcode.hpp"

/* 1114. 按序打印

我们提供了一个类：

public class Foo {
  public void one() { print("one"); }
  public void two() { print("two"); }
  public void three() { print("three"); }
}

三个不同的线程将会共用一个 Foo 实例。
  线程 A 将会调用 one() 方法
  线程 B 将会调用 two() 方法
  线程 C 将会调用 three() 方法

请设计修改程序，以确保 two() 方法在 one() 方法之后被执行，three() 方法在 two() 方法之后被执行。

示例 1:

输入: [1,2,3]
输出: "onetwothree"
解释:
有三个线程会被异步启动。
输入 [1,2,3] 表示线程 A 将会调用 one() 方法，线程 B 将会调用 two() 方法，线程 C 将会调用 three() 方法。
正确的输出是 "onetwothree"。

示例 2:

输入: [1,3,2]
输出: "onetwothree"
解释:
输入 [1,3,2] 表示线程 A 将会调用 one() 方法，线程 B 将会调用 three() 方法，线程 C 将会调用 two() 方法。
正确的输出是 "onetwothree"。



注意:

尽管输入中的数字似乎暗示了顺序，但是我们并不保证线程在操作系统中的调度顺序。
你看到的输入格式主要是为了确保测试的全面性。
*/

#include <atomic>
#include <functional>
#include <thread>

class Foo {
	std::atomic_int n;

public:
	Foo()
		: n(0) { }

	void first(std::function<void()> printFirst)
	{
		// printFirst() outputs "first". Do not change or remove this line.
		printFirst();
		n.fetch_add(1, std::memory_order_acq_rel);
	}

	void second(std::function<void()> printSecond)
	{
		while (n.load(std::memory_order_relaxed) != 1)
			std::this_thread::yield();
		// printSecond() outputs "second". Do not change or remove this line.
		printSecond();
		n.fetch_add(1, std::memory_order_acq_rel);
	}

	void third(std::function<void()> printThird)
	{
		while (n.load(std::memory_order_relaxed) != 2)
			std::this_thread::yield();
		// printThird() outputs "third". Do not change or remove this line.
		printThird();
	}
};

int main()
{
}
