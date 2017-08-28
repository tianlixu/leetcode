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
     *     f[i] - the MSS(Maximum Subarray Sum) of subarray a[0], a[0,1] ... a[0,1,...,i-1,i]
     * then
     *     f[i+1] = max(f[i] + a[i+1], a[i+1])
     * So /*
     *     max(f[0], f[1] ... f[n]) is the answer.
     *
     * Time: O(n), Space: O(1)
     * 
     * Your run time beats 88.24% of java submissions
     */
    class Solution {
        /*
         * Dynamic programming
         *
         * The state formular is:
         *     f[i] - the MSS(Maximum Subarray Sum) of subarray a[0], a[0,1] ... a[0,1,...,i-1,i]
         * then
         *     f[i+1] = max(f[i] + a[i+1], a[i+1])
         * So /*
         *     max(f[0], f[1] ... f[n]) is the answer.
         *
         * Time: O(n), Space: O(1)
         */
             public int maxSubArray(int[] nums) {
             int maxSum = Integer.MIN_VALUE;
             int f = 0; // current sum
 
             for (int num : nums) {
                 f = Math.max(f + num, num);
                 maxSum = Math.max(maxSum, f);
             }

             return maxSum;
         }
    }
}

