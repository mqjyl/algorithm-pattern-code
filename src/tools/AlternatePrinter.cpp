//
// Created by mqjyl on 2020/9/13.
//
#include <iostream>
#include <chrono>
#include <windows.h>
#include "../../include/tools/AlternatePrinter.h"
using namespace std;

std::mutex mtx;
std::condition_variable cond;
bool flag = true;
static int num = 1;

void thread1(){
    while(num <= 20){
        unique_lock<mutex> lock(mtx);
        cond.wait(lock, []{return flag;});
        cout << "Thread 1 :" << num << endl;
        num++;
        flag = false;
        cond.notify_one();
        this_thread::sleep_for(std::chrono::seconds(1));
    }
}
void thread2(){
    while(num <= 20){
        unique_lock<mutex> lock(mtx);
        cond.wait(lock, []{return !flag;});
        cout << "Thread 2 :" << num << endl;
        num++;
        flag = true;
        cond.notify_one();
        this_thread::sleep_for(std::chrono::seconds(1));
    }
}
void testAlternatePrinter(){
    thread t1(thread1);
    thread t2(thread2);
    t1.join();
    t2.join();
}

//std::mutex mtx;
//std::condition_variable cond1, cond2;
//static int num = 1;
//
//void thread1(){
//    while(true){
//        unique_lock<mutex> lock(mtx);
//        cout << "Thread 1 :" << num << endl;
//        num++;
//        cond2.notify_one();
//        if(num >= 20)
//            return;
//        cond1.wait(lock);
//        Sleep(1000);
//    }
//}
//void thread2(){
//    while(true){
//        unique_lock<mutex> lock(mtx);
//        cout << "Thread 2 :" << num << endl;
//        num++;
//        cond1.notify_one();
//        if(num >= 20)
//            return;
//        cond2.wait(lock);
//        Sleep(1000);
//    }
//}
//void testAlternatePrinter(){
//    thread t1(thread1);
//    thread t2(thread2);
//    t1.join();
//    t2.join();
//}