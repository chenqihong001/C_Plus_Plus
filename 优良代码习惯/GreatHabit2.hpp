#pragma once
#include <iostream>
#include <vector>
void GreatHabit2()
{
	//14.认为类成员按照初始化列表的顺序进行初始化,实际上，是按照变量的类中的声明顺序决定的
	//15.不了解初始化列表和值初始化之间的区别
	//16.对于一些固定的数值，要引入基本常量，如PI，增加代码的可读性
	//17.在循环遍历容器是尝试添加或删除元素,会使迭代器失效
	//18.返回局部变量的std::move右值引用
	//19.以为执行顺序是有保证的
}
class Habit2
{
public:
	Habit2():age(10),weight(age){}
public:
	int age = 0;
	float weight = 0.0f;
};
//15
void default_vs_value_initializtion()
{
	int z();//函数声明
	int x = 0;
	int* x1 = new int;
	int y{};
	int* y1 = new int();
	int* y2 = new int{};
	std::cout << x << "\n";
	std::cout << *x1 << "\n";
	std::cout << y << "\n";
	std::cout << *y1 << "\n";
	std::cout << *y2 << "\n";
}
//聚合类型
