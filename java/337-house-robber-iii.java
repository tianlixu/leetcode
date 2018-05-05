/*
  Source : https://leetcode.com/problems/house-robber-iii/
  Author : Alex Xu
  Date   : Nov 14, 2017
  Problem:
 
  The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

  Determine the maximum amount of money the thief can rob tonight without alerting the police.

  Example 1:
  3
  / \
  2   3
  \   \ 
  3   1
  Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
  Example 2:
  3
  / \
  4   5
  / \   \ 
  1   3   1
  Maximum amount of money the thief can rob = 4 + 5 = 9.

  /*
  Tag: DP
  Solution:
  Continue with 198-house-robber, 213-house-robber-ii


  Either we take N, then we cannot take its children:
  dp1(N) = n + dp(grandchildLL) + dp(grandchildLR) + dp(grandchildRL) + dp(grandchildRR)
  
  or we do not take node N, then you can take its children
  dp2(N) = dp(childL) + dp(childR)

  then the solution is:
  dp(N) = max(dp1(N), dp2(N))
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

/**
 * Run time: 803ms
 */
class Solution {
    public int rob(TreeNode root) {
        if (root == null) {
            return 0;
        }

        if (root.left == null && root.right == null) {
            return root.val;
        }

        // take root
        int dp1 = root.val
            + (root.left == null ? 0 : rob(root.left.left) + rob(root.left.right))
            + (root.right == null ? 0 : rob(root.right.left) + rob(root.right.right));
        // do not take root
        int dp2 = (root.left == null ? 0 : rob(root.left)) + (root.right == null ? 0 : rob(root.right));

        return Math.max(dp1, dp2);
    }
}

/**
 * Continue with the above solution, this one uses a hash map to avoid a re-caculation for a a given node.
 * Run time: 7ms
 */
class Solution {
    public int rob(TreeNode root) {
        HashMap<TreeNode, Integer> m = new HashMap<TreeNode, Integer>();
        return rob(root, m);
    }
    
    public int rob(TreeNode root, HashMap<TreeNode, Integer> m) {
        if (root == null) {              
            return 0;
        } 
        
        Integer dp = m.get(root);
        if (dp != null) {
            return dp.intValue();
        }

        // take root                                                                                     
        int dp1 = root.val                                                                               
            + (root.left == null ? 0 : rob(root.left.left, m) + rob(root.left.right, m))                       
            + (root.right == null ? 0 : rob(root.right.left, m) + rob(root.right.right, m));                   
        // do not take root                                                                               
        int dp2 = (root.left == null ? 0 : rob(root.left, m)) + (root.right == null ? 0 : rob(root.right, m)); 

        dp = Math.max(dp1, dp2);          
        m.put(root, dp);
        
        return dp;
    }
}

/**
 * Avoid overlaping, reduced run time
 * Run time: 1ms
 */
class Solution {
    public int rob(TreeNode root) {
        int[] dp = robSub(root);
        return Math.max(dp[0], dp[1]);
    }

    /**
     * return an array of two values
     * dp[0] is the one without taking root
     * dp[1] is the one with taking root
     */
    private int[] robSub(TreeNode root) {
        if (root == null){
            return new int[2]; // return [0, 0]
        }

        int[] left = robSub(root.left);
        int[] right = robSub(root.right);
        int[] dp = new int[2];

        // no root
        dp[0] = Math.max(left[0], left[1]) + Math.max(right[0], right[1]);
        // with root
        dp[1] = root.val + left[0] + right[0];

        return dp;
    }
}
