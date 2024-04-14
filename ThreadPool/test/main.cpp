#include <iostream>
#include <vector>
#include <functional>
#include <future>
#include <type_traits>
std::vector<std::packaged_task<void()>> taskQueue;

template <class Func, class... Args>
auto test(Func &&func, Args &&...args) -> std::future<decltype(func(args...))>
{
    using ReturnType = decltype(func(args...));
    std::cout << typeid(ReturnType).name() << std::endl;
    std::packaged_task<ReturnType()> task(std::bind(std::forward<Func>(func), std::forward<Args>(args)...)); // packaged_task封装
    auto future = task.get_future();
    taskQueue.emplace_back(std::move(task));
    return future;
}
// std::packaged_task<void()> task; 是可以复制，但是不可移动的
//  测试函数
void testFunc()
{
    std::cout << "Hello, world!" << std::endl;
}

void func()
{
    std::cout << "Func Test\n";
}

int main()
{
    auto res = test(func);
    // 调用任务
    taskQueue[0]();
    res.wait();
    return 0;
}
