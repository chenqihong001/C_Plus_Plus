#include <iostream>
#include "AboutChar.h"
#include "VSDebug.h"
struct Num
{
	int age;
	double sai;
};
int main()
{
	Num num{0};
	std::cout << num.age << "\n";
	std::cout << num.sai << "\n";

	return 0;
}