//
// Created by mqjyl on 2020/6/29.
//

#ifndef ALGORITHM_PATTERN_LISTHANDLER_H
#define ALGORITHM_PATTERN_LISTHANDLER_H

#include "Nodes.h"

class ListHandler {
public:
    ListNode* createList(int *pArray, int pCount);
    // remove-duplicates-from-sorted-list II
    ListNode* deleteDuplicates2(ListNode* head);
    // remove-duplicates-from-sorted-list
    ListNode* deleteDuplicates(ListNode* head);
    // Reverse a singly linked list.
    ListNode* reverseList(ListNode* head);
    // Reverse a singly linked list: recursive implementation
    ListNode* reverseListRecursion(ListNode* head);
    // 反转从位置 m 到 n 的链表。使用一趟扫描完成反转。
    ListNode* reverseBetween(ListNode* head, int m, int n);

    // 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
    // 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
    ListNode* swapPairs(ListNode* head);
    // 将两个升序链表合并为一个新的 升序 链表并返回。
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

    // 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
    // 应当保留两个分区中每个节点的初始相对位置。
    ListNode* partition(ListNode* head, int x);

    // 排序链表
    ListNode* sortList(ListNode* head);
    // 重排链表
    void reorderList(ListNode* head);
};


#endif //ALGORITHM_PATTERN_LISTHANDLER_H
