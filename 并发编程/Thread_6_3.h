#pragma once
#include <iostream>
#include <thread>
#include <memory>
/*总结*/
/*
  1）传递临时对象作为线程参数
  2）传递类对象，智能指针作为线程参数
  3）用成员函数指针做线程函数


*/
void Test_2_3(int & num)
{	 
	num = 9999;
}
//智能指针
void MySmartTest(std::unique_ptr<int>ptr)
{
	*ptr = 79879;
}
void SmartThreadTest()
{
    int* a = new int{ 55 };
    std::unique_ptr<int>pa(a);//智能指针用于保护动态创建的内存
    std::cout << *a << "\n";
    std::thread th(MySmartTest, std::move(pa));//通过move去传入右值引用
    th.join();
    //move之后原指针失去权限
    std::cout << *a << "\n";
}
//向线程中，传入成员函数
class Person {
public:
    void operator()(std::string str)
    {
        std::cout << "仿函数调用" << str << "\n";
    }
    int age{};
    void PersonTest(std::string name)
    {
        std::cout << "I am the best Person" << name << "\n";
    }
    Person(const Person& p) = default;
    Person() = default;
  
};
void MainTest_2_3()//通过类的成员函数创建线程
{
    Person p{};//Person p();声明一个函数，并非创建一个对象
   // std::thread th(&Person::PersonTest, std::ref(p), "Person Test Chen");//三个参数
    //th.join();//可以通过ref传入p的引用,也可以用&p
}//注意通过无参构造创建对象时，不要Type p();声明函数，用Type p{}
void OperatorTest()
{
    Person p;
    std::thread th{p,"niacas"};
    th.join();
}
