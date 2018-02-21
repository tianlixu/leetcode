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
        Recursive solution
        :type root: TreeNode
        :rtype: TreeNode
        """
        if not root:
            return root

        # swap left and rigth with multiple assignments
        root.left, root.right = self.invertTree(root.right), self.invertTree(root.left)
        
        return root

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def invertTree(self, root):
        """
        Iterative solution
        :type root: TreeNode
        :rtype: TreeNode
        """
        if not root:
            return root
        
        l = [root]
        while l:
            node = l.pop()

            # swap node.left and node.right with multiple assignments
            node.left, node.right = node.right, node.left
            
            if node.left is not None:
                l.append(node.left)
            if node.right is not None:
                l.append(node.right)
       
        return root
