//
// Created by mqjyl on 2020/7/19.
//

#ifndef ALGORITHM_PATTERN_CODE_STRINGHANDLER_H
#define ALGORITHM_PATTERN_CODE_STRINGHANDLER_H
#include<string>
#include<vector>

class StringHandler {
public:
    // 实现 strStr()
    int strStr(std::string haystack, std::string needle);
    // 替换空格
    std::string replaceSpace(std::string s, const std::string p);
};


#endif //ALGORITHM_PATTERN_CODE_STRINGHANDLER_H
