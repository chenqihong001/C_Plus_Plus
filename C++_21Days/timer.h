#pragma once
#include <iostream>
#include <chrono>

enum Level
{
    milliseconds, // 毫秒
    microseconds, // 微妙
    nanoseconds   // 纳秒
};

template <Level LEVEL = milliseconds>
class Timer
{
public:
    Timer() : time_begin(std::chrono::high_resolution_clock::now()) {}
    ~Timer()
    {
        time_end = std::chrono::high_resolution_clock::now();
        long long time;

        switch (LEVEL)
        {
        case milliseconds:
            time = std::chrono::duration_cast<std::chrono::milliseconds>(time_end - time_begin).count();
            std::cout << "执行时间：" << time << "ms" << std::endl;
            break;
        case microseconds:
            time = std::chrono::duration_cast<std::chrono::microseconds>(time_end - time_begin).count();
            std::cout << "执行时间：" << time << "us" << std::endl;
            break;
        default:
            time = std::chrono::duration_cast<std::chrono::nanoseconds>(time_end - time_begin).count();
            std::cout << "执行时间：" << time << "ns" << std::endl;
            break;
        }
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> time_begin;
    std::chrono::time_point<std::chrono::high_resolution_clock> time_end;
};
