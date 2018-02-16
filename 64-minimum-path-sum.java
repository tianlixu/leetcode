/*
  Source : https://leetcode.com/problems/minimum-path-sum/
  Author : Alex Xu
  Date   : Jul 15, 2016
  Problem:

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/


/*
  Tag: DP
  
  +-----+-----+-----+-----+
  |     | m-1 |     |     |
  |     | n   |     |     |
  +-----+-----+-----+-----+
  | m   | m   |     |     |
  | n-1 | n   |     |     |
  +-----+-----+-----+-----+
  |     |     |     |     |
  |     |     |     |     |
  +-----+-----+-----+-----+

  To reach cell (m, n), you can
  either 
    move down from cell (m-1, n) if (m-1, n) exists. The sum for this path is: sum1 = dp(m-1, n) + grid[m,n]
  or
    move right from (m, n-1) if (m, n-1) exists. The sum for this path is: sum2 = dp(m, n-1) + grid[m,n]

  Finally, the minimum path sum to reach (m, n) is: min(sum1, sum2).

  The DP formula is:
    dp(m,n) = min(dp(m-1, n), dp(m, n-1)) + grid[m][n];
 */


class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        
        int[][] dp = new int[m][n];
        
        dp[0][0] = grid[0][0];

        // initialize the 1st column, you can only move downward
        for (int i=1; i<m; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        // initialize the 1st row, you can only move rightward
        for (int j=1; j<n; j++) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                dp[i][j] = Math.min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        
        return dp[m-1][n-1];
    }
}

/* 
 * recursive solution,
 * Time Limit Exceeded
 */
class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
            
        return helper(grid, m-1, n-1);
    }
    public int helper(int[][] grid, int m, int n) {

        if (m == 0 && n == 0)
            return grid[0][0];

        return grid[m][n] + (m == 0 ? helper(grid, m, n-1)
                             : n == 0 ? helper(grid, m-1, n)
                             : Math.min(helper(grid, m-1, n), helper(grid, m, n-1)));
    }
}
