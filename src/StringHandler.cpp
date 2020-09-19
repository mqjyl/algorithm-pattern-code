//
// Created by mqjyl on 2020/7/19.
//

#include <climits>
#include "../include/StringHandler.h"
using namespace std;

/**
 * 模式匹配
 * */

void getNext(std::string needle, std::vector<int> &next){
    if(needle.empty())
        return;
    next[0] = -1;
    next[1] = 0;
    next[2] = 1;
}

int StringHandler::kmp(std::string s, std::string p, std::vector<int> &next){

}


/**
 * 其他题型
 * */
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

// 151. 翻转字符串里的单词
std::string StringHandler::reverseWords(std::string s){
    string result;
    int left = 0, right = s.size() - 1;
    while(right >= 0){
        while(right >= 0 && s[right] == ' ') right--;
        if(right >= 0){
            left = right;
            while(left >= 0 && s[left] != ' ') left--;
            left++;
            if(left >= 0){
                for(int i = left; i <= right; i++){
                    result.push_back(s[i]);
                }
                result.push_back(' ');
            }
            right = left - 1;
        }
    }
    if(!result.empty() && result.back() == ' ')
        result.pop_back();
    return result;
}

// 最长回文子串
string StringHandler::longestPalindrome(string s) {
    string result = s.substr(0,1);
    int len = s.length();
    for(int i = 1;i < len;i++){
        if(s[i] == s[i - 1]){
            int m = i + 1;
            int n = i - 2;
            while(m < len && n >= 0 && s[m] == s[n]){
                m++; n--;
            }
            m--; n++;
            if(m - n + 1 > result.length())
                result = s.substr(n, m - n + 1);
        }
        if(i >= 2 && s[i] == s[i - 2]){
            int m = i + 1;
            int n = i - 3;
            while(m < len && n >= 0 && s[m] == s[n]){
                m++; n--;
            }
            m--; n++;
            if(m - n + 1 > result.length())
                result = s.substr(n, m - n + 1);
        }
    }
    return result;
}
// 最长回文子串 马拉车算法
std::string StringHandler::longestPalindrome_Manacher(std::string s){
    if(s.empty()){
        return "";
    }
    string str(s.size() * 2 + 1, '#');
    for(int i = 1, j = 0; i < str.size() && j < s.size(); i += 2, j++)
        str[i] = s[j];
    vector<int> pArr(str.size());
    int index = -1;
    int pR = -1;
    int ans = INT_MIN;
    int t = 0;
    for(int i = 0; i < str.size(); i++){
        pArr[i] = pR > i ? min(pArr[2 * index - i], pR - i) : 1;
        while(i + pArr[i] < str.size() && i - pArr[i] > -1){
            if(str[i + pArr[i]] == str[i - pArr[i]]){
                pArr[i]++;
            }else{
                break;
            }
        }
        if(i + pArr[i] > pR){
            pR = i + pArr[i];
            index = i;
        }
        if(ans < pArr[i]){
            ans = pArr[i];
            t = i;
        }
    }
    // return ans - 1; // 最长回文字串长度
    string result;
    for(int i = t - ans + 1; i < t + ans; i++){
        if(str[i] != '#'){
            result.push_back(str[i]);
        }
    }
    return result;
}

// 实现 atoi() 函数
int StringHandler::myAtoi(string str) {
    int idx = 0;
    if(str.empty())
        return 0;
    long long result = 0;
    int len = str.size();
    bool flag = true;
    while(idx < len && str[idx] == ' ')
        idx++;
    if(idx < len && (str[idx] == '-' || str[idx] == '+')){
        if(str[idx] == '-')
            flag = false;
        idx++;
    }
    if(idx >= len || !(str[idx] <= '9' && str[idx] >= '0'))
        return 0;
    while(idx < len && str[idx] <= '9' && str[idx] >= '0'){
        int num = str[idx] - '0';
        result = result * 10 + num;
        if(result >= long(INT_MAX) && flag){
            return INT_MAX;
        }
        if(result >= long(INT_MAX) + 1 && !flag){
            return INT_MIN;
        }
        idx++;
    }
    return flag ? result : -1 * result;
}

// 72. 编辑距离
int StringHandler::minDistance(std::string word1, std::string word2){
    int m = word1.size();
    int n = word2.size();
    if(m * n == 0) return n + m;
    vector<vector<int> > dp(m + 1, vector<int>(n + 1));
    for(int i = 0; i <= m; i++){
        dp[i][0] = i;
    }
    for(int i = 0; i <= n; ++i){
        dp[0][i] = i;
    }
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            int a = dp[i - 1][j] + 1;
            int b = dp[i][j - 1] + 1;
            int c = dp[i - 1][j - 1];
            if(word1[i - 1] != word2[j - 1]) c++;
            dp[i][j] = min(a, min(b, c));
        }
    }
    return dp[m][n];
}
