"""
 Source : https://oj.leetcode.com/problems/two-sum/
 Author : Alex Xu
 Date   : Jan 16, 2017
 Tag    : array, hashmap

 Given an array of integers, find two numbers such that they add up to a specific target number.

 The function twoSum should return indices of the two numbers such that they add up to the target,
 where index1 must be less than index2.
 Please note that your returned answers (both index1 and index2) are not zero-based.

 You may assume that each input would have exactly one solution.

 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1=1, index2=2
"""

class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        ret = []
        
        dic = {}
        for i in range(len(nums)):
            key = target - nums[i]
            
            if key in dic:
                ret = [dic[key], i]
                break
            else:
                dic[nums[i]] = i
        
        return ret
