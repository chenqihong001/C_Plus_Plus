#pragma once
#include <iostream>
#include <chrono>
class Timer
{
public:
    Timer() : time_begin(std::chrono::high_resolution_clock::now()) {}
    ~Timer()
    {
        time_end = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::milliseconds>(time_end - time_begin).count();
        std::cout << "执行时间：" << time << "ms" << std::endl;
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> time_begin;
    std::chrono::time_point<std::chrono::high_resolution_clock> time_end;
};