/*
  Source : https://leetcode.com/problems/unique-paths/
  Author : Alex Xu
  Date   : Jul 13, 2016
  Problem:

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/

/*
  dp(0, 0) = 1
  dp(m, n) = dp(m-1, n) + dp(m, n-1)
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > grid(m, vector<int> (n, 1)); // set all cells with 1, actually it only meaning full for grid[0][n] and grid[m][0]
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
            }
        }
        
        return  grid[m-1][n-1];
    }
}
    
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > grid(m, vector<int> (n, 0));
        grid[0][0] = 1;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (i==0 && j==0)
                continue;
                
                grid[i][j] = (i ==0 ? 0 : grid[i-1][j]) + (j == 0 ? 0 : grid[i][j-1]);
            }
        }
        
        return  grid[m-1][n-1];
    }
};


/*
  recursive version, time exceeds
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        return helper(m, n);
    }
    
    int helper(int m, int n) {
        if (m == 1 && n == 1)
            return 1;
            
        int down = 0;
        int right = 0;
        
        if (m > 1) {
            down = helper(m-1, n);
        }
        
        if (n > 1) {
            right = helper(m, n-1);
        }
        
        
        return down + right;
    }
};
