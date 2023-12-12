#pragma once
#include <iostream>
void Virtual()
{
/*
1.友元函数，构造函数，static静态函数不能用virtual修饰
2.virtual具有继承性
3.多态分为编译时多态，和运行时多态
4.虚函数的特点是《动态联编》，它可以在运行时判断指针指向的对象，并自动调用相应的函数。
5.用虚拟继承去解决菱形继承问题
*/
}
class A {
public:
	int pwd = 2223;
	A()
	{
		std::cout << "A构造函数调用" << "\n";
	}
	virtual ~A()
	{
		std::cout << "A析构函数调用" << std::endl;
	}
};
class B1:virtual public A{
public:
	B1()
	{
		this->pwd = 11111;
		std::cout << "B1构造函数调用" << "\n";
	}
	virtual ~B1()
	{
		std::cout << "B1析构函数调用" << std::endl;
	}
};
class B2 :virtual public A{
public:
	B2()
	{
		this->pwd = 222222;
		std::cout << "B2构造函数调用" << "\n";
	}
	virtual ~B2()
	{
		std::cout << "B2析构函数调用" << std::endl;
	}
};
class C :public B1, public B2 {
public:
	C()
	{
		std::cout << "C构造函数调用" << "\n";
	}
	virtual ~C()
	{
		std::cout << "C析构函数调用" << std::endl;
	}

};



