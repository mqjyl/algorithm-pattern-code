//
// Created by mqjyl on 2020/9/9.
//

#ifndef ALGORITHM_PATTERN_CODE_CIRCULARQUEUE_H
#define ALGORITHM_PATTERN_CODE_CIRCULARQUEUE_H

const int maxn = 100;

template <class T>
class CircularQueue {
public:
    CircularQueue();
    CircularQueue(const int len);
    ~CircularQueue();

public:
    bool empty();
    bool full();
    void push(T x);
    void pop();
    T front();
    int size();

private:
    void resize();

private:
    T *m_data;
    int m_front;
    int m_rear;
    int m_length;
};


void testCircularQueue();

#endif //ALGORITHM_PATTERN_CODE_CIRCULARQUEUE_H
