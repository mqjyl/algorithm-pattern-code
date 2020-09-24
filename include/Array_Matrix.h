//
// Created by mqjyl on 2020/9/7.
//

#ifndef ALGORITHM_PATTERN_CODE_ARRAY_MATRIX_H
#define ALGORITHM_PATTERN_CODE_ARRAY_MATRIX_H
#include <vector>
#include <string>

class Array_Matrix {
public:
    /*  数组  */
    // 数组中出现次数超过一半的数字
    int majorityElement(std::vector<int>& nums);
    // 面试题 16.16. 部分排序
    std::vector<int> subSort(std::vector<int>& array);
    // 数组中未出现的最小正整数
    int findMin(std::vector<int> &arr);
    // 二维数组中未出现的最小正整数
    int findMin(std::vector<std::vector<int> > &arr);
    // 多个整数拼接成最大整数
    std::string getMaxNum(std::vector<int> &nums);
    // 数组和差值最小
    int minDiff(std::vector<int> &a, std::vector<int> &b);


    /*  矩阵  */
    // 对角打印：将一个矩阵（二维数组）按对角线向右进行打印。
    std::vector<int> slashOrder(std::vector<std::vector<int> > &matrix);
    // 顺时针打印
    std::vector<int> spiralOrder(std::vector<std::vector<int> >& matrix);
    // 旋转矩阵
    void rotate(std::vector<std::vector<int>>& matrix);
};


#endif //ALGORITHM_PATTERN_CODE_ARRAY_MATRIX_H
