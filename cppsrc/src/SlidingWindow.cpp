//
// Created by mqjyl on 2020/7/27.
//
#include <unordered_map>
#include <climits>
#include <iostream>
#include <algorithm>
#include "../include/SlidingWindow.h"

using namespace std;

// 盛最多水的容器
int SlidingWindow::maxArea(std::vector<int>& height) {
    int start = 0;
    int stop = height.size() - 1;
    int result = std::min(height[start], height[stop]) * (stop - start);
    while(start < stop){
        height[start] > height[stop] ? stop-- : start++;
        result = std::max(result, std::min(height[start], height[stop]) * (stop - start));
    }
    return result;
}

// 125. 验证回文串
int isValid(char c){
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
        return 1;
    }
    if(c >= '0' && c <= '9'){
        return 2;
    }
    return 0;
}
bool SlidingWindow::isPalindrome(string s) {
    int start = 0, stop = s.size() - 1;
    while(start < stop){
        while(start < stop && isValid(s[start]) == 0)
            start++;
        while(start < stop && isValid(s[stop]) == 0)
            stop--;
        if(start < stop){
            if(s[start] == s[stop] || (isValid(s[start]) == 1 && isValid(s[stop]) == 1 && abs(s[start] - s[stop]) == abs('a' - 'A'))) {
                start++, stop--;
            }else{
                return false;
            }
        }
    }
    return true;
}

/**
 * 滑动窗口
 **/
