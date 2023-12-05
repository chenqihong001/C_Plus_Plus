#pragma once
#include<iostream>
#include <vector>
#include <array>
#include <unordered_map>
void testGreatHabit()
{
	/*
	1.do not use using namespace std
	2.以\n代替std::endl
	3.避免使用基于索引的for loop，而选择基于范围的for(const auto& num : data){}
	4.尽量使用系统自带的方法去实现你想要的内容
	5.通常向函数中传入一个数组，需要void printArray(int* arr, int size);通过一个指针去接受，同时传入数组长度
	更优的写法是，设置参数为标准数组std::array或容器std::vector
	6.reinterpret_cast类型转换不要用
	7.at是[]运算符的"const"版本，如果单词不在映射中，则会抛出异常
	8.忽略"const correctness"const正确性，比如在一个函数的中，不需要修改传入的参数的值，则要为其加上const修饰
	9.不了解字符串字面值的生命周期,字符串字面值的生命周期与程序的生命周期相同，存储在静态区
	10.使用结构化绑定
	11.在想要从函数返回多个值时，使用多个输出参数
	12.使用constexpr在运行时执行本可以在编译时完成的工作
	13.忘记标记析构函数为virtual，1.对于通过子类指针创建子类对象，对象销毁后会调用，子类和父类的构造函数 2.对通过父类指针创建
	子类对象，对象销毁后，则只会调用父类的析构函数
	*/
}
void test3(const std::vector<int>&data)
{
	for (std::size_t i = 0; i < data.size(); i++)
	{
		
	}
	for (const auto& num : data)
	{
		std::cout << num << "\n";
	}
}

// 使用 std::array
void printArray(const std::array<int, 5>& arr) {
	for (const int& value : arr) {//引用传递
		std::cout << value << " ";
	}
	for (int val : arr)//值拷贝
	{
		std::cout << val<<'\n';
	}
	//在遍历的时候尽量都用带const修饰的迭代器
	//for (int& v : arr)
	//{
	//切忌用不带const修饰的引用&去接收带const的引用&
	//}
	std::cout << std::endl;
}
//10.使用结构化绑定
void loop_map_items()
{
	std::unordered_map<std::string, std::string> colors = {
		{"RED", "#FF0000"},
		{"BLUE", "#0000FF"}
	};

	for (const auto& pair : colors)
	{
		std::cout << pair.first << ": " << pair.second << "\n"; // 添加分隔符
	}

	for (const auto& [name, hex] : colors)
	{
		std::cout << name << ": " << hex << '\n'; // 添加分隔符
	}
}
//11.函数返回多个值
struct Values {
	int a;
	std::string strcat;
};
Values get_values()
{
	return { 12,"哈哈哈哈" };
}
void structured()
{
	auto [age, name] = get_values();//通过结构化绑定接收多个返回值
}
//12.使用constexpr,对于参数在编译时就是已知的
constexpr int  sum_of_valTo100(const int num)
{
	return num * (num + 10);
}
void testConstexpr()
{
	const int n = 10;//编译时确认其值
	std::cout << sum_of_valTo100(100);
}
//13.忘记标记析构函数为virtual
class A {
public:
	virtual ~A()
	{
		std::cout << "A析构函数调用" << std::endl;
	}
};
class B :public A {
public:
	 ~B()override//添加override能够提醒父类的析构函数为virtual
	{
		std::cout << "B析构函数调用" << std::endl;
	}
};