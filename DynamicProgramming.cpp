//
// Created by mqjyl on 2020/7/7.
//
#include <algorithm>
#include "DynamicProgramming.h"

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
