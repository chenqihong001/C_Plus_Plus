#pragma once
#include<iostream>
/*---多态---*/
/*
	Polymorphism
	1.虚函数的工作原理：理解虚函数表->每个基类和派生类都有自己的虚函数表
	->每个虚函数表都有函数指针组成，其中每个指针都指向相应虚函数的实现
	2.运行阶段类型识别（RTTI）
	3.纯虚函数
	4.使用虚继承解决菱形继承问题，菱形继承的问题：1.会导致最高级基类多次构造 2.最高级基类的成员属性存在二义性
	5.表明覆盖意图的限定符override，检查：1.基类函数是否是虚函数 2.基类中相应虚函数的特征标志是否于派生类的完全相同
	6.final->声明的类不可被继承->声明的virtual虚函数，不能在派生类中被覆盖

*/
/*《应该》*/
/*
	1.将析构函数设置为virtual
	2.务必使用虚继承virtual来解决菱形问题

*/
class Base11 {
public:
	 virtual void Print()
	{
		std::cout << "I am the Base11";
	}
	virtual ~Base11() = default;
};
class Derived11 :public Base11{
public:
	//virtual具有传递性
	void Print()override final//表示不能够再被重写
	{
		std::cerr << "I am the Derived11" << std::endl;
	}
};
void Main_11(){
	std::cout << sizeof(Base11) << std::endl;
}