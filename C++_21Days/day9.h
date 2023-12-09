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
	explicit Day9Test(int _age, std::string _name) :age(_age), name(_name){}
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
namespace day9 {
//9.5.3有助于改善性能的移动构造函数
class Person
{
public:
	int age{};
	mutable int money{ 100 };
	//自定义拷贝构造函数，此时编译器不再提供默认构造函数
	Person() = default;
	Person(const Person& p)
	{
		this->age = p.age;
		std::cout << "拷贝构造函数调用" << "\n";
	}
	//移动拷贝构造函数
	Person(const Person&& p)noexcept
	{
		this->age = age;
		std::cout << "移动构造函数调用" << std::endl;
	}
	void ChangeValue()const 
	{
		//this->age = 999;
		this->money = 99999999;//mutable修饰的变量，能使在const修饰的成员函数中，依旧能修改其值
	}
private:
	int password{ 19923 };
	friend void FriendAccess(const Person&p);//全局函数友元
	friend class FriendClass;
};
//使用friend，让外部函数能够访问私有数据成员
void FriendAccess(const Person& p)
{
	std::cout << p.password << "\n";
}
//使用friend，让外部类能够访问私有数据成员
class FriendClass {
public:
	FriendClass(const Person &p)
	{
		std::cout << "我是好朋友" << p.password << std::endl;
	}
};

//共用体：一种特殊的类，每次只有一个非静态数据成员处于活动状态
union MyUnion//成员默认公有，不可继承，sizeof()返回最大的数据类型的大小，无论该数据类型是否启用
{
	int age;
	//std::string name;共用体中不能含有std::string,其中存在动态分配内存的情况
	float weight{ 0.0f };//一个联合最多只能有一个有初始值
	~MyUnion() {}
	MyUnion() = default;
};

/*构造函数和析构函数的其他用途*/
	//9.6.1不允许复制的类
	//9.6.2只能有一个实例的类
	//9.6.3禁止在栈中实例化的类
	//9.6.4使用构造函数进行类型转换
	//9.9  结构不同与类的地方，即继承和内部的默认修饰不同，类为private，结构为public
	//9.10 声明友元
	//9.11 共用体
	//9.12 对类和结构使用你聚合初始化aggregate initialization


/*聚合初始化可用于聚合类型*/ 
//某些类属于聚合类型：1.全公有，非静态 2.无virtual 3.只涉及public继承 4.不包好用户自定义的构造函数
class AggregateTest
{
public:
	int age;
	int arr[3];
	std::string name;
	//无自定义构造函数
	//全public
	void Show()
	{
		std::cout << "age:" << age << "\n";
		std::cout << "arr:" << arr[0]<<arr[1]<<arr[2] << "\n";
		std::cout << "name:" << name << "\n";
	}
};
//day9::AggregateTest aggregate{ 18,{1,2,3},"小黑子" };
//aggregate.Show();
//对共用体使用聚合初始化：只会初始化第一个非静态成员，不推荐使用

}	


