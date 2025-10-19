//
// Created by mqjyl on 2020/8/17.
//
#include <iostream>
#include "../include/StackAndQueue.h"

using namespace std;

// 用一个栈实现另一个栈的排序
void StackAndQueue::sortStack(std::stack<int>& stk){
    stack<int> t_stk;
    while(!stk.empty()){
        int k = stk.top();
        stk.pop();
        while(!t_stk.empty() && k > t_stk.top()){ // >= 不可以，全相等的特例会死循环
            stk.push(t_stk.top());
            t_stk.pop();
        }
        t_stk.push(k);
    }
    while(!t_stk.empty()){
        stk.push(t_stk.top());
        t_stk.pop();
    }
}

void test_sortStack(){
    StackAndQueue stackAndQueue;
    stack<int> stk;
    int n = 0, a = 0;
    cin >> n;
    while(n-- > 0){
        cin >> a;
        stk.push(a);
    }
    stackAndQueue.sortStack(stk);
    while(!stk.empty()){
        cout << stk.top() << " ";
        stk.pop();
    }
}