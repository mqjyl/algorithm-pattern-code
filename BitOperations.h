//
// Created by mqjyl on 2020/7/15.
//

#ifndef ALGORITHM_PATTERN_BITOPERATIONS_H
#define ALGORITHM_PATTERN_BITOPERATIONS_H
#include<vector>

class BitOperations {
    //给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了两次。找出那个只出现了一次的元素。
    //算法应该具有线性时间复杂度，且不使用额外空间
    int singleNumber1(std::vector<int>& nums);

    //给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
    //算法应该具有线性时间复杂度，且不使用额外空间
    int singleNumber2(std::vector<int>& nums);
};


#endif //ALGORITHM_PATTERN_BITOPERATIONS_H
