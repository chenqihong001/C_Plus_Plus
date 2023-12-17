/*  1.仿函数
    2.谓词->返回值为bool的仿函数
*/
/*
    1.find_if()
    2.sort();
*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>
#include <functional> //提供了一些常用的谓词
/*
    <functional>中的常用谓词
    template<class T> bool equal_to<T>//等于
    template<class T> bool not_equal_to<T>//不等于
    template<class T> bool greater<T>//大于
    template<class T> bool greater_equal<T>//大于等于
    template<class T> bool less<T>//小于
    template<class T> bool less_equal<T>//小于等于
*/
/*
<algorithm>中的常用函数
查找算法：
std::find：在范围内查找特定值。
std::find_if：在范围内查找满足给定条件的元素。
std::find_if_not：在范围内查找不满足给定条件的元素。
std::binary_search：在有序范围内执行二分查找。

排序算法：
std::sort：对范围内的元素进行排序。
std::stable_sort：对范围内的元素进行稳定排序。
std::partial_sort：对范围内的部分元素进行排序。
std::nth_element：将范围内的元素按照第 n 个位置进行划分。

遍历和修改算法：
std::for_each：对范围内的每个元素应用函数。
std::transform：对范围内的元素应用一个函数，并将结果存储到另一个范围。
std::replace：将范围内的指定值替换为新值。
std::remove：从范围内移除指定值。

数值算法：
std::accumulate：对范围内的元素进行累加。
std::inner_product：计算两个范围的内积。
std::partial_sum：计算范围的部分和。

其他算法：
std::copy：将一个范围的元素复制到另一个范围。
std::rotate：将范围内的元素循环右移。
std::next_permutation：生成下一个排列。
std::prev_permutation：生成前一个排列。

*/
// 函数对象适配器

class Predicate
{
public:
    // bool operator()(int num) // 一元谓词
    // {
    //     return num > 8;
    // }
    bool operator()(int a, int b) // 二元谓词
    {
        return a > b;
    }
    void operator()(int val)
    {
        std::cout << val << " ";
    }
};
void Print(int val)
{
    std::cout << val << " ";
}
int main()
{
    std::random_device rd; // 随机数生成引擎，提供的硬件熵作为种子
    auto ty = rd();
    std::cout << typeid(ty).name() << std::endl;
    std::vector<int> array{1, 8, 5, 6, 2, 3, 5, 7, 8, 9, 8, 11, 23, 55};
    std::sort(array.begin(), array.end(), std::greater<int>());
    std::for_each(array.begin(), array.end(), [](int val)
                  { std::cout << val << " "; });
    std::cout << std::endl;
    std::mt19937 g(rd());
    std::shuffle(array.begin(), array.end(), g);
    std::for_each(array.begin(), array.end(), Print);
}
