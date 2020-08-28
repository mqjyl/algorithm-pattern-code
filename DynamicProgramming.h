//
// Created by mqjyl on 2020/7/7.
//

#ifndef ALGORITHM_PATTERN_DYNAMICPROGRAMMING_H
#define ALGORITHM_PATTERN_DYNAMICPROGRAMMING_H
#include <vector>

class DynamicProgramming {
public:
    // Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
    int minimumTotal(std::vector<std::vector<int>>& triangle);
    /*
     * Given a m x n grid filled with non-negative numbers, find a path
       from top left to bottom right which minimizes the sum of all numbers along its path.
     * Note: You can only move either down or right at any point in time.
     */
    int minPathSum(std::vector<std::vector<int>>& grid);
    /*
     * A robot is located at the top-left corner of a m x n grid.
     * The robot can only move either down or right at any point in time. The robot is trying to reach
       the bottom-right corner of the grid.
     * How many possible unique paths are there?
     */
    int uniquePaths(int m, int n);
    /*
     * Now consider if some obstacles are added to the grids. How many unique paths would there be?
     * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
     */
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid);
    /*
     * You are climbing a stair case. It takes n steps to reach to the top.
     * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
     */
    int climbStairs(int n);
    /*
     * Given an array of non-negative integers, you are initially positioned at the first index of the array.
     * Each element in the array represents your maximum jump length at that position.
     * Determine if you are able to reach the last index.
     */
    bool canJump(std::vector<int>& nums);
    /*
     * Given an array of non-negative integers, you are initially positioned at the first index of the array.
     * Each element in the array represents your maximum jump length at that position.
     * Your goal is to reach the last index in the minimum number of jumps.
     * You can assume that you can always reach the last index.
     */
    int jump(std::vector<int>& nums);

    // 0-1背包问题

};


#endif //ALGORITHM_PATTERN_DYNAMICPROGRAMMING_H
