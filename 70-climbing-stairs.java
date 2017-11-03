/*
  Source : https://leetcode.com/problems/climbing-stairs/
  Author : Alex Xu
  Date   : Nov 03, 2017
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
    public int climbStairs(int n) {
        int[] a = new int[n+1];
        Arrays.fill(a, 1); // acutally, here we only need to set a[0] and a[1]
        
        for (int i=2; i<=n; i++) {
            a[i] = a[i-1] + a[i-2];
        }
        
        return a[n];
    }
}

class Solution {
    public int climbStairs(int n) {
        if (n <=2) {
            return n;
        }
        
        int dp1 = 1; 
        int dp2 = 2;
        int dp=0;
        int i = 3;
        while (i <= n) {
            dp = 0;
            dp += dp1;
            dp1 = dp2;
            dp += dp2;
            dp2 = dp;
            
            i++;
        }
        
        return dp;
    }
}
