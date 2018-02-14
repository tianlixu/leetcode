/*
  Source : https://leetcode.com/problems/maximum-subarray/
  Author : Alex Xu
  Date   : May 28, 2017
  Problem:
 
  Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

  For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
  the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/

class Solution {
    /*
     * scaning algorithm:
     * A negative value does not help for SUM.
     *
     * Your run time beats 9% of java submissions
     */
    public int maxSubArray2(int[] nums) {
        int maxSum = Integer.MIN_VALUE;
        int curSum = 0; // current sum
        
        for (int num : nums) {
            if (curSum < 0) {
                curSum = num;
            } else {
                curSum += num;
            }
            
            maxSum = Math.max(maxSum, curSum);
        }
        
        return maxSum;
    }

    /*
     * Dynamic programming
     *
     * The state formular is:
     *     dp[i] - the MSS(Maximum Subarray Sum) of subarray a[j,...,i] (j >= 0)
     *             dp[i] = a[j] + a[...] + a[i]
     *             the last element of that subarray must be the last element in array a[0,1,...,i]
     * then
     *     dp[i+1] = max(dp[i] + a[i+1], a[i+1])
     * so
     *     max(dp[0], dp[1] ... dp[n]) is the answer.
     *
     * The meaning of dp[i] is the current sum in previous solution.
     *
     * Time: O(n), Space: O(1)
     * 
     * Your run time beats 88.24% of java submissions
     */
    class Solution {
             public int maxSubArray(int[] nums) {
             int dpMax = Integer.MIN_VALUE;
             int dpi = 0;
 
             for (int num : nums) {
                 dpi = Math.max(dpi + num, num);
                 dpMax = Math.max(dpMax, dpi);
             }

             return dpMax;
         }
    }
}

