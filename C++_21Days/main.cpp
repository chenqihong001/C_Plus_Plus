#include <iostream>
#include <array>
#include "day9.h"
#include "day10.h"
#include "day11.h"
#include "day12.h"
#include <memory>
int main()
{
	Date d(21, 3, 2004);
	std::cout << (const char*)d<<"\n";//使用强制类型转换来确认转换意图
	//Date d1 = { 11,5,2003 };隐式类型转换
	std::string str(static_cast<const char*>(d));
	std::cout << str;
}