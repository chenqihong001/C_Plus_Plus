#pragma once
#include <iostream>
#include <array>
//指针递增，递减的结果，其包含的地址将加sizeof(Type),确保不会指向数据的中间或结尾
//将关键字const用于指针

/*
	1.指针包含的地址是常量int* const data = &d;
	2.指针指向的数据是常量const int* data = &d;
	3.const int* const data = &d;
*/
//将指针作为参数传递给函数的时候，确保函数只能修改您希望修改的变量（使用const约束）
//数组变量是指向第一个元素的指针   int arr[10]{0};int* p = arr;
//****数组是静态的，不能作为左值
void Day8Test()
{
    int arr[10]{ 1 };
    int* p;
    p = arr;//可将arr赋给p
    //arr = p;//arr不可作为左值
}
//内存泄露
/*
    1.指针声明时初始化
    2.有new记得delete
    3.应该要避免指针拷贝,int* const ptr = new int();
*/
//悬浮指针
/*
    措施：在初始化指针或释放指针后，将其设置为nullptr,并在对指针解引用时，检查他是否有效
*/
//new内存分配失败，发出std::bad_alloc异常
//应该：
// 1.务必初始化指针变量
// 2.务必仅在指针有效时使用他
// 3.new后delete

//《引用》
/*
    引用即别名
    将const用于引用
    优点：避免将实参复制给形参，极大地提高性能

*/







//std::array->include<array>
void Print(std::array<int, 5> arr)
{
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    const size_t t = 78;
    std::array<int, t>myArray{ 0 };//初始化
    myArray.fill(0);//用0填充
    int* pointer = myArray.data();
    myArray.at(0) = 99;
    std::cout << *pointer;
}