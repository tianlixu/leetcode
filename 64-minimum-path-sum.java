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
        
        int[][] sum = new int[m][n];
        
        sum[0][0] = grid[0][0];
        
        for (int i=1; i<m; i++) {
            sum[i][0] = grid[i][0] + sum[i-1][0];
        }
        
        for (int j=1; j<n; j++) {
            sum[0][j] = grid[0][j] + sum[0][j-1];
        }
        
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                sum[i][j] = grid[i][j] + Math.min(sum[i-1][j], sum[i][j-1]);
            }
        }
        
        return sum[m-1][n-1];
    }
}