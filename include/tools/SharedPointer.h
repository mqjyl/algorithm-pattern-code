//
// Created by mqjyl on 2020/10/9.
//

#ifndef ALGORITHM_PATTERN_CODE_SHAREDPOINTER_H
#define ALGORITHM_PATTERN_CODE_SHAREDPOINTER_H

#include <cstdio>
#include <cstdlib>
#include <cassert>

template<typename T>
class SharedPointer {
public:
    SharedPointer(T *ptr = nullptr) : _ptr(ptr){
        if(ptr != nullptr)
            _count = new int(1);
        else
            _count = new int(0);
    }
    // 拷贝构造函数
    SharedPointer(const SharedPointer& ptr){
        if(this != &ptr){
            this->_ptr = ptr._ptr;
            this->_count = ptr._count;
            (*this->_count) ++;
        }
    }
    // 拷贝赋值运算符
    SharedPointer& operator = (const SharedPointer &ptr){
        if(this->_ptr == ptr._ptr){
            return *this;
        }

        if(this->_ptr){
            (*this->_count) --;
            if((*this->_count) == 0){
                delete this->_count;
                delete this->_ptr;
            }
        }

        this->_ptr = ptr._ptr;
        this->_count = ptr._count;
        (*this->_count) ++;
        return *this;
    }

    ~SharedPointer(){
        (*this->_count) --;
        if((*this->_count) == 0){
            delete this->_count;
            delete this->_ptr;
        }
    }

public:
    T& operator*(){
        return *(this->_ptr);
    }

    T* operator->(){
        return this->_ptr;
    }

    int use_count(){
        return *(this->_count);
    }

    T* get(){
        return this->_ptr;
    }
    // 重载布尔值操作
    operator bool(){
        return this->_ptr == nullptr;
    }

private:
    T *_ptr;
    int *_count;
};

void testSharedPointer();

#endif //ALGORITHM_PATTERN_CODE_SHAREDPOINTER_H
