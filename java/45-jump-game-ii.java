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
