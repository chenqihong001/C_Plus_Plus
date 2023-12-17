#include<iostream>
#include <thread>
class thread_guard {
public:
	explicit thread_guard(std::thread& th) :_th(th) {}
	virtual ~thread_guard() {
		//thread只能join或detach一次
		if (_th.joinable())
			_th.join();
	}
	thread_guard(const thread_guard& _t) = delete;//删除拷贝构造
	thread_guard& operator=(const thread_guard&) = delete;//删除赋值运算方法
private:
	std::thread &_th;
	//线程禁止拷贝构造
};
/*
	1.【拒接隐式类型转换】当定义一个线程变量时，传递给线程的参数，先被保存在线程的成员变量中，当线程启动的时候，参数才会传递给函数

*/
void Print(std::string str)
{
	std::cout << str << std::endl;
}
void ImpicitType()
{
	char arr[] = "123456789";
	std::thread th(Print, static_cast<std::string>(arr));
	th.join();
}
class Functor {
public:
	void Func(int age)
	{
		std::cout << "仿函数调用" << std::endl;
	}
};
//有时候传递给线程的参数是独占式资源，使用move
void deal_unique(std::unique_ptr<int> p) {
	std::cout << "unique ptr data is " << *p << std::endl;
	(*p)++;
	std::cout << "after unique ptr data is " << *p << std::endl;
}
void move_oops() {
	auto p = std::make_unique<int>(100);//make_unique用于创建动态分配的unique_ptr对象
	//可能会导致内存泄漏，因为 std::unique_ptr 构造函数中的 new 表达式已经执行，但智能指针对象尚未构造完成，因此没有机会释放内存。
	std::thread  t(deal_unique, std::move(p));
	t.join();
	//不能再使用p了，p已经被move废弃
   // std::cout << "after unique ptr data is " << *p << std::endl;
}