/*模板*/
/*
	1.模板类与静态成员
	2.使用参数数量可变的模板的函数
*/
#include <iostream> 
using namespace std;
template < typename T1 = int, typename T2 = double>
class HoldsPair {};
template<> class HoldsPair < int, int> {};
//函数模板具体化，和类模板具体化稍有不同
template<typename T1 = int>
void Print(T1 val)
{
	std::cout << "普通模板" << std::endl;
	std::cout << val << std::endl;
}
template<>
void Print<std::string>(std::string val)
{
	std::cout << "具体化模板调用" << std::endl;
	std::cout << val << std::endl;
}
template<class T>
class ClassStaticFunc {
public:
	int age = 789;
	std::string name = "哈哈";
	//static int storage = 0;静态成员变量不可在类内初始化
	/*static void Print()
	{
		std::cout << age << name << std::endl;
	}静态成员函数不可以访问非静态成员*/
	static int static_storage;
	void SetAge();
	static void Cout()
	{
		//SetAge();静态成员函数不可调用非静态成员函数和变量
		std::cout << "I am the Best" << std::endl;
	}
};
template<typename T>
int ClassStaticFunc<T>::static_storage = 999999;


template<typename Res,typename First,typename...Rest>
void Sum(Res& result, First val1, Rest...valn)
{
	result = result + val1;
	return Sum(result, valn...);
}

