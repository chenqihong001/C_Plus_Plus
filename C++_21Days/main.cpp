#include <iostream>
#include <cstdarg>

// 可变参数函数示例
double average(int count, ...) {
    va_list args;  // 定义一个va_list对象来存储可变参数
    va_start(args, count);  // 初始化args，使其指向可变参数列表的第一个参数

    double sum = 0;
    for (int i = 0; i < count; ++i) {
        sum += va_arg(args, double);  // 从可变参数列表中获取参数
    }

    va_end(args);  // 结束对可变参数的访问

    return sum / count;
}

int main() {
    std::cout << "Average: " << average(3, 1.0, 2.0, 3.0) << std::endl;

    return 0;
}
