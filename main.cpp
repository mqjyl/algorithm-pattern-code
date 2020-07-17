#include <iostream>
#include <set>
#include "ListHandler.h"
#include "BinaryTree.h"
#include "SortTool.h"

void printList(ListNode *head){
    std::cout << '[';
    ListNode *ptr = head;
    while(ptr){
        std::cout << ptr->val << ',';
        ptr = ptr->next;
    }
    std::cout << ']' << std::endl;
}

void testList(){
    //int gArray[]  = {1,1,7,12,2,6,3,4,9,5,9,11,8,6,7,8,9,10,10,11};
    int gArray[] = {1,1};
    ListHandler *arrayHandler = new ListHandler();
    ListNode *gList = arrayHandler->createList(gArray, 2);
    printList(gList);
    //ListNode *resultList = arrayHandler->deleteDuplicates2(gList);
    //printList(resultList);

    //ListNode *resultList = arrayHandler->reverseList(gList);
    /*
    ListNode *resultList = arrayHandler->reverseListRecursion(gList);
    printList(resultList);
    printList(gList); // gList = [1] ?
    */
    //ListNode *resultList1 = arrayHandler->reverseBetween(gList, 1 ,2);
    //printList(resultList1);

    ListNode *resultList2 = arrayHandler->partition(gList, 0);
    printList(resultList2);
}

void testTree(){
    std::vector<int> gPreorder = {3,9,20,15,7};
    std::vector<int> gInorder = {9,3,15,20,7};
    BinaryTree *binaryTree = new BinaryTree();
    TreeNode *bTree = binaryTree->buildTree(gPreorder, gInorder);
    //std::vector<int> gResult = binaryTree->preorderTraversalRecursion(bTree);
    //std::vector<int> gResult = binaryTree->inorderTraversal(bTree);
    //std::vector<int> gResult = binaryTree->preorderTraversal(bTree);
    //std::vector<int> gResult = binaryTree->postorderTraversal(bTree);
    //std::vector<std::vector<int>> gResult = binaryTree->levelOrder(bTree);

    std::vector<std::vector<int>> gResult = binaryTree->zigzagLevelOrder(bTree);
    /*
    for(int i = 0;i < gResult.size();i ++){
        std::cout << gResult[i] << " ";
    }
    */
    for(int i = 0;i < gResult.size();i ++){
        for(int j = 0;j < gResult[i].size();j ++) {
            std::cout<< gResult[i][j] << " ";
        }
        std::cout << std::endl;
    }
    //std::cout << "Max Depth:" << binaryTree->maxDepthRecursion(bTree) << std::endl;
    std::cout << "Max Depth:" << binaryTree->maxDepthBFS(bTree) << std::endl;
    std::cout << "Max Depth:" << binaryTree->maxDepthDFS(bTree) << std::endl;

    std::vector<double> gResult1 = binaryTree->averageOfLevels(bTree);
    for(int i = 0;i < gResult.size();i ++){
        std::cout << gResult1[i] << " ";
    }

    std::cout << "Is Balanced Tree:" << binaryTree->isBalanced(bTree) << std::endl;
}

void testSort(){
    std::vector<int> gPreorder = {3,9,20,15,7,10,3,44,8,34,35,445,2,45,6,5,4,43,87,98,7,6,677,655,3456,543,4,7,55,444,34,9,2,0,2,11,42};
    SortTool *sortTool = new SortTool();
    //std::vector<int> gResult = sortTool->insertionSort(gPreorder);
    std::vector<int> gResult = sortTool->mergeSort(gPreorder);
    for(int i = 0;i < gResult.size();i ++){
        std::cout<< gResult[i] << " ";
    }
}


int main() {
    //testList();
    //testTree();
    testSort();
    return 0;
}