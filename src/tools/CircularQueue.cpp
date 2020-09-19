//
// Created by mqjyl on 2020/9/9.
//

#include "../../include/tools/CircularQueue.h"
#include <new>

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
        return m_data[front()];
    }
}

template <class T>
int CircularQueue<T>::size(){
    return (m_rear - m_front + m_length) % m_length;
}

template <class T>
bool CircularQueue<T>::resize(){
    T *tmp = new T[m_length * 1.5];
    int count = 0;
    for(int i = m_front; i < m_rear; i = (i + 1) % m_length){
        tmp[count++] = m_data[i];
    }
    m_front = 0;
    m_rear = count;
    m_length *= 1.5;
    delete[] m_data;
    m_data = tmp;
}

void testCircularQueue(){

}