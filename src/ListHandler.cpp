//
// Created by mqjyl on 2020/6/29.
//
#include <iostream>
#include <stack>
#include <set>
#include <map>
#include "../ListHandler.h"

ListNode* ListHandler::createList(int *pArray, int pCount){
    if(pCount <= 0)
        return NULL;
    ListNode *head = new ListNode(pArray[0]);
    ListNode *ptr = head;
    for(int i = 1; i < pCount;i++){
        ptr->next = new ListNode(pArray[i]);
        ptr = ptr->next;
    }
    return head;
}
// remove-duplicates-from-sorted-list
ListNode* ListHandler::deleteDuplicates(ListNode* head) {
    ListNode *ptr = head;
    //注意访问x.val和x.next得保证x != NULL.
    while(ptr && ptr->next){
        if(ptr->next->val == ptr->val){
            ptr->next = ptr->next->next;
        }else{
            ptr = ptr->next;
        }
    }
    return head;
}
// remove-duplicates-from-sorted-list II
ListNode* ListHandler::deleteDuplicates2(ListNode* head) {
    if(!head)
        return head;
    ListNode *prev_ptr = new ListNode(head->val + 1);
    prev_ptr->next = head;
    head = prev_ptr;

    ListNode *ptr = head;
    while(ptr && ptr->next){
        if(ptr->next->val == ptr->val){
            while(ptr->next && ptr->val == ptr->next->val){
                ptr = ptr->next;
            }
            prev_ptr->next = ptr->next;
        }
        ptr = ptr->next;
        if(prev_ptr->next && prev_ptr->next->next == ptr){
            prev_ptr = prev_ptr->next;
        }
    }

    prev_ptr = head;
    head = head->next;
    delete prev_ptr;
    return head;
}
// Reverse a singly linked list.
ListNode* ListHandler::reverseList(ListNode* head) {
    if(!(head && head->next))
        return head;
    ListNode *tmpHead = head->next;
    ListNode *newHead = head;
    newHead->next = NULL;
    while(tmpHead){
        ListNode *ptr = tmpHead;
        tmpHead = tmpHead->next;
        ptr->next = newHead;
        newHead = ptr;
    }
    head = newHead;
    return head;
}
// Reverse a singly linked list: recursive implementation
ListNode* ListHandler::reverseListRecursion(ListNode* head){      // ??? 会出现断链
    if(!(head && head->next))
        return head;
    ListNode *ptr = head;
    ListNode *nextPtr = head->next;
    ListNode *subHead = reverseList(nextPtr);
    ptr->next = NULL;
    nextPtr->next = ptr;
    return subHead;
}
// 反转从位置 m 到 n 的链表。使用一趟扫描完成反转。
ListNode* ListHandler::reverseBetween(ListNode* head, int m, int n){
    if(!head->next)
        return head;
    ListNode *ptr = head;
    if(m == 1){
        ListNode *pre_ptr= head->next;
        ptr->next = NULL;
        while(pre_ptr && n > 1){
            ListNode *tmp_ptr = pre_ptr;
            pre_ptr = pre_ptr->next;
            tmp_ptr->next = ptr;
            ptr = tmp_ptr;
            n--;
        }
        head->next = pre_ptr;
        return ptr;
    }
    while(m > 2){// m 的前一个要记录在pre_tail中
        ptr = ptr->next;
        m--; n--;
    }
    // 开始反转
    ListNode *pre_tail = ptr;
    ListNode *in_tail = ptr->next;
    ListNode *pre_ptr = ptr->next;
    ptr = ptr->next->next;
    while(n > 2 && ptr){
        ListNode *tmp_ptr = ptr;
        ptr = ptr->next;
        tmp_ptr->next = pre_ptr;
        pre_ptr = tmp_ptr;
        n--;
    }
    pre_tail->next = pre_ptr;
    in_tail->next = ptr;
    return head;
}
//给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
//你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
ListNode* swapOnePair(ListNode* pre_head){
    if(!(pre_head->next && pre_head->next->next))
        return pre_head;
    ListNode *tmp = pre_head;
    ListNode *ptr = pre_head->next;
    tmp->next = ptr->next;
    ptr->next = ptr->next->next;
    tmp = tmp->next;
    tmp->next = ptr;
    tmp = tmp->next;
    swapOnePair(tmp);
    return pre_head->next;
}
ListNode* ListHandler::swapPairs(ListNode* head){
    /*
    if(!(head && head->next))
        return head;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *ptr = dummy;
    ListNode *tmp = ptr;
    while(ptr->next){
        ptr = ptr->next;
        if(ptr->next){
            tmp->next = ptr->next;
            ptr->next = ptr->next->next;
            tmp = tmp->next;
            tmp->next = ptr;
            tmp = tmp->next;
        }
    }
    return dummy->next;
    */
    if(!(head && head->next))
        return head;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    return swapOnePair(dummy);
}
// 将两个升序链表合并为一个新的 升序 链表并返回。
ListNode* ListHandler::mergeTwoLists(ListNode* l1, ListNode* l2){
    ListNode *head = new ListNode(0);
    ListNode *ptr = head;
    while(l1 && l2){
        if(l1->val > l2->val){
            ptr->next = l2;
            l2 = l2->next;
        }else{
            ptr->next = l1;
            l1 = l1->next;
        }
        ptr = ptr->next;
    }
    if(l1){
        ptr->next = l1;
    }
    if(l2){
        ptr->next = l2;
    }
    ptr = head;
    head = head->next;
    delete ptr;
    return head;
}
// 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
// 应当保留两个分区中每个节点的初始相对位置。
ListNode* ListHandler::partition(ListNode* head, int x){
    std::cout << "come in partition" << std::endl;
    if(!(head && head->next)){
        return head;
    }
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    bool flag = true;
    ListNode *tmp_head_small, *tmp_ptr_small;
    ListNode *ptr = dummy;
    while(ptr->next){
        std::cout << " d" << ptr->next->val << ',';
        if(ptr->next->val < x){
            if(flag){
                tmp_head_small = tmp_ptr_small = ptr->next;
                flag = !flag;
            }else{
                tmp_ptr_small->next = ptr->next;
                tmp_ptr_small = tmp_ptr_small->next;
            }
            ptr->next = ptr->next->next;
        }else{
            ptr = ptr->next;
        }
    }
    if(tmp_head_small && tmp_ptr_small){// tmp_ptr_small 也必须判断，否则编译过不去，编译器认为会有空指针异常
        tmp_ptr_small->next = dummy->next;
        dummy->next = tmp_head_small;
    }
    return dummy->next;
}

