//
// Created by mqjyl on 2020/7/7.
//
#include <algorithm>
#include <climits>
#include <cstring>
#include "../include/DynamicProgramming.h"

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

/**
 * 股票买卖问题
 * */
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


/**
 * 背包问题
 * */
/*  背包问题  */
// 01背包
//int DynamicProgramming::maxValue(std::vector<int>& values, std::vector<int>& weight, int n, int m){
//    int dp[n + 1][m + 1];
//    memset(dp, 0, sizeof(dp));
//    for(int i = 1; i <= n; ++i){
//        for(int j = 1; j <= m; ++j){
//            if(weight[i] <= j)
//                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + values[i]);
//            else
//                dp[i][j] = dp[i - 1][j];
//        }
//    }
//    return dp[n][m];
//}
int DynamicProgramming::maxValue(std::vector<int>& values, std::vector<int>& weight, int n, int m){
    int dp[m + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; ++i){
        for(int j = m; j >= 1; --j){
            if(weight[i] <= j)
                dp[j] = max(dp[j], dp[j - weight[i]] + values[i]);
        }
    }
    return dp[m];
}

// 完全背包
int DynamicProgramming::maxValue_i(std::vector<int>& values, std::vector<int>& weight, int n, int m){
    int dp[m + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; ++i){
        for(int j = weight[i]; j <= m; ++j){
            dp[j] = max(dp[j], dp[j - weight[i]] + values[i]);
        }
    }
    return dp[m];
}

// 多重背包
//int DynamicProgramming::maxValue_ii(std::vector<int>& values, std::vector<int>& weight, std::vector<int>& count, int n, int m){
//    int dp[m + 1];
//    memset(dp, 0, sizeof(dp));
//    for(int i = 1; i <= n; ++i){
//        for(int j = m; j >= weight[i]; --j){
//            for(int k = 0; k <= count[i]; k++){
//                if(j - k * weight[i] < 0)
//                    break;
//                dp[j] = max(dp[j], dp[j - k * weight[i]] + k * values[i]);
//            }
//        }
//    }
//    return dp[m];
//}
// 多重背包，二进制优化
//int DynamicProgramming::maxValue_ii(std::vector<int>& values, std::vector<int>& weight, std::vector<int>& count, int n, int m){
//    vector<pair<int, int> > lis;
//    lis.push_back({0, 0});
//    int idx, c;
//    for(int i = 1; i <= n; ++i){
//        c = 1;
//        while(count[i] - c > 0){
//            count[i] -= c;
//            lis.push_back({c * values[i], c * weight[i]});
//            c *= 2;
//        }
//        lis.push_back({count[i] * values[i], count[i] * weight[i]});
//    }
//    int dp[m + 1];
//    memset(dp, 0, sizeof(dp));
//    for(int i = 1; i <= lis.size(); ++i){
//        for(int j = m; j >= lis[i].second; --j){
//            dp[j] = max(dp[j], dp[j - lis[i].second] + lis[i].first);
//        }
//    }
//    return dp[m];
//}
// duochong
int DynamicProgramming::maxValue_ii(std::vector<int>& values, std::vector<int>& weight, std::vector<int>& count, int n, int m){
    int dp[m + 1];
    int q[m + 1];
    int num[m + 1];
    memset(dp, 0, sizeof(dp));
    int l, r;
    for(int i = 1; i <= n; ++i){
        int c = min(count[i], m / weight[i]);
        for(int b = 0; b < weight[i]; b++){
            l = r = 1;
            for(int t = 0; t <= (m - b) / weight[i]; t++){
                int tmp = dp[t * weight[i] + b] - t * values[i];
                while(l < r && q[r - 1] <= tmp)
                    r--;
                q[r] = tmp;
                num[r++] = t;
                // 滑动区间长度不大于c，因为dp[t * weight[i] + b] - t * values[i]既然存在，
                // 那么再加c区间的t * values[i]的值肯定能取到
                while(l < r && t - num[l] > c)
                    l++;
                // 因为dp中的是t * weight[i] + b,所以是q[l] + t * values[i]
                dp[t * weight[i] + b] = max(dp[t * weight[i] + b], q[l] + t * values[i]);
            }
        }
    }
    return dp[m];
}

/**
 * 石子堆问题
 * */
