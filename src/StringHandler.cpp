//
// Created by mqjyl on 2020/7/19.
//

#include "../StringHandler.h"
using namespace std;

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
    int count = 0;
    for(auto c : s){
        if(c == ' ')
            ++count;
    }
    int len = count * p.size() + s.size() - count;
    string result(len, ' ');
    int i = 0;
    for(auto c : s){
        if(c != ' '){
            result[i++] = c;
        }
        else{
            for(auto d : p){
                result[i++] = d;
            }
        }
    }
    return result;
}

void getNext(std::string needle, std::vector<int> &next){
    if(needle.empty())
        return;
    next[0] = 0;
    next[1] = 1;
}