// 排序链表
ListNode* ListHandler::sortList(ListNode* head){
    if(!head || !head->next)
        return head;
    // 拆分
    ListNode *quickptr=head->next, *slowptr=head;
    // 若quickptr=head，当原始链表长度为2时，会进入无线递归。
    while(quickptr && quickptr->next){
        quickptr = quickptr->next->next;
        slowptr = slowptr->next;
    }
    ListNode *tmpHead = slowptr->next;
    slowptr->next = NULL;
    ListNode *head1 = sortList(head);
    ListNode *head2 = sortList(tmpHead);
    // 合并
    return this->mergeTwoLists(head1, head2);
}
// 重排链表
/*
void ListHandler::reorderList(ListNode* head){
    if(!head || !head->next)
        return;
    ListNode *quickptr=head->next, *slowptr=head;
    std::stack<ListNode *> istack;
    while(quickptr && quickptr->next){
        quickptr = quickptr->next->next;
        istack.push(slowptr);
        slowptr = slowptr->next;
    }
    ListNode *tmpHead = slowptr->next;
    ListNode *tmpPtr = slowptr;
    ListNode *newHead = tmpPtr;
    if(!quickptr){ // 奇数个
        tmpPtr->next = NULL;
    }else{
        tmpHead = tmpHead->next;
        tmpPtr->next->next = NULL;
    }
    while(!istack.empty()){
        tmpPtr = istack.top();
        istack.pop();
        ListNode *tmp = tmpHead->next;
        tmpHead->next = newHead;
        tmpPtr->next = tmpHead;
        tmpHead = tmp;
        newHead = tmpPtr;
    }
    head = newHead;
}
 */
