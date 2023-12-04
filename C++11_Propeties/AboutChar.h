#pragma once
#include <iostream>
#include <string>
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
void test_C_Str()
{
	const char* str = "123456";
	char sr[] = "123456";//c风格字符串
	std::string name = "我是小丑";
	char* tes = sr;//可以用char *去接收c风格的字符串,但是不可以接收字符串字面值
	//char* point = name;char *不可以接收string
	const char* poin = name.c_str();
	std::cout << sr << std::endl;
	std::cout << str << std::endl;
	std::cout << tes << std::endl;
	const char* source = "哈";
	char destination[20]; // 请确保目标缓冲区足够大来容纳源字符串

	// 使用 strcpy_s 进行字符串复制
	strcpy_s(destination, sizeof(destination), source);
	std::cout << destination << std::endl;
}