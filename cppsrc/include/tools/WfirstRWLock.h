//
// Created by mqjyl on 2020/9/12.
//

#ifndef ALGORITHM_PATTERN_CODE_WFIRSTRWLOCK_H
#define ALGORITHM_PATTERN_CODE_WFIRSTRWLOCK_H
#include <mutex>
#include <condition_variable>

class WfirstRWLock {
public:
    WfirstRWLock() = default;
    ~WfirstRWLock() = default;

    void lock_read();
    void lock_write();
    void release_read();
    void release_write();

private:
    volatile size_t m_count_read = 0;
    volatile size_t m_count_write = 0;
    volatile bool m_write_flag{ false };
    std::mutex m_mutex;
    std::condition_variable m_cond_write;
    std::condition_variable m_cond_read;
};

void testRWLock();

#endif //ALGORITHM_PATTERN_CODE_WFIRSTRWLOCK_H
