/*
  Source : https://leetcode.com/problems/unique-paths-ii/description/
  Author : Alex Xu
  Date   : May 29 , 2018
  Problem: A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/

// dp solution that beats 100% ?!
    class Solution {
        public int uniquePathsWithObstacles(int[][] obstacleGrid) {
            int m= obstacleGrid.length;
            int n = m > 0 ? obstacleGrid[0].length : 0;

            // init dp[0][0], actually, we can just return if grid[0][0] or gird[m-1][n-1] is 1(obstacle)
            int[][] dp = new int[m][n];
            dp[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
       
            // init the 1st column
            for (int i=1; i<m; i++) {
                if (dp[i-1][0] == 1 && obstacleGrid[i][0] == 0) {
                    dp[i][0] = 1;
                } else {
                    dp[i][0] = 0;
                }
            }

            // init the 1st row
            for (int j=1; j<n; j++) {
                if (dp[0][j-1] == 1 && obstacleGrid[0][j] == 0) {
                    dp[0][j] = 1;
                } else {
                    dp[0][j] = 0;
                }
            }

            // calculate others
            for (int i=1; i<m; i++) {
                for (int j=1; j<n; j++) {
                    if (obstacleGrid[i][j] == 1) {
                        dp[i][j] = 0;
                    } else {
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    }
                }
            }

            // dp[m-1][n-1] is the answer
            return dp[m-1][n-1];
        }

