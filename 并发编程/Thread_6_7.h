#include <iostream>
#include <map>
#include <list>
#include <thread>
#include <mutex>
//单例设计模式
std::mutex m_mutex;
std::once_flag g_flag;
class Singleton
{
private:
	Singleton() {}
private:
	static Singleton* m_instance;
public:
	//方法1
	static Singleton* GetInstance_Simple()
	{
		if (m_instance == nullptr)//双重检查锁定模式
		{
			std::lock_guard<std::mutex>guard_thread(m_mutex);//频繁的调用 lock_guard会导致效率极低
			if (m_instance == nullptr)
			{
				m_instance = new Singleton();
			}
		}
		return m_instance;
	}
	//方法2
	static Singleton& GetInstance_SmartPtr()
	{
		std::unique_ptr<Singleton>instance(new Singleton);
		return *instance;
	}
	//方法3
	//类中套类，利用RAII资源获得及初始化，引入静态对象
	static void DestoryInstance()
	{
		if (m_instance != nullptr)
		{
			delete m_instance;
			m_instance = nullptr;
		}
	}
	//方法4
	static Singleton GetInstance_CallOnce()
	{
		std::call_once(g_flag,CreateInstance);//g_flag类似于一次性锁
	}
	//删除拷贝构造和赋值构造函数
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
private:
	static void CreateInstance()//只被调用一次
	{
		m_instance = new Singleton();
	}
};
//静态变量初始化
Singleton* Singleton::m_instance = nullptr;
void Main_6_7()
{
	Singleton* singleton = Singleton::GetInstance_Simple();
	Singleton::DestoryInstance();
}
//三、单例设计模式共享数据问题分析，解决
//多线程并发->单例类的GetInstance()需要互斥，否则会导致多个单例对象的创建

//四、std::call_once()，保证某函数只被调用一次，需要与标记(std::once_flag)结合使用