//
// Created by mqjyl on 2020/6/29.
//
#include <iostream>
#include <stack>
#include <utility>
#include <queue>
#include <algorithm>
#include <climits>
#include "../include/BinaryTree.h"

using namespace std;

// 从前序和中序构造二叉树
TreeNode* BinaryTree::buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    if(inorder.size() <= 0){
        return NULL;
    }
    int tmp = 0;
    for(int i = 0;i < inorder.size();i ++){
        if(preorder[0] == inorder[i]){
            tmp = i;
            break;
        }
    }
    TreeNode *treeNode = new TreeNode(preorder[0]);
    if(tmp > 0){
        std::vector<int> inorder_left(inorder.begin(), inorder.begin() + tmp); //左闭右开区间
        std::vector<int> preorder_left(preorder.begin() + 1, preorder.begin() + tmp + 1);
        treeNode->left = buildTree(preorder_left, inorder_left);
    }
    if(inorder.size() > tmp + 1){
        std::vector<int> inorder_right(inorder.begin() + tmp + 1, inorder.end());
        std::vector<int> preorder_right(preorder.begin() + tmp + 1, preorder.end());
        treeNode->right = buildTree(preorder_right, inorder_right);
    }
    return treeNode;
}
// 从后序和中序构造二叉树
TreeNode* BinaryTree::buildTreePost(std::vector<int>& inorder, std::vector<int>& postorder){
    if(inorder.size() == 0){
        return NULL;
    }
    if(inorder.size() == 1){
        return new TreeNode(inorder[0]);
    }
    int tmp = 0;
    for(int i = 0;i < inorder.size();i ++){
        if(postorder.back() == inorder[i]){
            tmp = i;
            break;
        }
    }
    TreeNode *treeNode = new TreeNode(inorder[tmp]);
    if(tmp > 0){
        // 左闭右开区间
        std::vector<int> inorder_left(inorder.begin(), inorder.begin() + tmp);
        std::vector<int> postorder_left(postorder.begin(), postorder.begin() + tmp);
        treeNode->left = buildTree(inorder_left, postorder_left);
    }
    if(inorder.size() > tmp + 1){
        std::vector<int> inorder_right(inorder.begin() + tmp + 1, inorder.end());
        std::vector<int> postorder_right(postorder.begin() + tmp, postorder.end() - 1);
        treeNode->right = buildTree(inorder_right, postorder_right);
    }
    return treeNode;
}


