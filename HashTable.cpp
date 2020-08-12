//
// Created by mqjyl on 2020/7/16.
//
#include<unordered_map>
#include <algorithm>
#include "HashTable.h"
using namespace std;

//std::vector<int> HashTable::twoSum(std::vector<int>& nums, int target){
//    std::unordered_map<int, int> ihash;
//    for(int i = 0;i < nums.size(); ++i){
//        ihash[nums[i]] = i;
//    }
//    for(int i = 0;i < nums.size(); ++i){
//        int tar = target - nums[i];
//        if(ihash.count(tar) && ihash[tar] != i)
//        {
//            return std::vector<int>{i, ihash[tar]};
//        }
//    }
//    return std::vector<int>{};
//}

std::vector<int> HashTable::twoSum(std::vector<int>& nums, int target){
    std::unordered_map<int, int> ihash;
    for(int i = 0;i < nums.size(); ++i){
        int tar = target - nums[i];
        if(ihash.count(tar) && ihash[tar] != i)
        {
            return std::vector<int>{ihash[tar], i}; //反过来
        }
        ihash[nums[i]] = i;
    }
    return std::vector<int>{};
}
// 三数之和
std::vector<std::vector<int>> HashTable::threeSum(std::vector<int>& nums)
{
    sort(nums.begin(), nums.end()); // 为了去重
    int len = nums.size();
    vector<vector<int>> result;
    for(int i = 0; i < len; ++i){
        std::unordered_map<int, int> ihash;
        for(int j = i + 1;j < len; ++j){
            int tar = 0 - nums[i] - nums[j];
            if(ihash.count(tar) && ihash[tar] != j)
            {
                vector<int> temp{nums[i], nums[ihash[tar]], nums[j]};
                result.push_back(temp); //反过来
                int t = nums[j];
                while(++j < len && t == nums[j]);  // 去重
                --j;
            }
            ihash[nums[j]] = j;
        }
        int t = nums[i];
        while(++i < len && t == nums[i]); // 去重
        --i;
    }
    return result;
}