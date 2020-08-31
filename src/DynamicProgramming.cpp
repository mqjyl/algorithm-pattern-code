//
// Created by mqjyl on 2020/7/7.
//
#include <algorithm>
#include <climits>
#include "../DynamicProgramming.h"

using namespace std;

int DynamicProgramming::minimumTotal(std::vector<std::vector<int>>& triangle) {
    std::vector<std::vector<int>> hash;
    std::vector<int> rHash;
    int len = triangle.size() - 1;
    for(int i = len;i >= 0; i--){
        for(int j = 0; j < i + 1;j++){
            if(i == len){
                rHash.push_back(triangle[i][j]);
            }else{
                rHash.push_back(std::min(hash[len - i - 1][j + 1], hash[len - i - 1][j]) + triangle[i][j]);
            }
        }
        hash.push_back(rHash);
        rHash.clear();
    }
    return hash[len][0];
}

int DynamicProgramming::minPathSum(std::vector<std::vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    std::vector<int> dp(n, 1);
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            if(i == 0 && j == 0){
                grid[i][j] = grid[i][j];
            }else if(i == 0 && j > 0){
                grid[i][j] = grid[i][j - 1] + grid[i][j];
            }else if(j == 0 && i > 0){
                grid[i][j] = grid[i - 1][j] + grid[i][j];
            }else{
                grid[i][j] = std::min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
            }
        }
    }
    return grid[m - 1][n - 1];
}

int DynamicProgramming::uniquePaths(int m, int n){
    std::vector<int> dp(n, 1);
    for(int i = 1;i < m;i++){
        for(int j = 1;j < n;j++){
            dp[j] = dp[j - 1] + dp[j];
        }
    }
    return dp[n - 1];
}

int DynamicProgramming::uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
    if(obstacleGrid[0][0] == 1)
        return 0;
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    std::vector<int> dp(n, 0);
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            if(i == 0 && j == 0){
                dp[j] = 1;
            }else if(i == 0 && j > 0){  // 初始化
                if(obstacleGrid[i][j] == 1 || dp[j - 1] == 0){
                    dp[j] = 0;
                }else{
                    dp[j] = 1;
                }
            }else if(j == 0 && i > 0){
                if(obstacleGrid[i][j] == 1){
                    dp[j] = 0;
                }
            }else{
                if(obstacleGrid[i][j] == 1){
                    dp[j] = 0;
                }else{
                    dp[j] = dp[j] + dp[j - 1];
                }
            }
        }
    }
    return dp[n - 1];
}

int DynamicProgramming::climbStairs(int n) {
    if(n == 1 || n == 2)
        return n;
    int x = 1, y = 2;
    for(int i = 2;i < n;i++){
        int tmp = x + y;
        x = y;
        y = tmp;
    }
    return y;
}

bool DynamicProgramming::canJump(std::vector<int>& nums){
    int curr_end = 0;
    for(int i = 0;i < nums.size();i++){
        if(curr_end >= i){
            curr_end = curr_end > (i + nums[i]) ? curr_end : (i + nums[i]);
        }else{
            curr_end = -1;
            break;
        }
    }
    return curr_end == -1 ? false : true;
}

//int DynamicProgramming::jump(std::vector<int>& nums){
//    int len = nums.size();
//    std::vector<int> dp(len, len);
//    dp[0] = 0;
//    for(int i = 0;i < len;i++){
//        for(int j = 1;j <= nums[i] && i + j < len;j++){
//            dp[i + j] = std::min(dp[i + j], dp[i] + 1);
//        }
//    }
//    return dp[len - 1];
//}

int DynamicProgramming::jump(std::vector<int>& nums){
    int len = nums.size() - 1;
    std::vector<int> dp(len, len);
    dp[len] = 0;
    for(int i = len; i >= 0; --i){
        if(nums[i] >= (len - i))
            dp[i] = 1;
        else{
            int tMin = len;
            for(int j = i + 1; j <= nums[i] + i; j++){
                tMin = std::min(tMin, dp[j]);
            }
            dp[i] = tMin;
        }
    }
    return dp[0];
}

// 股票买卖问题
// 121. 买卖股票的最佳时机 k = 1
//int DynamicProgramming::maxProfit(std::vector<int>& prices){
//    int len = prices.size();
//    int dp_i_0 = 0, dp_i_1 = INT_MIN;
//    for(int i = 0; i < len; i++){
//        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
//        dp_i_1 = max(dp_i_1, -prices[i]);
//    }
//    return dp_i_0;
//}

int DynamicProgramming::maxProfit(std::vector<int>& prices){
    int len = prices.size();
    vector<vector<int>> dp(len, vector<int>(2));

    for (int i = 0; i < len; i++) {
        if (i - 1 == -1) {
            dp[i][0] = 0;
            // 解释：
            //   dp[i][0]
            // = max(dp[-1][0], dp[-1][1] + prices[i])
            // = max(0, -infinity + prices[i]) = 0
            dp[i][1] = -prices[i];
            //解释：
            //   dp[i][1]
            // = max(dp[-1][1], dp[-1][0] - prices[i])
            // = max(-infinity, 0 - prices[i])
            // = -prices[i]
            continue;
        }
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
        dp[i][1] = max(dp[i-1][1], -prices[i]);
    }
    return len > 0 ? dp[len - 1][0] : 0;
}

