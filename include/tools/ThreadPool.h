//
// Created by mqjyl on 2020/9/26.
//

#ifndef ALGORITHM_PATTERN_CODE_THREADPOOL_H
#define ALGORITHM_PATTERN_CODE_THREADPOOL_H
#include <mutex>
#include <condition_variable>
#include <thread>
#include <queue>
#include <functional>
#include <list>

using namespace std;

struct Task{
    void (*func)(int arg, thread::id workerID);
    int user_data;
    thread::id workerID;
    Task() : user_data(0){}
};

class ThreadPool {
public:
    ThreadPool(int numWorkers, int maxNum = 20) : max_count(maxNum) {
        if(numWorkers > maxNum)
            numWorkers = maxNum;
        num_workers = numWorkers;
        int res = threadCreate(num_workers);
    }
    ~ThreadPool(){
        threadDestory();
    }
    int addOneTask(Task *task);

private:
    int threadCreate(int numWorkers);
    int threadDestory();
    void threadCallback();

    ThreadPool(const ThreadPool&); //禁止复制拷贝.
    const ThreadPool& operator=(const ThreadPool&);

private:
    std::mutex mtx;
    std::condition_variable cond;

    priority_queue<Task *> tasks;
    vector<thread *> workers;

    int num_workers;
    const int max_count;
};

int testThreadPool();

#endif //ALGORITHM_PATTERN_CODE_THREADPOOL_H
