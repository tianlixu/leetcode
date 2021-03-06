/*
  Source : https://leetcode.com/problems/climbing-stairs/
  Author : Alex Xu
  Date   : Jul 28, 2016
  Problem:
  You are climbing a stair case. It takes n steps to reach to the top.
  Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

  Tag: DP
  Solution:
  [0,1,2,...., i-2, i-1, i, .... n]

  To get to i, you can either
  A) take one step from i-1
  or
  B) take two steps directly from i-2
  So:
    dp(i) = dp(i-1) + dp(i-2)
*/


class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 1);

        for (int i=2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};
