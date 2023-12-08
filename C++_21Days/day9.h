#pragma once
/*类和对象*/
#include <iostream>
//推荐使用private实现数据抽象
/*应该:
  1.类包含原始指针成员（char*...），务必编写复制构造函数和复制赋值运算符
  2.编写拷贝构造函数时，务必将接受源对象的参数声明为const引用
  3.声明构造函数的时候多考虑使用explicit，拒绝隐式转换
  4.务必将类成员声明为std::string和智能指针（可以避免重写拷贝构造函数）
*/
class Day9Test {
public:
	void SetAge(int age)
	{
		this->age = age;
	}
	int GetAge()
	{
		return this->age;
	}
	Day9Test(const Day9Test& day9) {//自己重载一个构造函数之后，编译器将不再提供默认的构造函数
		std::cout << "拷贝构造函数调用" << "\n";
		this->age = day9.age;
		this->name = day9.name;
	}
	explicit Day9Test(int _age, std::string _name) :age(_age), name(_name), {}
	//带默认值的构造函数
	// Day9Test(const char* add) : str(add), age(18), name("") {
	// 初始化成员列表中的顺序是按照，在类中声明的顺序}
private:
	int age;
	std::string name;
};
//::作用域解析符
//POD类型(Plain Old Data)
//深浅拷贝的问题
class Day9CopyQuestion
{
public:
	int* data;
	Day9CopyQuestion():data(nullptr)
	{
		data = new int[10] {0};
	}
	
	Day9CopyQuestion(const Day9CopyQuestion& day9)
	{
		this->data = new int[10] {0};
	}
	// 赋值运算符的重载
	Day9CopyQuestion& operator=(const Day9CopyQuestion& other) {
		this->data = new int[10] {0};
		return *this;
	}
	~Day9CopyQuestion()
	{
		std::cout << "Day9CopyQuestion析构函数调用" << "\n";
			delete[]data;
	}
};

//9.5.3有助于改善性能的移动构造函数

