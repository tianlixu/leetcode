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
     * Reference: https://en.wikipedia.org/wiki/Maximum_subarray_problem
     */
    public int maxSubArray(int[] nums) {
        int dpMax = Integer.MIN_VALUE;
        int dpi = 0;
 
        for (int num : nums) {
            dpi = Math.max(dpi + num, num);
            dpMax = Math.max(dpMax, dpi);
        }

        return dpMax;
    }

    /*
     * Divide and Conquer
     *
     * Divide the problem
     * Divide the array a[0,...,n] into two sub arrays a[0,...,mid] and a[mid+1,...,n]
     * where mid = (0 + n) / 2

     * The maximum sub array may exist in a[0,...,mid] which is
     * maxSumLeft = maxSubarray(a[0,...,mid]) = a[i] + ... + a[j] 
     * where 0 =< i < j <= mid
     * 
     * The maximum sub array may exist in a[mid,...,n] which is
     * maxSumRight = maxSubarray(a[mid+1,...,n]) = a[i] + ... + a[j] 
     * where mid+1 =< i < j <= n

     * Or the maxmimu sub array may exist part in a[0,...,mid] and part in a[mid+1,...,n] which is
     * maxSumCross = maxSumCrossLeft + maxSumCrossRight, where
     * maxSumCrossLeft = a[i] + .. + a[mid] where 0 =< i < mid
     * maxSumCrossLeft = a[mid] + .. + a[i] where mid < i <= n
     *
     * Time: O(nlogn)
     */
    public int maxSubArray(int[] nums) {
        return maxSubArray(nums, 0, nums.length - 1);
    }

    public int maxSubArray(int[] nums, int low, int high) {
        if (low == high) {
            return nums[low];
        }

        int mid = (low + high) / 2;

        // the max sub array in the left, low =< i <= j <= mid
        int maxSumLeft = maxSubArray(nums, low, mid);
        // the max sub array in the left, mid < i <= j <= high
        int maxSumRight = maxSubArray(nums, mid+1, high);
        // the max sub array is crossing the middle, low =< i <= mid < j <= high
        int maxSumCross = maxSubArrayCross(nums, low, mid, high);

        return Math.max(Math.max(maxSumLeft, maxSumRight), maxSumCross);
    }

    /*
     * Time: O(n)
     */
    private int maxSubArrayCross(int[] nums, int low, int mid, int high) {
        int maxSumCrossLeft = Integer.MIN_VALUE;
        int maxSumCrossRight = Integer.MIN_VALUE;

        int maxSumTemp = 0;
        // left max sub array
        for (int i = mid; i>= low; i--) {
            maxSumTemp += nums[i];
            maxSumCrossLeft = Math.max(maxSumCrossLeft, maxSumTemp);
        }

        maxSumTemp = 0;
        // right max sub array
        for (int j = mid + 1; j <= high; j++) {
            maxSumTemp += nums[j];
            maxSumCrossRight = Math.max(maxSumCrossRight, maxSumTemp);
        }

        return maxSumCrossLeft + maxSumCrossRight;
    }

}

