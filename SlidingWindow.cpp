//
// Created by mqjyl on 2020/7/27.
//
#include <unordered_map>
#include <climits>
#include <iostream>
#include "SlidingWindow.h"

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