//
// Created by mqjyl on 2020/6/29.
//

#ifndef ALGORITHM_PATTERN_NODES_H
#define ALGORITHM_PATTERN_NODES_H

#include <stdio.h>
#include <vector>

// Definition for a list node.
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(NULL){}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

// Definition for a list node with a random pointer.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
     val = _val;
     next = NULL;
     random = NULL;
    }
};

// Definition for a Node.
class GraphNode {
public:
    int val;
    std::vector<GraphNode*> neighbors;

    GraphNode() {
        val = 0;
        neighbors = std::vector<GraphNode*>();
    }

    GraphNode(int _val) {
        val = _val;
        neighbors = std::vector<GraphNode*>();
    }

    GraphNode(int _val, std::vector<GraphNode*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

#endif //ALGORITHM_PATTERN_NODES_H
