//
// Created by mqjyl on 2020/9/19.
//

#ifndef ALGORITHM_PATTERN_CODE_UTILS_H
#define ALGORITHM_PATTERN_CODE_UTILS_H

#include <vector>

void Fisher_Yates_Shuffle(std::vector<int>& arr, std::vector<int>& res);

void Knuth_Durstenfeld_Shuffle(std::vector<int> &arr);

void Inside_Out_Shuffle(const std::vector<int>& arr, std::vector<int>& res);

void testDealCards();

#endif //ALGORITHM_PATTERN_CODE_UTILS_H
