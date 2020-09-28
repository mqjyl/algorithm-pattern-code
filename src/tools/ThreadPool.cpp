//
// Created by mqjyl on 2020/9/26.
//

#include "../../include/tools/ThreadPool.h"
#include <iostream>
#include <algorithm>
#include <windows.h>

void ThreadPool::threadCallback(){
    while(1){
        // 没有任务则等待
        unique_lock<mutex> lock(mtx);
        cond.wait(lock, [this](){return !tasks.empty();});
        Task *task = tasks.top();
        if(task != nullptr){
            tasks.pop();
        }
        task->workerID = this_thread::get_id();
        lock.unlock();
        task->func(task->user_data, task->workerID);
    }
}
int ThreadPool::addOneTask(Task *task){
    unique_lock<mutex> lock(mtx);
    tasks.push(task);
    cond.notify_all();
    return 0;
}
int ThreadPool::threadCreate(int numWorkers){
    if(numWorkers <= 0)
        numWorkers = 1;
    for(int i = 0; i < numWorkers; i++){
        thread *worker = new thread(std::bind(&ThreadPool::threadCallback, this));
        if(worker != nullptr){
            cout << "new thread error" << endl;
            return -1;
        }
        workers.push_back(worker);
    }
    return 0;
}
int ThreadPool::threadDestory(){
    std::unique_lock<std::mutex> lock(mtx);
    cond.notify_all();
    for (vector<thread *>::iterator it = workers.begin(); it != workers.end() ; ++it)
    {
        (*it)->join();
        delete *it;
    }
    workers.clear();
    return 0;
}

void printer(int arg, thread::id workerID){
    cout << "thread" << " " << workerID << " " << arg << endl;
    Sleep(5);
}

// 0 --> 1000
int testThreadPool(){
    ThreadPool threadPool(10);
    int i = 0;
    for(i = 0; i <= 1000; i++){
        Task *task = new Task();
        task->func = printer;
        task->user_data = i;
        threadPool.addOneTask(task);
    }
    Sleep(8000);
    return 0;
}

