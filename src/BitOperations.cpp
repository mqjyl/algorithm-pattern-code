//
// Created by mqjyl on 2020/7/15.
//

#include<set>
#include "../BitOperations.h"

int BitOperations::singleNumber1(std::vector<int>& nums) {
    int result = 0;
    for(int num : nums){
        result = result ^ num;
    }
    return result;
}

int BitOperations::singleNumber2(std::vector<int>& nums) {
    /*
    long sum = 0;
    long tmpSum = 0;
    std::set<int> iset;
    for(int num : nums){
        sum += num;
        iset.insert(num);
    }
    for(std::set<int>::iterator iter = iset.begin(); iter != iset.end();iter++){
        tmpSum += *iter;
    }
    return (tmpSum * 3 - sum) / 2;
    */
}