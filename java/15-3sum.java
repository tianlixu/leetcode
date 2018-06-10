/**
  Source : https://leetcode.com/problems/3sum/description/
  Author : Alex Xu
  Date   : Jun 10, 2018
  Problem: Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ret = new LinkedList<>();
        
        if (nums == null || nums.length < 3) {
            return ret;
        }
        
        Arrays.sort(nums); // NlogN
        
        int i = 0;
        while (i + 1 < nums.length - 1) { // have at least 3 numbers
            int j = i + 1;
            int k = nums.length - 1;
            if (nums[i] > 0 || nums[k] < 0) break;
            
            while (j < k) {
               int sum = nums[i] + nums[j] + nums[k];
               if (sum == 0) {
                    List<Integer> l = new LinkedList<>();
                    l.add(nums[i]);
                    l.add(nums[j]);
                    l.add(nums[k]);
                    ret.add(l);
                   do {j++;} while (j < k && nums[j] == nums[j-1]);
                   do {k--;} while (k > j && nums[k] == nums[k+1]);
                } else if (sum < 0) {
                    do {j++;} while (j < k && nums[j] == nums[j-1]);
                } else {
                    do {k--;} while (k > j && nums[k] == nums[k+1]);
                }
            }
            
            do {i++;} while (i+1 < nums.length -1 && nums[i] == nums[i-1]);
        }
        
        return ret;
    }
}
