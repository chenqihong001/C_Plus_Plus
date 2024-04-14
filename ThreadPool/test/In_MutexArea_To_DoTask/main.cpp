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
void test(int id)
{
    std::unique_lock<std::mutex> lock(mtx);
    {
        task(id);
    }
}
int main()
{
    std::thread t1(test, 88);
    std::thread t2(test, 99);
    t1.join();
    t2.join();
    return 0;
}