/**
  Source : https://leetcode.com/problems/unique-binary-search-trees/description/
  Author : Alex Xu
  Date   : May 28, 2018
  Problem: Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

DP Solution:
dp[i] : 1, 2, 3, ..., i
dp[i+1]: 
    dp[0] * dp[i]: 1,  2,3,...i,i+1
  + dp[1] * dp[i-1]: 1,  2,  3,...i,i+1
  + dp[2] * dp[i-2]: 1,2,  3,  4,...i,i+1
    ...
  + dp[i] * dp[0]: 1,2,3,...i,  i+1
*/

// beats 100% in Java :O
class Solution {
    public int numTrees(int n) {
        if (n < 1) {
            return 0;
        }

        int[] dp = new int[n + 1];
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }

        return dp[n];
    }
}
