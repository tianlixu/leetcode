/*
  Source : https://leetcode.com/problems/minimum-size-subarray-sum/description/
  Author : Alex Xu
  Date   : August 22, 2017
  Problem:
  Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

  For example, given the array [2,3,1,2,4,3] and s = 7,
  the subarray [4,3] has the minimal length under the problem constraint.

  click to show more practice.

  Credits:
  Special thanks to @Freezen for adding this problem and creating all test cases.

*/

/*
 * sliding window 
 */
class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int ret = Integer.MAX_VALUE;

        // sliding window, [left, right]
        int left = 0;
        int right = 0;

        // condition
        int sum = 0;

        while (right < nums.length) {
            /*
             * For each loop, either we increase the window if the current window is not a solution
             * or we shrink the window if the current window is a solution
             */
            if (sum < s) {
                sum += nums[right];
            } else {
                sum -= nums[left];
                left ++;
            }

            if (sum >= s) {
                ret = Math.min(ret, right - left + 1);
            } else {
                right ++;
            }
        }

        return ret == Integer.MAX_VALUE ? 0 : ret;
    }
}

class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int ret = Integer.MAX_VALUE;
        
        // sliding window
        int left = 0;
        int right = 0;
        
        // condition
        int sum = 0;
        
        while (right < nums.length) {
            // for each loop, we increase the window until we get a solution
            sum += nums[right];
            
            // once the current window is a solution, need to shrink the window from left
            // until the current window is not a solution any more
            while (sum >= s) {
                // the current window is a solution
                ret = Math.min(ret, right - left + 1);
                
                // shrink the window from left
                sum -= nums[left];
                left ++;
            }
            
            // increase window
            right ++;
        }
        
        return ret == Integer.MAX_VALUE ? 0 : ret;
    }
}