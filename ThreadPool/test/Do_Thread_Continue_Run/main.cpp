#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
void task(int id)
{
    for (int i = 0; i < 10; ++i)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1)); // 线程休眠 1 秒
        std::cout << "task " << id << " 正在执行...\n";
    }
}
std::mutex mtx;
class Test
{
public:
    Test()
    {
        std::thread t(task, 89);
        t.join();
        std::cout << "Test 构造成功\n";
        // 阻塞Test对象的构造
    }
    ~Test()
    {
        std::cout << "Test 已经被销毁\n";
    }
};
int main()
{
    Test t;
    return 0;
}