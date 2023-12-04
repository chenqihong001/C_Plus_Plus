#include <iostream>
#include "AboutChar.h"
#include "VSDebug.h"
void testDebug()
{
	int temp_a = 789;
	temp_a += 100;
	int a = 0;
	int ta = a++;
	int tb = ++a;
}
void note()
{
/*
	VS常用调试技巧
	1.查看临时变量的值
	2.查看内存信息
*/
}
int main()
{
	testDebug();
}