// 前序遍历：递归实现
std::vector<int> BinaryTree::preorderTraversalRecursion(TreeNode* root) {
    std::vector<int> result;
    if(!root)
        return result;
    result.push_back(root->val);
    if(root->left){
        std::vector<int> result_left = preorderTraversalRecursion(root->left);
        result.insert(result.end(), result_left.begin(), result_left.end());
    }
    if(root->right){
        std::vector<int> result_right = preorderTraversalRecursion(root->right);
        result.insert(result.end(), result_right.begin(), result_right.end());
    }
    return result;
}
// 中序遍历
std::vector<int> BinaryTree::inorderTraversal(TreeNode* root) {
    std::vector<int> inorder;
    std::stack<TreeNode *> istack;
    TreeNode *ptr = root;
    while(ptr){
        istack.push(ptr);
        ptr = ptr->left;
    }
    while(!istack.empty()){
        TreeNode *curr_ptr = istack.top();
        inorder.push_back(curr_ptr->val);
        istack.pop();
        ptr = curr_ptr->right;
        while(ptr){
            istack.push(ptr);
            ptr = ptr->left;
        }
    }
    return inorder;
}
// 前序遍历
std::vector<int> BinaryTree::preorderTraversal(TreeNode* root){
    std::vector<int> preorder;
    std::stack<TreeNode *> istack;
    TreeNode *ptr = root;
    while(ptr){
        preorder.push_back(ptr->val);
        istack.push(ptr);
        ptr = ptr->left;
    }
    while(!istack.empty()){
        TreeNode *curr_ptr = istack.top();
        istack.pop();
        ptr = curr_ptr->right;
        while(ptr){
            preorder.push_back(ptr->val);
            istack.push(ptr);
            ptr = ptr->left;
        }
    }
    return preorder;
}
// 后序遍历
std::vector<int> BinaryTree::postorderTraversal(TreeNode* root){
    /*
    std::vector<int> postorder;
    if(!root)
        return postorder;
    std::stack<std::pair<TreeNode *, int>> istack;
    std::pair<TreeNode*, int> tmpPair(root, 0);
    istack.push(tmpPair);
    while(!istack.empty()){
        tmpPair = istack.top();
        istack.pop();
        if(tmpPair.second == 0){
            istack.push(std::make_pair(tmpPair.first, 1));
            if(tmpPair.first->left){
                istack.push(std::make_pair(tmpPair.first->left, 0));
            }
        }else if(tmpPair.second == 1){
            istack.push(std::make_pair(tmpPair.first, 2));
            if(tmpPair.first->right){
                istack.push(std::make_pair(tmpPair.first->right, 0));
            }
        }else{
            postorder.push_back(tmpPair.first->val);
        }
    }
    */
    std::vector<int> postorder;
    if(!root)
        return postorder;
    std::stack<TreeNode *> istack;
    TreeNode *ptr = root;
    TreeNode *lastVisit = root;
    while(ptr || !istack.empty()){
        while(ptr){
            istack.push(ptr);
            ptr = ptr->left;
        }
        ptr = istack.top();
        if(ptr->right == NULL || ptr->right == lastVisit){
            postorder.push_back(ptr->val);
            istack.pop();
            lastVisit = ptr;
            ptr = NULL;
        }else{
            ptr = ptr->right;
        }
    }
    return postorder;
}
// BFS层次遍历
std::vector<std::vector<int>> BinaryTree::levelOrder(TreeNode* root){
    /*
    std::vector<std::vector<int>> result;
    if(!root)
        return result;
    int height = 0;
    std::queue<std::pair<TreeNode *,int>> iqueue;
    iqueue.push(std::make_pair(root, 0));
    std::pair<TreeNode*, int> tmpPair;
    std::vector<int> level_val;
    while(!iqueue.empty()) {
         tmpPair = iqueue.front();
         int tmp = tmpPair.second;
         if(tmp > height){
             result.push_back(level_val);
             level_val.clear();
             height = tmp;
         }
         level_val.push_back(tmpPair.first->val);
         if(tmpPair.first->left)
             iqueue.push(std::make_pair(tmpPair.first->left, tmp + 1));
         if(tmpPair.first->right)
            iqueue.push(std::make_pair(tmpPair.first->right, tmp + 1));
         iqueue.pop();
    }
    result.push_back(level_val);
    */
    std::vector<std::vector<int>> result;
    if(!root)
        return result;
    int len = 1;
    std::queue<TreeNode *> iqueue;
    iqueue.push(root);
    TreeNode* ptr = root;
    std::vector<int> level_val;
    while(!iqueue.empty()){
        int tmp_len = 0;
        while(len > 0){
            ptr = iqueue.front();
            level_val.push_back(ptr->val);
            if(ptr->left){
                iqueue.push(ptr->left);
                tmp_len++;
            }
            if(ptr->right){
                iqueue.push(ptr->right);
                tmp_len++;
            }
            iqueue.pop();
            len--;
        }
        len = tmp_len;
        result.push_back(level_val);
        level_val.clear();
    }
    return result;
}


