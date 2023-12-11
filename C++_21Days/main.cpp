#include <iostream>
#include <array>
#include "day9.h"
#include "day10.h"
#include "day11.h"
#include <memory>
int main()
{
	Base11* arr[10]{};
	std::unique_ptr<Derived11>d1(new Derived11());
	arr[0] = d1;
	Base11* brr = new Base11[10]{};

}