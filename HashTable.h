//
// Created by mqjyl on 2020/7/16.
//

#ifndef ALGORITHM_PATTERN_HASHTABLE_H
#define ALGORITHM_PATTERN_HASHTABLE_H
#include <vector>
#include <unordered_map>

class HashTable {
public:
    // 两数之和
    std::vector<int> twoSum(std::vector<int>& nums, int target);
    // 三数之和
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums);
};

struct DLinkedList{
    int key,val;
    DLinkedList *prev;
    DLinkedList *next;
    DLinkedList() : key(0), val(0), prev(nullptr), next(nullptr){}
    DLinkedList(int _key, int _val) : key(_key), val(_val), prev(nullptr), next(nullptr){}
};

class LRUCache {
public:
    LRUCache(int capacity) : m_capacity(capacity) , m_size(0){
        head = new DLinkedList();
        tail = new DLinkedList();
        head->next = tail;
        tail->prev = head;
    }
    int get(int key) {
        if(!m_cache.count(key)){
            return -1;
        }
        DLinkedList *node = m_cache[key];
        moveToHead(node);
        return node->val;
    }
    void put(int key, int value) {
        if(m_cache.count(key)){
            DLinkedList *node = m_cache[key];
            node->val = value;
            moveToHead(node);
        }else{
            DLinkedList *node = new DLinkedList(key, value);
            m_cache[key] = node;
            addToHead(node);
            ++m_size;
            if(m_size > m_capacity){
                DLinkedList *removeNode = removeTail();
                m_cache.erase(removeNode->key);
                delete removeNode;
                --m_size;
            }
        }
    }
    // 维护双向链表
    void moveToHead(DLinkedList *_node){
        removeNode(_node);
        addToHead(_node);
    }
    DLinkedList *removeTail(){
        DLinkedList *node = tail->prev;
        removeNode(node);
        return node;
    }

    void removeNode(DLinkedList *node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void addToHead(DLinkedList *node){
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }

private:
    int m_capacity;
    int m_size;
    DLinkedList *head;
    DLinkedList *tail;
    std::unordered_map<int, DLinkedList*> m_cache;
};


#endif //ALGORITHM_PATTERN_HASHTABLE_H
