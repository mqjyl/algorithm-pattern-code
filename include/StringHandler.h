//
// Created by mqjyl on 2020/7/19.
//

#ifndef ALGORITHM_PATTERN_CODE_STRINGHANDLER_H
#define ALGORITHM_PATTERN_CODE_STRINGHANDLER_H
#include<string>
#include<vector>

class StringHandler {
public:
    /*  模式匹配  */
    int kmp(std::string s, std::string p, std::vector<int> &next);

    /*  题型  */
    // 实现 strStr()
    int strStr(std::string haystack, std::string needle);
    // 替换空格
    std::string replaceSpace(std::string s, const std::string p);
    // 151. 翻转字符串里的单词
    std::string reverseWords(std::string s);
    // 最长回文子串
    std::string longestPalindrome(std::string s);
    std::string longestPalindrome_Manacher(std::string s);
    // 实现 atoi() 函数
    int myAtoi(std::string str);
    // 72. 编辑距离
    int minDistance(std::string word1, std::string word2);
};


#endif //ALGORITHM_PATTERN_CODE_STRINGHANDLER_H
