#pragma once
#include <iostream>

class A
{
public:
	int _age = 45;
	mutable int weigth = 212;
	static int static_num;
	A(int age) :_age(age) {}
	void modifMem() const {
		//_age = 99;常量成员函数中不允许修改普通成员变量
		static_num = 100;//常量成员函数中可以修改静态static成员变量的值
		weigth = 88888;//通过mutable修饰的变量就可以修改了
	}
};
int A::static_num = 99;//静态成员，类内定义，类外初始化
void testMutable()
{

}