// 122. 买卖股票的最佳时机 II
int DynamicProgramming::maxProfit_infinity(std::vector<int>& prices){
    int len = prices.size();
    int dp_i_0 = 0, dp_i_1 = INT_MIN;  // i = -1
    for(int i = 0; i < len; ++i){
        int temp = dp_i_0;
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
        dp_i_1 = max(dp_i_1, temp - prices[i]);
    }
    return dp_i_0;
}

// 309. 最佳买卖股票时机含冷冻期
int DynamicProgramming::maxProfit_icooldown(std::vector<int>& prices){
    int len = prices.size();
    int dp_i_0 = 0, dp_i_1 = INT_MIN;
    int dp_i_pre = 0;
    for(int i = 0; i < len; ++i){
        int temp = dp_i_0;
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
        dp_i_1 = max(dp_i_1, dp_i_pre - prices[i]);
        dp_i_pre = temp;
    }
    return dp_i_0;
}
// 714. 买卖股票的最佳时机含手续费
int DynamicProgramming::maxProfit_fee(std::vector<int>& prices, int fee){
    int len = prices.size();
    int dp_i_0 = 0, dp_i_1 = INT_MIN;  // i = -1
    for(int i = 0; i < len; ++i){
        int temp = dp_i_0;
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
        dp_i_1 = max(dp_i_1, temp - prices[i] - fee);
    }
    return dp_i_0;
}

// 123. 买卖股票的最佳时机 III
//int DynamicProgramming::maxProfit_2(std::vector<int>& prices){
//    int len = prices.size();
//    int dp_0[3], dp_1[3];
//    // base case
//    for(int k = 0; k < 3; ++k){
//        dp_0[k] = 0, dp_1[k] = INT_MIN;
//    }
//    for(int i = 0; i < len; ++i){
//        for(int j = 1; j <= 2; ++j){
//            dp_0[j] = max(dp_0[j], dp_1[j] + prices[i]);
//            dp_1[j] = max(dp_1[j], dp_0[j - 1] - prices[i]);
//        }
//    }
//    return dp_0[2];
//}
int DynamicProgramming::maxProfit_2(std::vector<int>& prices){
    int dp_i10 = 0, dp_i11 = INT_MIN;
    int dp_i20 = 0, dp_i21 = INT_MIN;

    for(int price : prices){
        dp_i10 = max(dp_i10, dp_i11 + price);
        dp_i11 = max(dp_i11, -price);
        dp_i20 = max(dp_i20, dp_i21 + price);
        dp_i21 = max(dp_i21, dp_i10 - price);
    }
    return dp_i20;
}

// 188. 买卖股票的最佳时机 IV
int DynamicProgramming::maxProfit_k(int k, std::vector<int>& prices){
    int len = prices.size();
    if(k > len / 2)
        return maxProfit_infinity(prices);
    int dp_0[k + 1], dp_1[k + 1];
    // base case
    for(int t = 0; t <= k; ++t){
        dp_0[t] = 0, dp_1[t] = INT_MIN;
    }
    for(int i = 0; i < len; ++i){
        for(int j = 1; j <= k; ++j){
            dp_0[j] = max(dp_0[j], dp_1[j] + prices[i]);
            dp_1[j] = max(dp_1[j], dp_0[j - 1] - prices[i]);
        }
    }
    return dp_0[k];
}
// 机器人达到指定位置方法数
//long long DynamicProgramming::getSolutions(int n, int m, int k, int p) {
//    vector<vector<long long>> solutions(k + 1, vector<long long>(n + 2));
//    // base case
//    for (int i = 0; i < n + 2; ++i) {
//        solutions[0][i] = 0;
//    }
//    solutions[0][m] = 1;
//    for (int i = 1; i < k + 1; ++i) {
//        for (int j = 1; j < n + 1; ++j) {
//            solutions[i][j] = solutions[i - 1][j - 1] + solutions[i - 1][j + 1];
//            solutions[i][j] %= prime;
//        }
//    }
//    return solutions[k][p];
//}

long long DynamicProgramming::getSolutions(int n, int m, int k, int p) {
    vector<long long> curr(n + 2);
    vector<long long> last(n + 2);
    // base case
    for (int i = 0; i < n + 2; ++i) {
        last[i] = 0;
    }
    last[m] = 1;
    for (int i = 1; i < k + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            curr[j] = last[j - 1] + last[j + 1];
            curr[j] %= prime;
        }
        for (int j = 1; j < n + 1; ++j) {
            last[j] = curr[j];
        }
    }
    return curr[p];
}