//
// Created by mqjyl on 2020/7/27.
//

#ifndef ALGORITHM_PATTERN_CODE_SLIDINGWINDOW_H
#define ALGORITHM_PATTERN_CODE_SLIDINGWINDOW_H
#include <vector>
#include <string>

class SlidingWindow {
public:
    /*  左右指针  */
    // 167. 两数之和 II - 输入有序数组
    std::vector<int> twoSum(std::vector<int>& numbers, int target);
    // 三数之和
    std::vector<std::vector<int>> threeSumTarget(std::vector<int>& nums, int target);
    // 四数之和
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target);


    // 盛最多水的容器
    int maxArea(std::vector<int>& height);
    // 125. 验证回文串
    bool isPalindrome(std::string s);


    /*  滑动窗口  */
    // 长度最小的子数组
    int minSubArrayLen(int s, std::vector<int>& nums);
    // 最小覆盖子串
    std::string minWindow(std::string s, std::string t);
    // 字符串的排列
    bool checkInclusion(std::string s1, std::string s2);
    // 找到字符串中所有字母异位词
    std::vector<int> findAnagrams(std::string s, std::string p);
    // 不含有重复字符的 最长子串 的长度
    int lengthOfLongestSubstring(std::string s);
    // 最大连续1的个数 III
    int longestOnes(std::vector<int>& A, int K);
    // 340 至多包含 K 个不同字符的最长子串
    int lengthOfLongestSubstringKDistinct(std::string s, int k);
};


#endif //ALGORITHM_PATTERN_CODE_SLIDINGWINDOW_H
