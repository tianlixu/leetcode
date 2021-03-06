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

// beats 93%
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] ret = new int[2];
        HashMap<Integer, Integer> map = new HashMap<>();

        for (int i=0; i<nums.length; i++) {
            if (map.containsKey(nums[i])) {
                ret[0] = map.get(nums[i]);
                ret[1] = i;
                break;
            } else {
                map.put(target - nums[i], i);
            }
        }
        
        return ret;
    }
}

// beats 75%
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] ret = new int[2];
        HashMap<Integer, Integer> map = new HashMap<>();

        for (int i=0; i<nums.length; i++) {
            Integer index = map.get(nums[i]);
            if (index == null) {
                map.put(target - nums[i], i);
            } else {
                ret[0] = index;
                ret[1] = i;
                break;
            }
        }
        
        return ret;
    }
}

