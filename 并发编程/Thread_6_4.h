#pragma once
/*创建多个线程，数据共享问题分析，案例代码*/
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <list>
using std::cout, std::endl;
using std::thread, std::vector;
//共享数据
vector<int>shared_datas{11,222,333,4444,55555};

//线程入口函数
void print(int index)
{
	cout << "线程函数" << index << "号" << endl;
	return;
}
void Test1()
{
	//1.创建多个线程
	vector<thread>myThreads;
	for (int i = 0; i < 10; i++)
	{
		myThreads.push_back(thread(print, i));//对象数组，创建多个线程到容器中去管理
	}
	for (auto& th : myThreads)//std::thread是不可拷贝的，而是只能移动，所以不能通过auto th 去取thread
	{
		th.join();//如果用const去限制，则不能join
	}//线程的执行是混乱的
	cout << "I love China" << endl;
	//2.数据共享问题分析（1.只读数据 2.可读可写数据）
}
class A {
public:
	//把收到的玩家信息输入消息队列
	void inMsgRecQueue()
	{
		for (int i = 0; i < 100000; ++i)
		{
			cout << "iniMsgRecQueue执行，插入" << i << "\n";
			msgRecQueue.push_back(i);//假设插入消息队列
		}
	}
	//取出消息队列中的玩家指令信息
	void outMsgRecQueue()
	{
		for (int i = 0; i < 100000; ++i)
		{
			if (!msgRecQueue.empty())
			{
				int command = msgRecQueue.front();//.front获取第一个元素的引用
				msgRecQueue.pop_front();//移除
			}
			else
			{
				std::cout << "消息队列为空" << i << std::endl;
			}
		}
	}
private:
	std::list<int>msgRecQueue;//玩家命令容器
};

void Main_6_4()
{
	A m_obj;
	std::thread myOutMsgObj(&A::outMsgRecQueue, std::ref(m_obj));//传入对象引用
	std::thread myInMsgObj(&A::inMsgRecQueue, std::ref(m_obj));
	myOutMsgObj.join();
	myInMsgObj.join();
}
//互斥量


	
