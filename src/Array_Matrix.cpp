//
// Created by mqjyl on 2020/9/7.
//
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <climits>
#include <utility>
#include "../include/Array_Matrix.h"

using namespace std;

/**
 * 数组
 * */
// 数组中出现次数超过一半的数字
//int Array_Matrix::majorityElement(std::vector<int>& nums){
//    int len = nums.size();
//    unordered_map<int, int> imap;
//    for(int num : nums){
//        imap[num]++;
//        if(imap[num] > len / 2)
//            return num;
//    }
//    return 0;
//}

int Array_Matrix::majorityElement(std::vector<int>& nums){
    int votes = 0;
    int num = nums[0];
    for(int i = 1; i < nums.size(); ++i){
        votes = nums[i] != num ? votes - 1 : votes + 1;
        if(votes < 0){
            num = nums[i];
            votes = 0;
        }
    }
    return num;
}

// 面试题 16.16. 部分排序
//std::vector<int> Array_Matrix::subSort(std::vector<int>& array){
//    vector<int> tmp = array;
//    sort(tmp.begin(), tmp.end());
//    int left = -1, right = -1;
//    for(int i = 0; i < array.size(); i++){
//        if(tmp[i] != array[i]){
//            if(left == -1)
//                left = i;
//            right = i;
//        }
//    }
//    return vector<int>{left, right};
//}
std::vector<int> Array_Matrix::subSort(std::vector<int>& array){
    int left = -1, right = -1;
    int max_val = INT_MIN;
    int min_val = INT_MAX;
    int len = array.size();
    for(int i = 0; i < len; i++){
        if(array[i] < max_val){
            right = i;
        }else{
            max_val = max(max_val, array[i]);
        }
        if(array[len - i - 1] > min_val){
            left = len - i - 1;
        }else{
            min_val = min(min_val, array[len - i - 1]);
        }
    }
    return vector<int>{left, right};
}

// 数组中未出现的最小正整数
int Array_Matrix::findMin(std::vector<int> &arr){
    int left = 0, right = arr.size();
    while(left < right){
        int tmp = arr[left];
        if(tmp == left + 1){
            left++;
        }else if(tmp < left + 1 || tmp > right || arr[tmp - 1] == tmp){
            right--;
            arr[left] = arr[right];
        }else{
            swap(arr[left], arr[tmp - 1]);
        }
    }
    return left + 1;
}
// 二维数组中未出现的最小正整数
int Array_Matrix::findMin(std::vector<std::vector<int> > &arr){
    int rlen = arr.size();
    int clen = arr[0].size();
    int left = 0, right = rlen * clen;
    while(left < right){
        int tmp = arr[left / clen][left % clen];
        if(tmp == left + 1){
            left++;
        }else if(tmp < left + 1 || tmp > right || arr[(tmp - 1) / clen][(tmp - 1) % clen] == tmp){
            right--;
            arr[left / clen][left % clen] = arr[right / clen][right % clen];
        }else{
            swap(arr[left / clen][left % clen], arr[(tmp - 1) / clen][(tmp - 1) % clen]);
        }
    }
    return left + 1;
}

// 多个整数拼接成最大整数
bool compare(const int& a, const int& b)
{
    //从大到小排序，使用字符串拼接
    return atoi((to_string(a) + to_string(b)).data())
           > atoi((to_string(b) + to_string(a)).data());
}
string Array_Matrix::getMaxNum(vector<int> &nums){
    string res;
    sort(nums.begin(), nums.end(), compare);
    for(int n : nums){
        res.append(to_string(n));
    }
    return res;
}

/**
 * 矩阵
 * */
// 对角打印：将一个矩阵（二维数组）按对角线向右进行打印。
vector<int> Array_Matrix::slashOrder(vector<vector<int> > &matrix) {
    int cols = matrix[0].size();
    int rows = matrix.size();
    vector<int> result;
    for (int l = 0; l < cols + rows - 1; l++) {
        int sum = l;
        for (int i = 0; i < rows; i++) {
            int j = sum - i;
            if (i >= 0 && i < rows && j >= 0 && j < cols) {
                result.push_back(matrix[i][j]);
            }
        }
    }
    return result;
}
// 螺旋矩阵
vector<int> Array_Matrix::spiralOrder(vector<vector<int> >& matrix) {
    vector<int> result;
    if(matrix.empty())
        return result;
    int row_s = 0, row_t = matrix.size() - 1;
    int col_s = 0, col_t = matrix[0].size() - 1;

    while(true){
        if(row_s <= row_t){
            for(int i = col_s; i <= col_t; ++i)
                result.push_back(matrix[row_s][i]);
            ++row_s;
            if(row_s > row_t)
                break;
        }
        if(col_s <= col_t){
            for(int i = row_s; i <= row_t; ++i)
                result.push_back(matrix[i][col_t]);
            --col_t;
            if(col_s > col_t)
                break;
        }
        if(row_s <= row_t){
            for(int i = col_t; i >= col_s; --i)
                result.push_back(matrix[row_t][i]);
            --row_t;
            if(row_s > row_t)
                break;
        }
        if(col_s <= col_t){
            for(int i = row_t; i >= row_s; --i)
                result.push_back(matrix[i][col_s]);
            ++col_s;
            if(col_s > col_t)
                break;
        }
    }
    return result;
}

// 旋转矩阵
void Array_Matrix::rotate(std::vector<std::vector<int>>& matrix){
    int n = matrix.size();
    for(int i = 0; i < n / 2; ++i){
        int count = n - i * 2;
        for(int j = i; j < i + count - 1; ++j){
            // 每次旋转四个
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[n - 1 - j][i];
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 -j];
            matrix[n - 1 - i][n - 1 -j] = matrix[j][n - 1 - i];
            matrix[j][n - 1 - i] = tmp;
        }
    }
}