#pragma once
/*互斥量概念，用法，死锁演示及解决详解*/
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <list>
using std::cout;

//保护共享数据
//互斥量(mutex)，多个线程尝试加锁lock
/*
1.lock和unlock必须成对使用
2.std::lock_guard，防止忘记unlock
3.死锁（至少两把锁）
4.std::lock()函数模板，一次锁多个互斥量，如果其中一个互斥量没锁住，没有把所有的锁住，则会立马释放已锁的互斥量
  std::lock()需要自己手动unlock
*/

class Counter {
public:
    Counter() : count(0) {}

    void increment() {
      
        for (int i = 0; i < 1000000; ++i) {
            std::lock_guard<std::mutex>mutexGuard(m_mutex);//构造函数中调用lock，析构函数中调用unlock
            count++;
        }
    }
    int getCount() const {
        return count;
    }
private:
    int count;
    std::mutex m_mutex;
    
};
void SharedTest()
{
    Counter counter;

    // 创建两个线程，同时对共享资源进行递增操作
    std::thread thread1(&Counter::increment, &counter);
    std::thread thread2(&Counter::increment, &counter);

    // 等待两个线程完成
    thread1.join();
    thread2.join();

    // 打印最终的计数值
    std::cout << "Final Count: " << counter.getCount() << std::endl;//理想为200000
}
class Dead {
public:
    void Left()
    {
        for (int i = 0; i < 50000; i++)
        {
            std::lock(mutex2, mutex1);
            //std::lock_guard<std::mutex>leftMutex1(mutex1);
            //std::lock_guard<std::mutex>leftMutex2(mutex2);//
            std::lock_guard<std::mutex>leftMutex1(mutex1,std::adopt_lock);//放弃构造函数，及放弃lock
            std::lock_guard<std::mutex>leftMutex2(mutex2,std::adopt_lock);
            std::cout << "Left结束" << "\n";
        }
    }
    void Right()
    {
        for (int i = 0; i < 50000; i++)
        {
            //std::lock_guard<std::mutex>RightMutex1(mutex1);
            std::lock(mutex1, mutex2);
            //std::lock_guard<std::mutex>RightMutex2(mutex2);
            mutex1.unlock();
            mutex2.unlock();
            std::cout << "Right结束" << "\n";
        }
    }
private:
    std::mutex mutex1;
    std::mutex mutex2;
};
void DeadLockTest()
{
    Dead d;
    std::thread t1(&Dead::Left, &d);
    std::thread t2(&Dead::Right, &d);
    t1.join();
    t2.join();
}
void Main_6_5()
{
    DeadLockTest();
}