//
// Created by mqjyl on 2020/9/10.
//

#ifndef ALGORITHM_PATTERN_CODE_BLOCKQUEUE_H
#define ALGORITHM_PATTERN_CODE_BLOCKQUEUE_H

#include <mutex>
#include <condition_variable>
#include <deque>
#include <chrono>

template<class T>
class BlockQueue {
public:
    using size_type = typename std::deque<T>::size_type;

public:
    BlockQueue(const int cap = -1) : m_maxCapacity(cap){}
    ~BlockQueue(){}

    BlockQueue(const BlockQueue &) = delete;
    BlockQueue &operator = (const BlockQueue &) = delete;

public:
    void put(const T t);
    T take();

    bool empty() const{
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_queue.empty();
    }

    bool full() const{
        if(-1 == m_maxCapacity)
            return false;
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_queue.size() >= m_maxCapacity;
    }

    size_type size(){
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_queue.size();
    }

public:
    bool offer(const T t);
    bool poll(T& t);
    bool offer(const T t, std::chrono::milliseconds& time);
    bool poll(T& t, std::chrono::milliseconds& time);

private:
    std::deque<T> m_queue;
    const int m_maxCapacity;
    mutable std::mutex m_mutex;
    std::condition_variable m_cond_empty;
    std::condition_variable m_cond_full;
};


void testBlockQueue();


#endif //ALGORITHM_PATTERN_CODE_BLOCKQUEUE_H