void ListHandler::reorderList(ListNode* head){
    if(!head || !head->next)
        return;
    ListNode *quickptr=head->next, *slowptr=head;
    while(quickptr && quickptr->next){
        quickptr = quickptr->next->next;
        slowptr = slowptr->next;
    }
    ListNode *rightHead = slowptr->next;
    slowptr->next = NULL;
    rightHead = this->reverseList(rightHead);
    // 合并
    ListNode *leftHead = head;
    ListNode *tmpPtr = leftHead;
    while(leftHead){
        tmpPtr = leftHead;
        leftHead = leftHead->next;
        tmpPtr->next = rightHead;
        if(rightHead){
            rightHead = rightHead->next;
            tmpPtr->next->next = leftHead;
        } // 奇数个的情况
    }
}
// 判断链表是否有环
/*
bool ListHandler::hasCycle(ListNode *head){
    if(!head || !head->next)
        return false;
    ListNode *quickptr=head->next, *slowptr=head;
    while(quickptr && quickptr->next){
        if(quickptr == slowptr){
            return true;
        }
        quickptr = quickptr->next->next;
        slowptr = slowptr->next;
    }
    return false;
}
*/
bool ListHandler::hasCycle(ListNode *head){
    if(!head || !head->next)
        return false;
    std::set<ListNode *> iset;
    ListNode *ptr = head;
    while(ptr){
        if(iset.count(ptr) > 0){
            return true;
        }
        iset.insert(ptr);
        ptr = ptr->next;
    }
    return false;
}
// 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
ListNode *ListHandler::detectCycle(ListNode *head){
    if(!head || !head->next)
        return NULL;
    ListNode *quickptr=head->next, *slowptr=head;
    while(quickptr && quickptr->next){
        if(quickptr == slowptr){
            quickptr = head;
            slowptr = slowptr->next;
            break;
        }
        quickptr = quickptr->next->next;
        slowptr = slowptr->next;
    }
    if(quickptr == head){
        while(quickptr != slowptr){
            quickptr = quickptr->next;
            slowptr = slowptr->next;
        }
        return quickptr;
    }
    return NULL;
}
// 判断一个链表是否为回文链表。
bool ListHandler::isPalindrome(ListNode* head){
    if(!head || !head->next)
        return true;
    ListNode *quickptr=head->next, *slowptr=head;
    while(quickptr && quickptr->next){
        quickptr = quickptr->next->next;
        slowptr = slowptr->next;
    }
    ListNode *rightHead = slowptr->next;
    slowptr->next = NULL;
    rightHead = this->reverseList(rightHead);
    // 合并
    ListNode *leftHead = head;
    while(leftHead && rightHead){
        if(leftHead->val != rightHead->val){
            return false;
        }
        leftHead = leftHead->next;
        rightHead = rightHead->next;
    }
    return true;
}
// 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
// 要求返回这个链表的 深拷贝。
/*
Node* ListHandler::copyRandomList(Node* head){
    if(!head)
        return NULL;
    std::map<Node*, Node*> imap;
    Node *ptr = head;
    Node *newHead = new Node(0);
    Node *newptr = newHead;
    while(ptr){
        newptr->next = new Node(ptr->val);
        newptr = newptr->next;
        imap.insert(std::make_pair(ptr, newptr));
        ptr = ptr->next;
    }
    ptr = head;
    newptr = newHead->next;
    while(ptr){
        if(ptr->random)
            newptr->random = imap.find(ptr->random)->second;
        ptr = ptr->next;
        newptr = newptr->next;
    }
    return newHead->next;
}
 */
Node* ListHandler::copyRandomList(Node* head){
    if(!head)
        return NULL;
    Node *ptr = head;
    Node *tmpptr = head;
    while(ptr){
        tmpptr = ptr->next;
        ptr->next = new Node(ptr->val);
        ptr->next->next = tmpptr;
        ptr = tmpptr;
    }
    ptr = head;
    tmpptr = head->next;
    while(tmpptr){
        if(ptr->random)
            tmpptr->random = ptr->random->next;
        if(tmpptr->next){
            tmpptr = tmpptr->next->next;
            ptr = ptr->next->next;
        }else{
            break;
        }
    }
    // 拆分
    Node *newHead = head->next;
    ptr = head;
    tmpptr = head->next;
    while(tmpptr && tmpptr->next){
        ptr->next = tmpptr->next;
        tmpptr->next = tmpptr->next->next;
        ptr = ptr->next;
        tmpptr = tmpptr->next;
    }
    ptr->next = NULL;
    return newHead;
}

// 删除链表的倒数第N个节点
ListNode* ListHandler::removeNthFromEnd(ListNode* head, int n){
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *prev = dummy, *post = dummy;
    while(n >= 0){
        prev = prev->next;
        n--;
    }
    while(prev){
        prev = prev->next;
        post = post->next;
    }
    post->next = post->next->next;
    return dummy->next;
}

// 25. K 个一组翻转链表
ListNode* ListHandler::reverseKGroup(ListNode* head, int k) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *p = dummy;
    ListNode *q = dummy;
    while(p){
        int t = k;
        while(p && t > 0){
            p = p->next;
            --t;
        }
        if(t == 0){
            // 反转
            ListNode *temp = p ? p->next : p;
            ListNode *tmpHead = q->next->next;
            ListNode *newHead = q->next;
            p = newHead;
            while(tmpHead != temp){
                ListNode *ptr = tmpHead;
                tmpHead = tmpHead->next;
                ptr->next = newHead;
                newHead = ptr;
            }
            q->next = newHead;
            p->next = temp;
            q = p;
        }else{
            break;
        }
    }
    return dummy->next;
}