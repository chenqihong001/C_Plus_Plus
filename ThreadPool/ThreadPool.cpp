#include <iostream>
#include "ThreadPool.h"
#include <thread>
// #include "Timer.h"
void test(int id)
{
    int res{};
    for (int i = 0; i < 1000; ++i)
    {
        res = (res % 180000000 * i % 18000000) % 180000000;
    }
}

std::vector<std::thread> pools;
int main()
{
    // Timer t;
    ThreadPool pool(400);
    for (int i = 0; i < 4000; ++i)
    {
        pool.enqueue(test, i);
    }
    for (auto &i : pools)
        i.join();
    return 0;
}