/* 滑动窗口
int SlidingWindow::minSubArrayLen(int s, std::vector<int>& nums) {
    if(nums.empty())
        return 0;
    int start = 0, stop = 0;
    int sum = 0;
    int result = nums.size() + 1;
    int tmpLen = 0;
    while(stop < nums.size()){
        sum += nums[stop];
        tmpLen++;
        if(sum >= s){
            while(sum >= s){
                sum -= nums[start++];
                tmpLen--;
            }
            result = std::min(result, tmpLen + 1);
        }
        stop++;
    }
    return result == nums.size() + 1 ? 0 : result;
}
*/
// 长度最小的子数组
int lower_bound(std::vector<int>& nums, int target){
    int left = 0, right = nums.size() - 1;
    int mid = -1;
    while(left < right){
        mid = (left + right) / 2;
        if(nums[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return nums[left] >= target ? left : -1;
}
int SlidingWindow::minSubArrayLen(int s, std::vector<int>& nums) {
    int len = nums.size();
    if(len == 0)
        return 0;
    int result = len + 1;
    std::vector<int> sums(len + 1, 0);
    for(int i = 1;i <= len;i++){
        sums[i] = sums[i - 1] + nums[i - 1];
    }
    for(int i = 1;i <= len;i++){
        int target = sums[i - 1] + s;
        auto bound = std::lower_bound(sums.begin(), sums.end(), target);
        if(bound != sums.end()){
            result = std::min(result, static_cast<int>(bound - sums.begin()) - (i - 1));
        }
    }
    return result == len + 1 ? 0 : result;
}

// 最小覆盖子串
std::string SlidingWindow::minWindow(std::string s, std::string t){
    if(s.empty() || t.empty())
        return "";
    std::unordered_map<char, int> need, window;
    for(char c : t)
        need[c]++;
    int left = 0, right = 0;
    int valid = 0;
    int len = s.size() + 1, start = 0;
    while(right < s.size()){
        char c = s[right];
        right++;
        if(need.count(c) > 0){
            window[c]++;
            if(need[c] == window[c])
                valid++;
        }
        while(valid == need.size()){
            if(len > right - left){
                len = right - left;
                start = left;
            }
            char d = s[left];
            left++;
            if(need.count(d) > 0){
                if(need[d] == window[d])
                    valid--;
                window[d]--;
            }
        }
    }
    return len == s.size() + 1 ? "" : s.substr(start, len);
}

// 字符串的排列
bool SlidingWindow::checkInclusion(std::string s1, std::string s2) {
    std::unordered_map<char, int> need, window;
    for(char c : s1)
        need[c]++;
    int left = 0, right = 0;
    int valid = 0;
    while(right < s2.size()){
        char c = s2[right];
        right++;
        if(need.count(c)){
            window[c]++;
            if(need[c] == window[c])
                valid++;
        }
        while(right - left >= s1.size()){
            if(valid == need.size())
                return true;
            char d = s2[left];
            left++;
            if(need.count(d)){
                if(need[d] == window[d])
                    valid--;
                window[d]--;
            }
        }
    }
    return false;
}

// 找到字符串中所有字母异位词
std::vector<int> SlidingWindow::findAnagrams(std::string s, std::string p){
    std::unordered_map<char, int> need, window;
    std::vector<int> result;
    for(char c : p)
        need[c]++;
    int left = 0, right = 0;
    int valid = 0;
    while(right < s.size()){
        char c = s[right];
        right++;
        if(need.count(c)){
            window[c]++;
            if(need[c] == window[c])
                valid++;
        }
        while(right - left >= p.size()){
            if(valid == need.size())
                result.push_back(left);
            char d = s[left];
            left++;
            if(need.count(d)){
                if(need[d] == window[d])
                    valid--;
                window[d]--;
            }
        }
    }
    return result;
}

// 不含有重复字符的 最长子串 的长度
int SlidingWindow::lengthOfLongestSubstring(string s) {
    int result = 0;
    int len = s.size();
    if(len == 0 || len == 1)
        return len;
    unordered_map<char, int> window;
    int left = 0, right = 0;
    while(right < len){
        char c = s[right];
        right++;
        window[c]++;
        if(window[c] > 1){
            result = max(result, right - left - 1);
            while(s[left] != c){
                window[s[left]]--;
                left++;
            }
            window[s[left]]--;
            left++;
        }
    }
    return max(result, right - left);
}

// 最大连续1的个数 III
int SlidingWindow::longestOnes(std::vector<int>& A, int K) {
    if(K == A.size())
        return K;
    int left = 0, right = 0;
    int result = 0, window = 0;
    while(right < A.size()){
        int i = A[right];
        right++;
        if(i == 1 || K > 0) {
            window++;
            if(i == 0)
                K--;
        }else{
            result = std::max(result, window);
            window++;
            K--;
            while(K < 0){
                int j = A[left];
                left++;
                window--;
                if(j == 0){
                    K++;
                }
            }
        }
    }
    return std::max(result, window);
}

// 340 至多包含 K 个不同字符的最长子串
int SlidingWindow::lengthOfLongestSubstringKDistinct(std::string s, int k){
    if(s.size() == 0 || k <= 0)
        return 0;
    unordered_map<char, int > m;
    int l = 0, r = 0;   // 滑动窗口左右指针
    int maxLen = 1;     // 最大长度
    int count = 0;
    while(r < s.size()){
        if (m[s[r]] == 0)
            count ++;
        m[s[r]] += 1;
        r++;
        // 左指针移动减小
        while (count > k){
            if(m[s[l]] == 1)
                count--;
            m[s[l]] -= 1;
            l++;
        }
        maxLen = max(maxLen, r - l);
    }
    return maxLen;
}


/**
 * 左右指针
 **/
// 167. 两数之和 II - 输入有序数组
std::vector<int> SlidingWindow::twoSum(std::vector<int>& numbers, int target){
    int lo = 0, hi = numbers.size() - 1;
    while(lo < hi){
        int tmp = numbers[lo] + numbers[hi];
        if(tmp == target){
            return std::vector<int>{lo + 1, hi + 1};
        }else if(tmp > target){
            hi--;
        }else{
            lo++;
        }
    }
    return std::vector<int>{};
}
vector<vector<int>> twoSumTarget(vector<int>& nums, int start, int target) {
    // nums 数组必须有序
    // sort(nums.begin(), nums.end()); // 如果无序，则排序
    int lo = start, hi = nums.size() - 1;
    vector<vector<int>> res;
    while (lo < hi) {
        int sum = nums[lo] + nums[hi];
        int left = nums[lo], right = nums[hi];
        if (sum < target) {
            while (lo < hi && nums[lo] == left) lo++;
        } else if (sum > target) {
            while (lo < hi && nums[hi] == right) hi--;
        } else {
            res.push_back({left, right});
            while (lo < hi && nums[lo] == left) lo++;
            while (lo < hi && nums[hi] == right) hi--;
        }
    }
    return res;
}

// 三数之和
vector<vector<int>> SlidingWindow::threeSumTarget(vector<int>& nums, int target) {
    // 输入数组 nums，返回所有和为 target 的三元组
    sort(nums.begin(), nums.end());
    int len = nums.size();
    vector<vector<int>> res;
    for(int i = 0; i < len; ++i){
        vector<vector<int>> tuples = twoSumTarget(nums, i + 1, target - nums[i]);
        for(vector<int> &tuple : tuples){
            tuple.push_back(nums[i]);
            res.push_back(tuple);
        }
        while(i < len - 1 && nums[i] == nums[i + 1]) i++;
    }
    return res;
}
vector<vector<int>> threeSumTarget1(vector<int>& nums, int start, int target) {
    // 输入数组 nums，返回所有和为 target 的三元组
    sort(nums.begin(), nums.end());
    int len = nums.size();
    vector<vector<int>> res;
    for(int i = start; i < len; ++i){
        vector<vector<int>> tuples = twoSumTarget(nums, i + 1, target - nums[i]);
        for(vector<int> &tuple : tuples){
            tuple.push_back(nums[i]);
            res.push_back(tuple);
        }
        while(i < len - 1 && nums[i] == nums[i + 1]) i++;
    }
    return res;
}

// 四数之和
std::vector<std::vector<int>> SlidingWindow::fourSum(std::vector<int>& nums, int target){
    // 数组需要排序
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> res;
    // 穷举 fourSum 的第一个数
    for (int i = 0; i < n; i++) {
        // 对 target - nums[i] 计算 threeSum
        vector<vector<int>>
                triples = threeSumTarget1(nums, i + 1, target - nums[i]);
        // 如果存在满足条件的三元组，再加上 nums[i] 就是结果四元组
        for (vector<int>& triple : triples) {
            triple.push_back(nums[i]);
            res.push_back(triple);
        }
        // fourSum 的第一个数不能重复
        while (i < n - 1 && nums[i] == nums[i + 1]) i++;
    }
    return res;
}