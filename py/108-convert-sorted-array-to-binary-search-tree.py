"""
  Source : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
  Author : Alex Xu
  Date   : May 24, 2018
  Problem: Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
"""


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# beats 98.35
class Solution:
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if nums is None:
            return None
        if len(nums) == 0:
            return None
        if len(nums) == 1:
            return TreeNode(nums[0])
        
        middle_index = len(nums) // 2
        middle_value = nums[middle_index]
        root = TreeNode(middle_value)
        root.left = self.sortedArrayToBST(nums[ : middle_index])
        root.right = self.sortedArrayToBST(nums[middle_index + 1 : ])
        
        return root
