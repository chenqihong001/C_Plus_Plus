#pragma once
#include <iostream>
#include <thread>
// 隐式类型转换不可取
class A
{
public:
	int _a;
	explicit A(int a) : _a(a) {
		std::cout << "A构造函数调用" << std::endl;
		std::cout << "构造函数在" << std::this_thread::get_id()<< "中调用" << std::endl;
	}
	~A() {
		std::cout << "A析构函数调用" << std::endl;
		std::cout << "析构函数在" << std::this_thread::get_id() << "中调用" << std::endl;
	}
};
void Test(const A& temp)
{
	std::cout << "子线程的地址是:" << std::this_thread::get_id() << std::endl;
}
void TestA()
{
	std::cout << "主线程_id : " << std::this_thread::get_id() << std::endl;
	std::thread t1(Test, 8);//通过隐式类型转换去实例化类
	t1.join();
}
//结论：
/*
	1.当通过隐式类型转换的时候，临时对象是在子线程中创建的，如果detach则是不安全的
	2.当通过显示类型转换的时候，临时对象是在主线程中的创建的，是线程安全的
	3.char const* const _Message指向常量字符串的常量指针
	4.转引用用std::ref
*/
