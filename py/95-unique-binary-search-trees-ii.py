"""
  Source : https://leetcode.com/problems/unique-binary-search-trees-ii/description/
  Author : Alex Xu
  Date   : May 25, 2018
  Problem: Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
"""
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        if n <= 0:
            return []
        return self.generateBST(1, n)
    
    def generateBST(self, n1, n2):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        root_list = []
        
        if n1 > n2:
            root_list.append(None)
        elif n1 == n2:
            root_list.append(TreeNode(n1))
        else:
            for n in range(n1, n2+1):
                left_list = self.generateBST(n1, n-1)
                right_list = self.generateBST(n+1, n2)
                
                for left in left_list:
                    for right in right_list:
                        root = TreeNode(n)
                        root.left = left
                        root.right = right
                        root_list.append(root)
        
        return root_list
