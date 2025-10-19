//
// Created by mqjyl on 2020/7/29.
//
#include <algorithm>
#include "../include/BackTracking.h"

void backtrack(std::vector<std::vector<int>> &result, std::vector<int> &track, std::vector<int>& nums){
    if(track.size() == nums.size()){
        result.push_back(track);
        return;
    }
    for(int i : nums){
        if(std::find(track.begin(), track.end(), i) != track.end())
            continue;
        track.push_back(i);
        backtrack(result, track, nums);
        track.pop_back();
    }
}

// 给定一个 没有重复 数字的序列，返回其所有可能的全排列
std::vector<std::vector<int>> BackTracking::permute(std::vector<int>& nums){
    std::vector<std::vector<int>> result;
    std::vector<int> track;
    backtrack(result, track, nums);
    return result;
}

bool isValid(std::vector<int> &solution, int col){
    int len = solution.size();
    for(int i = 0; i < len; ++i){
        if(std::abs(len - i) == std::abs(col - solution[i]))
            return false;
    }
    return true;
}

void backtrack_n(std::vector<std::vector<std::string>> &result, std::vector<int> &solution, std::vector<std::string> &cases, int n){
    if(n == solution.size()){
        std::vector<std::string> temp;
        for(int i : solution){
            temp.push_back(cases[i]);
        }
        result.push_back(temp);
        return;
    }
    for(int i = 0; i < n; ++i){
        if(std::find(solution.begin(), solution.end(), i) != solution.end())
            continue;
        if(isValid(solution, i)){
            solution.push_back(i);
            backtrack_n(result, solution, cases, n);
            solution.pop_back();
        }
    }
}
// N皇后
std::vector<std::vector<std::string>> BackTracking::solveNQueens(int n){
    std::vector<std::string> cases;
    for(int i = 0; i < n; ++i){
        std::string str = std::string(i, '.') + 'Q' + std::string(n - i - 1, '.');
        cases.push_back(str);
    }
    std::vector<std::vector<std::string>> result;
    std::vector<int> track;
    backtrack_n(result, track, cases, n);
    return result;
}

// 37. 解数独
void BackTracking::solveSudoku(std::vector<std::vector<char>>& board){

}