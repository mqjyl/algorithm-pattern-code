//
// Created by mqjyl on 2020/7/29.
//
#include <algorithm>
#include "BackTracking.h"

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

void backtrack_n(std::vector<std::vector<std::string>> &result, std::vector<std::string> &solution, int n){
    if(n == 0){
        result.push_back(solution);
        return;
    }
}
// N皇后
std::vector<std::vector<std::string>> BackTracking::solveNQueens(int n){
    std::vector<std::vector<std::string>> result;

    return result;
}