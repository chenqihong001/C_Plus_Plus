# ThreadPool

## 属性

1. __任务队列__ ->taskQueue
2. __线程池大小__ ->size
3. __线程池状态__ -> stop
4. __线程池线程数组__ -> vector<std::thread>threads
5. __线程池任务队列锁__ -> std::mutex taskMtx
6. __线程池任务队列条件变量__ ->std::condition_variable taskCv

## 方法Function

1. __构造函数__ ->ThreadPool(int size, std::function<void(int)> task)
2. __析构函数__ ->~ThreadPool()
3. __添加任务__ ->void enqueueu(int task)
4. __执行任务__ ->void run()

## 实现

1. taskQueue -> std::queue<std::function<void()>>taskQueue
    > 把任务封装成std::function<void()>
2. threads线程池线程数组 -> std::vector<std::thread>threads

## 问题

1. std::function和std::packaged_task区别
    > std::function和std::packaged_task封装对象后都可以直接调用
    > 但是std::packaged_task不能直接获得返回值结果
2. **不要再互斥区域执行函数func/任务task**

## 要点

1. std::condition_variable的使用
2. 如何利用模板将任意类型的function封装成std::function<void()>
3. 线程池的销毁 -> stop = true; taskCv.notify_all(); 等待所有线程退出
4. 线程每次取出任务队列TaskQueue的front队首，并出队pop
5. **std::packaged_task是不可复制的 -> 只能移动**
6. std::bind() 返回可调用对象 ->
7. **不要再互斥区域执行函数func/任务task**

## 互斥变量

1. taskQueue 任务队列
2. 条件判断的过程需要原子 condition.wait(std::unique_lock<std::mutex>,[]{return});

## 总结和分析

1. 对于template<typename Func,typename ...Args> 的使用不对 特别是 ...args和args...
2. 错误理解emplace()的使用  vec.emplace(std::move(pkg)); -> 这样还是调用了 pkg的拷贝构造
3. 即std::function和std::packaged_task的相互构造转换
4. 注意std::move的使用，会使得task对象失效，此时再get_future将不再有效
5. 不要在锁区域中调用func()函数，会使得某一线程一直处于该临界区

```cpp
auto future = task.get_future(); // 保存 future 对象
auto moved_task = std::move(task);
```
