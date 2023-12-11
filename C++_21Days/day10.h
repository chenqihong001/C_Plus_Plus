#pragma once
/*实现继承*/
#include <iostream>
//数据抽象，protected继承->实现禁止继承层次结构外部对其进行修改
/*
	1.在派生类中覆盖基类的方法，即函数的所有特征一致
	2.在派生类中调用基类的方法，Animal::CoverFunc();在main中调用基类被覆盖方法，pig.Animal::CoverFunc();
	3.在派生类中隐藏基类的方法，子类对基类莫一方法的覆盖导致，基类中所有该方法的重载全部失效
		解决：1.main中使用::，pig.Animal::CoverFunc(true);
			 2.子类中使用using解除隐藏，using Animal::CoverFunc;
			 3.子类中覆盖所有的重载版本
*/
using std::cout;
using std::endl;
class Animal {
protected:
	int age{};
	std::string name;
public:
	Animal() {
		//std::cout << "Animal无参构造函数调用" << std::endl;
	};
	Animal(int _age, std::string _name) :age(_age), name(_name) {
		//std::cout << "Animal有参构造函数调用" << std::endl;
	}
	virtual ~Animal() {
		//std::cout << "Animal析构函数调用" << endl;
	}//virtual修饰析构函数
	void CoverFunc()
	{
		std::cout << "Animal覆盖测试调用" << endl;
	}
	void CoverFunc(bool test)
	{
		std::cout << "Animal重载版本覆盖测试" << endl;
	}//由于子类的覆盖，导致此方法失效
};
class Pig :public Animal {
public:
	using Animal::CoverFunc;
	Pig() = default;
	explicit Pig(int _age,std::string _name) :Animal(_age, _name) {
		//cout << "Pig有参构造函数调用" << endl;
	}//在子类的构造函数中，通过初始化列表的方式调用父类构造函数
	~Pig()
	{
		//std::cout << "Pig析构函数调用" << endl;
	}
	void CoverFunc()
	{
		//Animal::CoverFunc();//通过::在派生类中调用基类的方法
		std::cout << "Pig覆盖测试调用" << endl;
	}
};
/*	派生类对象调用基类被覆盖方法
	Pig pig;
	pig.CoverFunc();//调用基类中被覆盖的方法
	pig.Animal::CoverFunc();//加上作用域解析符
*/
class Sequence {
public:
	int age{};//先实例化成员属性，再调用构造函数
	Sequence() :age(18)
	{

	}
};