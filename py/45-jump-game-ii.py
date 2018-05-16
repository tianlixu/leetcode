"""
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
"""

"""
96 ms, beats 18%. not good.
"""
class Solution:
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        steps = 0
        start = 0
        end = 0
        
        while end < len(nums)-1:
            steps += 1
            start, end = self.nextWindow(nums, start, end)
        
        return steps
    
    def nextWindow(self, nums, start, end):
        """
        :type nus: List[int]
        :rtype: (int, int)
        """
        next_start = end + 1
        next_end = end + 1
        
        for index, value in enumerate(nums[start : end + 1]):
            next_end = max(next_end, start + value + index)
        
        print("next:", next_start, next_end)
        return (next_start, next_end)
