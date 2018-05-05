"""
  Source : https://leetcode.com/problems/binary-tree-inorder-traversal/
  Author : Alex Xu
  Date   : May 21, 2015
  Problem:

  Given a binary tree, return the inorder traversal of its nodes' values.

  For example:
  Given binary tree {1,#,2,3},
  1
   \
   2
  /
  3
  return [1,3,2].

  Note: Recursive solution is trivial, could you do it iteratively?


                        1
                       / \
                      2  3
                     / \
                    4   5
Depth First Traversals:
(a) Inorder L-V-R(Left, Root, Right): 4 2 5 1 3
(b) Preorder V-L-R(Root, Left, Right): 1 2 4 5 3
(c) Postorder L-R-V(Left, Right, Root): 4 5 2 3 1

Breadth First or Level Order Traversal: 1 2 3 4 5

"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        values = []
        self.inorder(root, values)
        return values
    
    def inorder(self, root, values):
        """
        :type root: TreeNode
        :type values: List[int]
        :rtype: void
        """
        if not root:
            return
        
        self.inorder(root.left, values)
        values.append(root.val)
        self.inorder(root.right, values)

# iterative solution
class Solution:
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

