//
// Created by mqjyl on 2020/7/29.
//

#ifndef ALGORITHM_PATTERN_CODE_BACKTRACKING_H
#define ALGORITHM_PATTERN_CODE_BACKTRACKING_H
#include <vector>
#include <string>

class BackTracking {
public:
    // 给定一个 没有重复 数字的序列，返回其所有可能的全排列
    std::vector<std::vector<int>> permute(std::vector<int>& nums);
    // N皇后
    std::vector<std::vector<std::string>> solveNQueens(int n);
    // 37. 解数独
    void solveSudoku(std::vector<std::vector<char>>& board);
};


#endif //ALGORITHM_PATTERN_CODE_BACKTRACKING_H
