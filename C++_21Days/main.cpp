#include <iostream>
#include <array>

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
int main()
{
    int arr[10]{ 0 };//初始化列表的方式
    int* num = new int();
    int da = 45;
    std::cout << num;
    int* rm = num;
    num = &da;
    delete rm;
    rm = nullptr;
}