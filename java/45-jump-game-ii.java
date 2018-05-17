/**
  Source : https://leetcode.com/problems/jump-game-ii/description/
  Author : Alex Xu
  Date   : May 16, 2018
  Problem: Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.

Note:
You can assume that you can always reach the last index.
*/

/**
   Time: O(n), beats 95.26%
   Taking a step would give you a window size, once the window_right execeeds the end of the array, you get a solution.
   Take [2, 3, 1, 1, 4] for example:
   initilization: window [0, 0]
       index:       0  1  2  3  4
       value:       [2], 3, 1, 1, 4
       window: [0, 0]
   take 1st step, you get next window [1, 2]: 
       2, [3, 1], 1, 4
   take 2nd step, you get next window [3, 4], which reaches the end, you get a solution
       2, 3, 1, [1, 4]
 */ 

class Solution {
    public int jump(int[] nums) {
        int window_left = 0;
        int window_right = 0;
        int steps = 0;

        while (window_right < nums.length - 1) {
            steps ++;
            int j = window_right;
            while (window_left <= j) {
                window_right = Math.max(window_right, nums[window_left] + window_left);
                if (window_right >= nums.length - 1) {
                    break; // reaches the end, no need to continue
                }
                window_left ++;
            }
        }

        return steps;
    }
}



/**
 * Recursive solution
 * Find the first index that can reach the end then iterate.
 * This is just a solution with long runtime: 215ms
 */ 
class Solution {
    public int jump(int[] nums) {
        return jump(nums, nums.length);
    }
    
    public int jump(int[] nums, int length) {
        if(length > 1) {        
            for (int i=0; i< length; i++) {
                if (nums[i] + i + 1 >= length) { // can reach the end
                    return 1 + jump(nums, i+1);
                }
            }
        }
        return 0;
    }
}
