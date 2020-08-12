//
// Created by mqjyl on 2020/7/19.
//

#include "StringHandler.h"

// 实现 strStr()
int StringHandler::strStr(std::string haystack, std::string needle){
    int i = 0, j = 0;
    while(i < haystack.size() && j < needle.size()){
        if(haystack[i] == needle[j]){
            i++; j++;
        }else{
            i = i - j + 1; j = 0;
        }
    }
    if(j >= needle.size())
        return i - needle.size();
    else
        return -1;
}
// 替换空格
std::string StringHandler::replaceSpace(std::string s, const std::string p){

}

void getNext(std::string needle, std::vector<int> &next){
    if(needle.empty())
        return;
    next[0] = 0;
    next[1] = 1;
}