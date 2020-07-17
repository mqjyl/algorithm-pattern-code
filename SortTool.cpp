//
// Created by mqjyl on 2020/6/30.
//

#include <iostream>
#include "SortTool.h"
// 冒泡排序
std::vector<int> SortTool::bubbleSort(std::vector<int>& nums) {
    int len = nums.size();
    while(len > 1){
        for(int i = 0;i < len - 1;i ++){
            if(nums[i] > nums[i+1]){
                int tmp = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = tmp;
            }
        }
        len--;
    }
    return nums;
}

/***
 * 设计一个数据结构 list: rpush rpop lpush lpop index 五种方法的时间复杂度均为 O(1),
 * 数据量上限是100w（我回答使用双端队列+hashMap, 面试官说可以用两个数组实现）
 * */

// 快速排序
int partition(std::vector<int>& nums, int start, int stop){
    int idx = start + 1;
    for(int i = idx;i <= stop;i ++){
        if(nums[i] < nums[start]){
            int tmp = nums[i];
            nums[i] = nums[idx];
            nums[idx] = tmp;
            idx++;
        }
    }
    int tmp = nums[start];
    nums[start] = nums[idx - 1];
    nums[idx - 1] = tmp;
    return idx - 1;
}
void sortArray(std::vector<int>& nums, int start, int stop){
    if(start >= stop)
        return;
    int pivot = partition(nums, start, stop);
    sortArray(nums, start, pivot - 1);
    sortArray(nums, pivot + 1, stop);
}
std::vector<int> SortTool::quickSort(std::vector<int>& nums){
    sortArray(nums, 0, nums.size() - 1);
    return nums;
}

// 插入排序
std::vector<int> SortTool::insertionSort(std::vector<int>& nums){
    int len = nums.size();
    for(int i = 1;i < len; i++){
        int tmp = nums[i];
        int j;
        for(j = i - 1;j >= 0 && nums[j] > tmp;j--){
            nums[j + 1] = nums[j];
        }
        nums[j + 1] = tmp;
    }
    return nums;
}
// 希尔排序
std::vector<int> SortTool::shellSort(std::vector<int>& nums){

}
// 归并排序
void merge_sort(std::vector<int>& nums, int start, int stop){
    if(stop >= nums.size() || stop - start <= 0)
        return;
    // 拆分
    int mid = (stop - start) / 2 + start;
    //(stop - start + 1) / 2 + start; 有问题，因为[start,mid]是右闭区间
    std::cout<<"come in"<<std::endl;
    merge_sort(nums, start, mid);
    merge_sort(nums, mid + 1, stop);
    // 合并
    std::vector<int> tmp;
    int i = start, j = mid + 1;
    while(i <= mid && j <= stop){
        if(nums[i] < nums[j]){
            tmp.push_back(nums[i++]);
        }else{
            tmp.push_back(nums[j++]);
        }
    }
    while(i <= mid){
        tmp.push_back(nums[i++]);
    }
    while(j <= stop){
        tmp.push_back(nums[j++]);
    }
    for(i = 0, j = start; i < tmp.size() && j <= stop; i++, j++)
        nums[j] = tmp[i];
}
std::vector<int> SortTool::mergeSort(std::vector<int>& nums){
    merge_sort(nums, 0, nums.size() - 1);
    return nums;
}