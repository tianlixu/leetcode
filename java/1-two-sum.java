/*
 Source : https://oj.leetcode.com/problems/two-sum/
 Author : Alex Xu
 Date   : Jan 16, 2017
 Problem: Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

 Tag    : array, hashmap
*/

import java.util.HashMap;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] ret = new int[2];
        HashMap<Integer, Integer> map = new HashMap<>();

        for (int i=0; i<nums.length; i++) {
            Integer index = map.get(nums[i]);
            if (index == null) {
                map.put(target - nums[i], i); // key is the 2nd addend, value is its index
            } else {
                ret[0] = index; // index for the 1st addend
                ret[1] = i;     // index for the 2nd addend
                break;          // found it, break then
            }
        }
        
        return ret;
    }
}
