"""
  Source : https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
  Author : Alex Xu
  Date   : Mar 31, 2018
  Problem:

Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
Note: There are at least two nodes in this BST.


Hint:
For a given node.val, the one that is next smaller is its left child (node.left and node.left does not have a right child) or its left child's right most child. (node.left.right.right......right).

For a given node.val, the one that is next bigger is its right child (node.right and node.right does not have a left child) or its right child's left most child. (node.right.left.left.......left).

"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        ret = sys.maxsize
        
        if (root.left):
            right_most = root.left
            while (right_most.right):
                right_most = right_most.right
            ret = min(ret, abs(root.val - right_most.val))
            ret = min(ret, self.getMinimumDifference(root.left))
        
        if (root.right):
            left_most = root.right
            while (left_most.left):
                left_most = left_most.left
            ret = min(ret, abs(root.val - left_most.val))
            ret = min(ret, self.getMinimumDifference(root.right))
        
        return ret

# in-order tranverse with 94, the minimum is the one in the differences between any two adjacent elements
class Solution:
    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        inorder_values = self.inorderTraversal(root)
        
        return self.getMinimumDifferenceBetweenAdjacentElements(inorder_values)
    
    def getMinimumDifferenceBetweenAdjacentElements(selt, alist):
        """
        :type alist: List[int]
        :rtype: int
        """
        diffs = [abs(alist[i] - alist[i-1]) for i in range(1, len(alist))]
        return min(diffs)
        
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        values = []

        if not root:
            return values
        
        stack = [] # stack for tuple (node, bool), the bool means if this node has been visited
        node = root
        visited = False
        stack.append((node, visited))        
            
        while stack:
            node, visited = stack.pop() # visit top
            
            if visited:
                values.append(node.val)
            else:
                # R->V->L to stack, LVR to visit
                # push R
                if node.right is not None:
                    stack.append((node.right, False))
                stack.append((node, True))
                if node.left is not None:
                    stack.append((node.left, False))
        
        return values
