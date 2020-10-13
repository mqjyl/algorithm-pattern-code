//
// Created by mqjyl on 2020/9/12.
//

#include "../../include/tools/WfirstRWLock.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <future>
#include <ctime>
using namespace std;

void WfirstRWLock::lock_read(){
    unique_lock<mutex> lock(m_mutex);
    m_cond_read.wait(lock, [this]()->bool{return m_count_write == 0;});
    ++ m_count_read;
}

void WfirstRWLock::lock_write(){
    unique_lock<mutex> lock(m_mutex);
    m_cond_write.wait(lock, [this]()->bool{return m_count_read == 0 && !m_write_flag;});
    ++ m_count_write;
    m_write_flag = true;
}

void WfirstRWLock::release_read(){
    unique_lock<mutex> lock(m_mutex);
    -- m_count_read;
    if(m_count_read == 0 && m_count_write > 0){
        m_cond_write.notify_one();
    }
}

void WfirstRWLock::release_write(){
    unique_lock<mutex> lock(m_mutex);
    -- m_count_write;
    if(m_count_write == 0){
        m_cond_read.notify_all();
    }else{
        m_cond_write.notify_one();
    }
    m_write_flag = false;
}

#if 1
static WfirstRWLock wfirstRwLock;
static int number = 1;

void getVal(promise<int> &pro){
    wfirstRwLock.lock_read();
    pro.set_value(number);
    this_thread::sleep_for(std::chrono::milliseconds(30));
    wfirstRwLock.release_read();
}

void putVal(int val){
    wfirstRwLock.lock_write();
    number = val;
    this_thread::sleep_for(std::chrono::milliseconds(100));
    wfirstRwLock.release_write();
}

void testRWLock(){
    srand((unsigned)time(NULL));
    for(int i = 0; i < 30; i++){
        int k = rand() % 10;
        if(k < 6){
            std::promise<int> resPro;
            std::future<int> resObj = resPro.get_future();
            thread r(getVal, std::ref(resPro));
            cout << resObj.get() << endl;
            r.join();
        }else{
            thread w(putVal, k + 1);
            w.join();
        }
    }
}
#endif