// 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
std::vector<std::vector<int>> BinaryTree::levelOrderBottom(TreeNode* root){
    std::vector<std::vector<int>> result;
    if(!root)
        return result;
    int len = 1;
    std::queue<TreeNode *> iqueue;
    std::stack<std::vector<int>> istack;
    iqueue.push(root);
    TreeNode* ptr = root;
    std::vector<int> level_val;
    while(!iqueue.empty()){
        int tmp_len = 0;
        while(len > 0){
            ptr = iqueue.front();
            level_val.push_back(ptr->val);
            if(ptr->left){
                iqueue.push(ptr->left);
                tmp_len++;
            }
            if(ptr->right){
                iqueue.push(ptr->right);
                tmp_len++;
            }
            iqueue.pop();
            len--;
        }
        len = tmp_len;
        istack.push(level_val);
        level_val.clear();
    }
    while(!istack.empty()){
        result.push_back(istack.top());
        istack.pop();
    }
    return result;
}
// 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
std::vector<std::vector<int>> BinaryTree::zigzagLevelOrder(TreeNode* root){
    /*
    std::vector<std::vector<int>> result;
    if(!root)
        return result;
    int len = 1;
    bool flag = true;
    std::queue<TreeNode *> iqueue;
    iqueue.push(root);
    TreeNode* ptr = root;
    std::vector<int> level_val;
    while(!iqueue.empty()){
        int tmp_len = 0;
        while(len > 0){
            ptr = iqueue.front();
            level_val.push_back(ptr->val);
            if(ptr->left){
                iqueue.push(ptr->left);
                tmp_len++;
            }
            if(ptr->right){
                iqueue.push(ptr->right);
                tmp_len++;
            }
            iqueue.pop();
            len--;
        }
        len = tmp_len;
        if(!flag)
            std::reverse(level_val.begin(), level_val.end());
        flag = !flag;
        result.push_back(level_val);
        level_val.clear();
    }
    */
    std::vector<std::vector<int>> result;
    if(!root)
        return result;
    int len = 1;
    bool flag = true;
    std::deque<TreeNode *> ideque;
    ideque.push_back(root);
    TreeNode* ptr = root;
    std::vector<int> level_val;
    while(!ideque.empty()){
        int tmp_len = 0;
        while(len > 0){
            if(flag){
                ptr = ideque.back();
                ideque.pop_back();
                if(ptr->left){
                    ideque.push_front(ptr->left);
                    tmp_len++;
                }
                if(ptr->right) {
                    ideque.push_front(ptr->right);
                    tmp_len++;
                }
            }else{
                ptr = ideque.front();
                ideque.pop_front();
                if(ptr->right) {
                    ideque.push_back(ptr->right);
                    tmp_len++;
                }
                if(ptr->left){
                    ideque.push_back(ptr->left);
                    tmp_len++;
                }
            }
            level_val.push_back(ptr->val);
            len--;
        }
        len = tmp_len;
        flag = !flag;
        result.push_back(level_val);
        level_val.clear();
    }
    return result;
}
// 给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。
std::vector<double> BinaryTree::averageOfLevels(TreeNode* root){
    std::vector<double> result;
    if(!root)
        return result;
    int len = 1;
    std::queue<TreeNode *> iqueue;
    iqueue.push(root);
    TreeNode* ptr = root;
    double level_sum = root->val;
    while(!iqueue.empty()){
        result.push_back(level_sum / len);
        level_sum = 0;
        int tmp_len = 0;
        while(len > 0){
            ptr = iqueue.front();
            if(ptr->left){
                iqueue.push(ptr->left);
                level_sum += ptr->left->val;
                tmp_len++;
            }
            if(ptr->right){
                iqueue.push(ptr->right);
                level_sum += ptr->right->val;
                tmp_len++;
            }
            iqueue.pop();
            len--;
        }
        len = tmp_len;
    }
    return result;
}


// 给定一个二叉树，找出其最大深度。
int BinaryTree::maxDepthRecursion(TreeNode* root){
    if(!root)
        return 0;
    return std::max(maxDepthRecursion(root->left), maxDepthRecursion(root->right)) + 1;
}
int BinaryTree::maxDepthDFS(TreeNode* root){
    if(!root)
        return 0;
    int height = 0;
    std::stack<std::pair<TreeNode *, int>> istack;
    TreeNode *ptr = root;
    std::pair<TreeNode *, int> tmpPair;
    int tmpHeight = 1;
    while(ptr){
        istack.push(std::make_pair(ptr, tmpHeight));
        ptr = ptr->left;
        tmpHeight++;
    }
    while(!istack.empty()){
        tmpPair = istack.top();
        if(!tmpPair.first->left && !tmpPair.first->right){
            height = height < tmpPair.second ? tmpPair.second : height;
        }
        tmpHeight = istack.top().second + 1;
        istack.pop();
        ptr = tmpPair.first->right;
        while(ptr){
            istack.push(std::make_pair(ptr, tmpHeight));
            ptr = ptr->left;
            tmpHeight++;
        }
    }
    return height;
}
int BinaryTree::maxDepthBFS(TreeNode* root){
    int height = 0;
    if(!root)
        return 0;
    int len = 1;
    std::queue<TreeNode *> iqueue;
    iqueue.push(root);
    TreeNode* ptr = root;
    std::vector<int> level_val;
    while(!iqueue.empty()){
        int tmp_len = 0;
        while(len > 0){
            ptr = iqueue.front();
            level_val.push_back(ptr->val);
            if(ptr->left){
                iqueue.push(ptr->left);
                tmp_len++;
            }
            if(ptr->right){
                iqueue.push(ptr->right);
                tmp_len++;
            }
            iqueue.pop();
            len--;
        }
        len = tmp_len;
        height++;
        level_val.clear();
    }
    return height;
}

