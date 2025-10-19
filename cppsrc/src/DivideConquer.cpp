//
// Created by mqjyl on 2020/7/7.
//

#include <climits>
#include "../include/DivideConquer.h"

// 最大子序和
int maxSubArrayRecursion(std::vector<int>& nums, int start, int stop){
    if(stop < start){
        return INT_MIN;
    }
    if(stop == start){
        return nums[start];
    }
    int mid = (stop - start + 1) / 2 + start;
    int leftSum = maxSubArrayRecursion(nums, start, mid - 1);
    int rightSum = maxSubArrayRecursion(nums, mid + 1, stop);
    int midSum = nums[mid];
    int tmp = nums[mid];
    for(int i = mid - 1; i >= start; i--){
        tmp += nums[i];
        midSum = std::max(tmp, midSum);
    }
    tmp = midSum;
    for(int i = mid + 1; i <= stop; i++){
        tmp += nums[i];
        midSum = std::max(tmp, midSum);
    }
    return std::max(std::max(leftSum, rightSum), midSum);
}

int DivideConquer::maxSubArray(std::vector<int>& nums){
    return maxSubArrayRecursion(nums, 0, nums.size() - 1);
}