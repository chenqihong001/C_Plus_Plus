#include <iostream>
void test(const int val)
{
	int temp = val;
	temp += 100;
	std::cout << temp;
}
int main()
{
	const int VAL = 555;
	test(VAL);
	return 0;
}