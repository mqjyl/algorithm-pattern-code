//
// Created by mqjyl on 2020/8/17.
//

#ifndef ALGORITHM_PATTERN_CODE_STACKANDQUEUE_H
#define ALGORITHM_PATTERN_CODE_STACKANDQUEUE_H
#include <stack>
#include <queue>

class StackAndQueue {

};

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        m_stack1 = new std::stack<int>();
        m_stack2 = new std::stack<int>();
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        m_stack1->push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(m_stack2->empty()){
            while(!m_stack1->empty()){
                m_stack2->push(m_stack1->top());
                m_stack1->pop();
            }
        }
        int re = m_stack2->top();
        m_stack2->pop();
        return re;
    }

    /** Get the front element. */
    int peek() {
        if(m_stack2->empty()){
            while(!m_stack1->empty()){
                m_stack2->push(m_stack1->top());
                m_stack1->pop();
            }
        }
        return m_stack2->top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return m_stack1->empty() && m_stack2->empty();
    }
private:
    std::stack<int> *m_stack1;
    std::stack<int> *m_stack2;
};

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        m_queue = new std::queue<int>();
    }

    /** Push element x onto stack. */
    void push(int x) {
        m_queue->push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int size = m_queue->size();
        while(size > 1){
            m_queue->push(m_queue->front());
            m_queue->pop();
            size--;
        }
        int re = m_queue->front();
        m_queue->pop();
        return re;
    }

    /** Get the top element. */
    int top() {
        int size = m_queue->size();
        while(size > 1){
            m_queue->push(m_queue->front());
            m_queue->pop();
            size--;
        }
        int re = m_queue->front();
        m_queue->pop();
        m_queue->push(re);
        return re;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return m_queue->empty();
    }
private:
    std::queue<int> *m_queue;
};


#endif //ALGORITHM_PATTERN_CODE_STACKANDQUEUE_H
