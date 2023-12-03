#pragma once
#include <iostream>
void TestAboutChar()
{
	char const* const data = "String";//必须要初始化
	//char* message = "啊八八八";试图去用一个字符指针接收字符串常量是不被允许的
	char message[] = "12";
	//message = "12345";//试图去用一个字符指针去接收一个字符串常量是不被允许的额
	const char me[] = "哈哈哈啊";
	//me = "u按上窜";
	std::cout << me;
	const char* const str = "45";
	//字符串常量和字符串字面值是一个概念,是不可修改的
}