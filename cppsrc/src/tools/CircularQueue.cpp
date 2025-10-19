//
// Created by mqjyl on 2020/9/9.
//

#include "../../include/tools/CircularQueue.h"
#include <new>
#include <iostream>
#include <vector>

using namespace std;
template <class T>
CircularQueue<T>::CircularQueue(){
    m_front = 0;
    m_rear = 0;
    m_data = new T[maxn];
    m_length = maxn;
}

template <class T>
CircularQueue<T>::CircularQueue(const int len){
    m_front = 0;
    m_rear = 0;
    m_data = new T[len];
    m_length = len;
}

template <class T>
CircularQueue<T>::~CircularQueue(){
    delete[] m_data;
    m_data = nullptr;
}

template <class T>
bool CircularQueue<T>::empty(){
    return m_front == m_rear;
}

template <class T>
bool CircularQueue<T>::full(){
    return m_front == (m_rear + 1) % m_length;
}

template <class T>
void CircularQueue<T>::push(T x){
    if(full()){
        resize();
    }
    m_data[m_rear] = x;
    m_rear = (m_rear + 1) % m_length;
}

template <class T>
void CircularQueue<T>::pop(){
    if(empty()){
        return;
    }
    m_front = (m_front + 1) % m_length;
}

template <class T>
T CircularQueue<T>::front(){
    if(!empty()){
        return m_data[m_front];
    }
    return T();
}

template <class T>
int CircularQueue<T>::size(){
    return (m_rear - m_front + m_length) % m_length;
}

template <class T>
void CircularQueue<T>::resize(){
    int len = int(m_length * 1.5);
    T *tmp = new T[len];
    int count = 0;
    for(int i = m_front; i != m_rear; i = (i + 1) % m_length){
        tmp[count++] = m_data[i];
    }
    m_front = 0;
    m_rear = count;
    m_length = len;
    delete[] m_data;
    m_data = tmp;
}

void testCircularQueue(){
    CircularQueue<int> CIR(4);
    CIR.push(10);
    CIR.push(11);
    CIR.push(12);
    cout << CIR.size() << endl;
    CIR.push(17);
    cout << CIR.front() << endl;
    CIR.pop();
    CIR.push(17);
    CIR.push(9);
    CIR.push(1);
    cout << CIR.front() << endl;
    cout << CIR.size() << endl;
    CIR.pop();
    CIR.pop();
    CIR.pop();
    cout << CIR.front() << endl;
    cout << CIR.size() << endl;
    CIR.push(6);
}