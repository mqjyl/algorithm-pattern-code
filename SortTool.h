//
// Created by mqjyl on 2020/6/30.
//

#ifndef ALGORITHM_PATTERN_SORTTOOL_H
#define ALGORITHM_PATTERN_SORTTOOL_H

#include <vector>

class SortTool {
public:
    // 冒泡排序
    std::vector<int> bubbleSort(std::vector<int>& nums);
    // 快速排序
    std::vector<int> quickSort(std::vector<int>& nums);
    // 插入排序
    std::vector<int> insertionSort(std::vector<int>& nums);
    // 希尔排序
    std::vector<int> shellSort(std::vector<int>& nums);
    // 归并排序
    std::vector<int> mergeSort(std::vector<int>& nums);
};


#endif //ALGORITHM_PATTERN_SORTTOOL_H