// 任意合并
int DynamicProgramming::mergeStones(vector<int> &nums){
    if(nums.empty())
        return 0;
    sort(nums.begin(), nums.end());
    int idx = 0;
    int res = 0;
    while(idx < nums.size() - 1){
        nums[idx] += nums[idx + 1];
        res += nums[idx];
        nums[idx + 1] = 0;
        int tmp = nums[idx];
        int i = idx + 1;
        for(; i < nums.size() && nums[i] < tmp; ++i){
            nums[i - 1] = nums[i];
        }
        nums[i - 1] = tmp;
        while(nums[idx] == 0)
            idx++;
    }
    return res;
}
// 相邻合并
//int DynamicProgramming::mergeStones_i(std::vector<int> &nums){
//    int len = nums.size();
//    int sum[len + 1];
//    sum[0] = 0;
//    int dp[len + 1][len + 1];
//    for(int i = 1; i <= len; ++i){
//        sum[i] = sum[i - 1] + nums[i - 1];
//        dp[i][i] = 0;
//    }
//    for(int v = 1; v < len; ++v){
//        for(int i = 1; i <= len - v; ++i){
//            int j = i + v;
//            dp[i][j] = INT_MAX;
//            for(int k = i; k < j; ++k){
//                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
//            }
//            dp[i][j] += sum[j] - sum[i - 1];
//        }
//    }
//    return dp[1][len];
//}
// 相邻合并——平行四边形优化
//int DynamicProgramming::mergeStones_i(std::vector<int> &nums){
//    int len = nums.size();
//    int sum[len + 1];
//    sum[0] = 0;
//    int dp[len + 1][len + 1];
//    int s[len + 1][len + 1];
//    for(int i = 1; i <= len; ++i){
//        sum[i] = sum[i - 1] + nums[i - 1];
//        dp[i][i] = 0;
//        s[i][i] = i;
//    }
//    for(int v = 1; v < len; ++v){ // v 控制离中心线距离
//        for(int i = 1; i <= len - v; ++i){ // i 控制行
//            int j = i + v;  // j 控制列
//            dp[i][j] = INT_MAX;
//            for(int k = s[i][j - 1]; k <= s[i + 1][j]; ++k){
//                if(dp[i][j] > dp[i][k] + dp[k + 1][j]) {
//                    dp[i][j] = dp[i][k] + dp[k + 1][j];
//                    s[i][j] = k;
//                }
//            }
//            dp[i][j] += sum[j] - sum[i - 1];
//        }
//    }
//    return dp[1][len];
//}
// 相邻合并——GarsiaWachs算法
int DynamicProgramming::mergeStones_i(std::vector<int> &nums){
    int ans = 0;
    int len = nums.size();
    int cnt = len - 3;
    while(cnt--){
        int tmp = 0;
        int i = 2;
        for(; i < len - 1; ++i){
            if(nums[i - 1] <= nums[i + 1]){
                tmp = nums[i - 1] + nums[i];
                ans += tmp;
                break;
            }
        }
        int j = i - 1;
        // 将 tmp 插入到合适的位置
        for(; nums[j - 1 ] < tmp; j--)
            nums[j] = nums[j - 1];
        nums[j] = tmp;
        // 删除第 i 个元素
        nums.erase(nums.begin() + i);
//        for(j = i; j < len - 1 ; j++)
//            nums[j] = nums[j + 1];
        len--;
    }
    return ans;
}
// 环形合并
int sum(std::vector<int> &nums, int i, int j){
    int ans = 0;
    for(; j > 0; j--, i++){
        if(i > nums.size() - 1)
            i %= (nums.size() - 1);
        ans += nums[i];
    }
    return ans;
}
pair<int, int> DynamicProgramming::mergeStones_ii(std::vector<int> &nums){
    int len = nums.size();
    int dp_min[len][len];
    int dp_max[len][len];
    for(int i = 1; i < len; i++){
        dp_min[i][1] = 0; // 没有合并则花费为0
        dp_max[i][1] = 0;
    }
    for(int j = 2; j < len; ++j){
        for(int i = 1; i < len; ++i){
            dp_min[i][j] = INT_MAX;
            dp_max[i][j] = INT_MIN;
            for(int k = 1; k < j; k++){
                dp_min[i][j] = min(dp_min[i][j], dp_min[i][k] + dp_min[(i + k - 1) % (len - 1) + 1][j - k] + sum(nums, i, j));
                dp_max[i][j] = max(dp_max[i][j], dp_max[i][k] + dp_max[(i + k - 1) % (len - 1) + 1][j - k] + sum(nums, i, j));
            }
        }
    }
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(int i = 1; i < len; i++){//从第几堆石子开始结果最小
        mini = min(mini, dp_min[i][len - 1]);
        maxi = max(maxi, dp_max[i][len - 1]);
    }
    return make_pair(mini, maxi);
}
