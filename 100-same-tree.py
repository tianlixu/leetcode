"""
 Source : https://leetcode.com/problems/same-tree/
 Author : Alex Xu
 Date   : Feb 28, 2018
 
 Problem:
 Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        if not p and not q:
            return True
        
        if not p or not q:
            return False
        
        return p.val == q.val and self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)

"""
convert the tree to an array of numbers then compare the array
Note: leaf node will be save as [leaf_node.val, '/', '/'], e.g.
    tree [1, 0] -> [1, 0, '/', '/', '/']
while 
    tree [1, null] -> [1, '/', '/']
"""
class Solution:
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        return self.treeToArray(p) == self.treeToArray(q)
    
    def treeToArray(self, root):
        """
        :type root: root TreeNode
        :rtype: []
        """
        ret = []
        if root:
            ret.append(root.val)
            ret += self.treeToArray(root.left)
            ret += self.treeToArray(root.right)
        else:
            ret.append('/')
        
        return ret

"""
Solution 3: using stack/queue for dfs/bfs
"""    
