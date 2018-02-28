"""
  Source : https://leetcode.com/problems/path-sum-ii/
  Author : Alex Xu
  Date   : Mar 16, 2015
 
  Problem:
  Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

  For example:
  Given the below binary tree and sum = 22,
   5
  / \
  4   8
  /   / \
  11  13  4
  /  \    / \
  7    2  5   1
  return
  [
  [5,4,11,2],
  [5,8,4,5]
  ]
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        paths = []
        
        if not root:
            return paths
        
        if root.left is None and root.right is None:
            if sum == root.val:
                # found one path, create the path with leaf node's value
                path = [root.val]
                paths.insert(0, path)
            return paths
        
        # search from left and right sub tree
        paths = self.pathSum(root.left, sum - root.val) + self.pathSum(root.right, sum - root.val)
        if paths:
            for path in paths:
                path.insert(0, root.val)
                
        return paths
