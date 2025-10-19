//
// Created by mqjyl on 2020/9/19.
//
#include <ctime>
#include <iostream>
#include "utils.h"

using namespace std;
/**
 * 洗牌算法
 * */
void Fisher_Yates_Shuffle(vector<int>& arr,vector<int>& res)
{
    int len = arr.size();
    srand((unsigned)time(NULL));
    for (int i = 0; i < len; ++i)
    {
        int k = rand() % arr.size();
        res.push_back(arr[k]);
        arr.erase(arr.begin() + k);
    }
}
void Knuth_Durstenfeld_Shuffle(vector<int> &arr)
{
    int len = arr.size();
    srand((unsigned)time(NULL));
    for (int i = len - 1; i >= 0; --i)
    {
        int k = rand() % (i + 1);
        swap(arr[k], arr[i]);
    }
}
void Inside_Out_Shuffle(const vector<int>& arr, vector<int>& res)
{
    res.assign(arr.size(), 0);
    copy(arr.begin(), arr.end(), res.begin());
    srand((unsigned)time(NULL));
    for (int i = 0; i < arr.size(); ++i)
    {
        int k = rand() % (i + 1);
        swap(res[k], res[i]);
    }
}
void testDealCards()
{
    vector<int> arr(54);
    for(int i = 0; i < 54; ++i)
        arr[i] = i + 1;
    vector<int> res;
    // Fisher_Yates_Shuffle(arr, res);
    // Knuth_Durstenfeld_Shuffle(arr);
    Inside_Out_Shuffle(arr, res);
    for(int a : res)
        cout << a << " ";
}