// 给定一个二叉树，判断它是否是高度平衡的二叉树。
//bool BinaryTree::isBalanced(TreeNode* root){
//    if(root && !root->left && !root->right)
//        return true;
//    stack<TreeNode *> istack;
//    TreeNode *ptr = root;
//    long long last_val = (long long)INT_MIN - 1;
//    while(ptr || !istack.empty()){
//        while(ptr) {
//            istack.push(ptr);
//            ptr = ptr->left;
//        }
//        TreeNode *curr_ptr = istack.top();
//        if(curr_ptr->val <= last_val)
//            return false;
//        last_val = curr_ptr->val;
//        istack.pop();
//        ptr = curr_ptr->right;
//    }
//    return true;
//}

bool helper(TreeNode* root, long long lower, long long upper) {
    if(root == NULL)
        return true;
    if(root->val <= lower || root->val >= upper)
        return false;
    return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
}

bool BinaryTree::isBalanced(TreeNode* root){
    return helper(root, LONG_MIN, LONG_MAX);
}

// 124. 二叉树中的最大路径和
int helper(TreeNode *node, int &sum){
    if(!node){
        sum = max(sum, 0);
        return 0;
    }
    int lsum = 0, rsum = 0;
    if(node->left){
        lsum = max(0, helper(node->left, sum));  // 左子树的贡献
    }
    if(node->right){
        rsum = max(0, helper(node->right, sum)); // 右子树的贡献
    }
    sum = max(sum, node->val + lsum + rsum); // 当前子树的 maxSum 挑战最大值
    return node->val + max(lsum, rsum);      // 向父节点提供的最大和，要包括自己
}
int BinaryTree::maxPathSum(TreeNode* root){
    int maxSum = INT_MIN;
    helper(root, maxSum);
    return maxSum;
}

// 112. 路径总和
bool BinaryTree::hasPathSum(TreeNode* root, int sum){
    if(!root)
        return false;
    if(root && !root->left && !root->right)
        return sum == root->val;
    return hasPathSum(root->left, sum - root->val)
           || hasPathSum(root->right, sum - root->val);
}

// 113. 路径总和 II
void getPaths(TreeNode *root, vector<vector<int>> &result, vector<int> &path){
    
}

std::vector<std::vector<int>> pathSum(TreeNode* root, int sum){
    vector<vector<int>> result;
    vector<int> path;

    return result;
}

using namespace std;
// 逆时针打印完全二叉树的边界节点
vector<int> BinaryTree::getSeq(int n, vector<int>& tree){
    vector<int> ans;
    if(n == 1){
        ans.push_back(tree[0]);
        return ans;
    }
    // 左边界
    int i = 1;
    while(i - 1 < n){
        ans.push_back(tree[i - 1]);
        i *= 2;
    }
    ans.pop_back();
    // 叶节点
    int j = i / 2 - 2;
    i = i / 2 / 2 - 1;
    for(int k = i; k >= 0 && k < n && k <= j; ++k){
        if(k * 2 + 1 < n)
            ans.push_back(tree[k * 2 + 1]);
        if(k * 2 + 2 < n)
            ans.push_back(tree[k * 2 + 2]);
        if(k * 2 + 1 >= n)
            ans.push_back(tree[k]);
    }
    // 右边界
    while(j > 0){
        ans.push_back(tree[j]);
        j = (j - 2) / 2;
    }
    return ans;
}