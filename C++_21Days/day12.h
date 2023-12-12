#pragma once
#include <iostream>
#include <string>
#include <sstream>
/*---运算符类型与运算符重载---*/
/*
	1.可重载的单目运算符：（++,--,*,->,!,&,~,+,-）
	2.prefix++,postfix++
	3.转换运算符，通过explicit可以禁止隐式类型转换，要求程序员使用强制类型转换来确认转换意图
	4.注意：不要返回局部变量的地址，在返回类型为指针或引用类型的时候要注意
	5.解除引用运算符*，和成员选择->
*/
class Date {
public:
	explicit Date(int _day, int _month, int _year) :day(_day), month(_month), year(_year) {}
	Date& operator++ ()//前缀递增运算符
	{
		//implementation
		++day;
		return *this;
	}
	//postfix differs from prefix operator in return-type and paramaters
	Date operator++(int)//后缀++运算符，返回值不同，有一个输入参数
	{
		Date copy(this->day, this->month, this->year);//拷贝一个副本
		++day;
		return copy;
	}
	void DisplayDate()
	{
		std::cout << year << ":" << month << ":" << day << std::endl;
	}
	explicit operator const char* ()//一般用于将对象转为const char*类型的指针
	{
		std::ostringstream formattedData;
		formattedData << year << ":" << month << ":" << day;
		str = formattedData.str();
		return str.c_str();//返回指向str的指针，注意str的生命周期
		//注意：不要返回局部变量的地址，在返回类型为指针或引用类型的时候要注意
	}//cout能够理解const chat *


private:
	int day,month,year;
	std::string str;
};


/*常见的类型转换操作符*/
/*
	1.static_cast（基本的数据类型转换）
	2.dynamic_cast（通常用于处理基类和派生类的转换）
	3.const_cast（不推荐滥用）
	4.reinterpret_cast（十分危险）
*/
/*常见的智能指针*/
/*
	1.std::shared_ptr
	2.std::unique_ptr
	3.std::weak_ptr（）
	4.std::auto_ptr（已弃用）
	
*/