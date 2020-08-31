//
// Created by mqjyl on 2020/7/27.
//

#ifndef ALGORITHM_PATTERN_CODE_SLIDINGWINDOW_H
#define ALGORITHM_PATTERN_CODE_SLIDINGWINDOW_H
#include <vector>
#include <string>

class SlidingWindow {
public:
    // 盛最多水的容器
    int maxArea(std::vector<int>& height);
    // 长度最小的子数组
    int minSubArrayLen(int s, std::vector<int>& nums);
    // 最小覆盖子串
    std::string minWindow(std::string s, std::string t);
    // 字符串的排列
    bool checkInclusion(std::string s1, std::string s2);
    // 找到字符串中所有字母异位词
    std::vector<int> findAnagrams(std::string s, std::string p);
    // 最大连续1的个数 III
    int longestOnes(std::vector<int>& A, int K);
};


#endif //ALGORITHM_PATTERN_CODE_SLIDINGWINDOW_H
