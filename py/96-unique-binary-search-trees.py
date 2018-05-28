"""
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
"""
class Solution:
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 1:
            return 1
        
        dp = [0] * (n + 1)
        dp[0] = 1
        dp[1] = 1
        
        for i in range(2, n+1): # for-loop beats 95%, while while-loop beats only 59%
            for j in range(0, i):
                dp[i] += dp[j] * dp[i-j-1]
            
        return dp[n]


# recursive solution,  Time Limit Exceeded
class Solution:
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        return self.numTreesHelper(1, n)
    
    def numTreesHelper(self, n1, n2):
        """
        :type n1: int, left index
        :type n2: int, right index
        :rtype: int
        """
        num = 0
        if n1 > n2:
            num = 1
        else:
            for n in range(n1, n2+1):
                num_left = self.numTreesHelper(n1, n-1)
                num_right = self.numTreesHelper(n+1, n2)
                num += num_left * num_right
                
        return num

