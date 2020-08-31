//
// Created by mqjyl on 2020/6/29.
//

#ifndef ALGORITHM_PATTERN_BINARYTREE_H
#define ALGORITHM_PATTERN_BINARYTREE_H
#include <vector>
#include "Nodes.h"
class BinaryTree {
public:
    // 从前序和中序构造二叉树
    TreeNode *buildTree(std::vector<int>& preorder, std::vector<int>& inorder);
    // 从后序和中序构造二叉树
    TreeNode* buildTreePost(std::vector<int>& inorder, std::vector<int>& postorder);


    // 前序遍历：递归实现
    std::vector<int> preorderTraversalRecursion(TreeNode* root);
    // 中序遍历
    std::vector<int> inorderTraversal(TreeNode* root);
    // 前序遍历
    std::vector<int> preorderTraversal(TreeNode* root);
    // 后序遍历
    std::vector<int> postorderTraversal(TreeNode* root);
    // BFS层次遍历
    std::vector<std::vector<int>> levelOrder(TreeNode* root);


    // 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root);
    // 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root);
    // 给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。
    std::vector<double> averageOfLevels(TreeNode* root);


    // 给定一个二叉树，找出其最大深度。
    int maxDepthRecursion(TreeNode* root);
    int maxDepthDFS(TreeNode* root);
    int maxDepthBFS(TreeNode* root);

    // 给定一个二叉树，判断它是否是高度平衡的二叉树。
    bool isBalanced(TreeNode* root);

    // 124. 二叉树中的最大路径和
    int maxPathSum(TreeNode* root);

    // 112. 路径总和
    bool hasPathSum(TreeNode* root, int sum);

    // 113. 路径总和 II
    std::vector<std::vector<int>> pathSum(TreeNode* root, int sum);

    // 逆时针打印完全二叉树的边界节点
    std::vector<int> getSeq(int n, std::vector<int>& tree);
};


#endif //ALGORITHM_PATTERN_BINARYTREE_H
