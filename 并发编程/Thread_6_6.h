#pragma once
#include <iostream>
#include <thread>
/*unique_lock详解*/
/*
	unique_lock可以自动解锁和手动解锁
*/
/*第二个参数*/
//1.std::adopt_lock; 表示这个互斥量已经被lock
//2.std::try_to_lock; 禁止提前lock .owns_lock()是否拿到锁
//3.std::defer_lock; 没有提前加lock
/* 共享锁，递归锁 */
class MulThread {
public:
	int publicData{};
	void Add1()
	{
		for (int i = 0; i < 500000; i++)
		{
			std::lock_guard<std::mutex> u_lock1(_mutex);
				publicData++;
		}
	}

	void Add2()
	{
		for (int i = 0; i < 500000; i++)
		{
			_mutex.lock();//_mutex手动加锁
			std::unique_lock<std::mutex>u_lock2(_mutex,std::adopt_lock);
			publicData++;
		}
	}
private:
	std::mutex _mutex;
};
void Thread_6_Test()
{
	MulThread t;
	std::thread t1(&MulThread::Add1, std::ref(t));
	std::thread t2(&MulThread::Add2, std::ref(t));
	t1.join();
	t2.join();
	std::cout << t.publicData << std::endl;
}


