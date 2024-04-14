#include <iostream>
#include <queue>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <future>
#include <thread>
#include <memory>
#include <stdexcept>

class ThreadPool
{
public:
    ThreadPool(int thread_size) : stop(false)
    {
        for (int i = 0; i < thread_size; ++i)
        {
            threadPools.emplace_back([this]
                                     {
                while (true) {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(queue_mutex);
                        cv.wait(lock, [this] { return stop || !tasks.empty(); });
                        if (stop && tasks.empty())
                            return;
                        task = std::move(tasks.front());
                        tasks.pop();
                    }
                    task();
                } });
        }
    }

    template <typename Func, typename... Args>
    auto enqueue(Func &&func, Args &&...args) -> std::future<decltype(func(args...))>
    {
        using returnType = decltype(func(std::forward<Args>(args)...));
        auto task = std::make_shared<std::packaged_task<returnType()>>(std::bind(std::forward<Func>(func), std::forward<Args>(args)...));
        auto res = task->get_future();
        {
            std::lock_guard<std::mutex> lock(queue_mutex);
            if (stop)
            {
                throw std::runtime_error("enqueue on stopped ThreadPool");
            }
            tasks.emplace([task]()
                          { (*task)(); });
        }
        cv.notify_one();
        return res;
    }

    ~ThreadPool()
    {
        {
            std::lock_guard<std::mutex> lock(queue_mutex);
            stop = true;
        }
        cv.notify_all();
        for (auto &th : threadPools)
            th.join();
    }

private:
    std::vector<std::thread> threadPools;
    std::queue<std::function<void()>> tasks;
    std::mutex queue_mutex;
    bool stop;
    std::condition_variable cv;
};
