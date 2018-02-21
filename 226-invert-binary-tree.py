"""
  Source : https://leetcode.com/problems/invert-binary-tree/
  Author : Alex Xu
  Date   : Feb 21, 2018
  Problem:
  Invert a binary tree. That is to swap the left and right of each node.

       4
     /   \
    2     7
   /  \   / \
  1   3 6   9
  
  to
       4
     /   \
    7     2
   / \   / \
  9   6 3   1

You are here! 
Your runtime beats 100.00 % of python3 submissions. :O, Nobody is using Python3 in leetcode?!
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if not root:
            return root
        
        left = self.invertTree(root.left)
        right = self.invertTree(root.right)
        
        root.left = right
        root.right = left;
        
        return root;
