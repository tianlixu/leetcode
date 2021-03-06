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
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                grid[i][j] += (i == 0 ? grid[i][j-1]
                                      : j == 0 ? grid[i-1][j]
                                               : min(grid[i-1][j], grid[i][j-1]));
            }
        }

        return grid[m-1][n-1];
    }
    
    /*
      int minPathSum(vector<vector<int>>& grid) {
        return helper(grid, grid.size()-1, grid[0].size()-1);
    }
    
    int helper(vector<vector<int>>& grid, int m, int n) {
        if (m == 0 && n == 0)
            return grid[0][0];
            
        return grid[m][n] + (m == 0 ? helper(grid, m, n-1) 
                                    : n == 0 ? helper(grid, m-1, n) 
                                             : min(helper(grid, m-1, n), helper(grid, m, n-1)));
    }
    */
};
