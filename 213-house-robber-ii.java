/*
  Source : https://leetcode.com/problems/house-robber-ii/
  Author : Alex Xu
  Date   : Jul 28, 2016
  Problem:
 
  After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

  Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

/*
  Tag: DP
  Solution:
  Continue with 198-house-robber, the solution for this problem is quite straightforward:

  Since you cannot rob both the first and the last house because they are neighbours, just create two seperate vectors, one excluding the first house, and the other  excluding the last house. The best solution generates from these two vectors using the original solution for 198.

  1, 2, 3, 4,...,n
  A: if you rob 1, then you cannot rob 2 and n, it becomes problem 198 to find solution for a[1] + dp(3,..., n-1)
  B: if you do not rob 1, then, it becomes problem 198 to find solution for  dp(2,..., n)
  The max(A, B) becomes the final solution for this problem.
*/
class Solution {
    /*
    public int rob(int[] nums) {
        int ret = 0;
        switch (nums.length) {
        case 0:
            ret = 0;
            break;
        case 1:
            ret = nums[0];
            break;
        case 2:
            ret = Math.max(nums[0], nums[1]);
            break;
        case 3:
            ret = Math.max(Math.max(nums[0], nums[1]), nums[2]);
        default:
            ret = Math.max(robAline(nums, 1, nums.length), nums[0] + robAline(nums, 2, nums.length-1));
        }

        return ret;
    }
    */
    /* the above cases for 1, 2 and 3 have already been covered in default branch, thus we have this */
    public int rob(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        else {
            return Math.max(robAline(nums, 1, nums.length), nums[0] + robAline(nums, 2, nums.length-1));
        }
    }

    public int robAline(int[] nums, int low, int high) { // array [low, high)
        int dp0 = 0;
        int dp1 = 0;
        int dp = 0;

        for (int i=low; i<high; i++) {
            int n = nums[i];
            dp = Math.max(dp0 + n, dp1);

            dp0 = dp1;
            dp1 = dp;
        }

        return dp;
    }
}
