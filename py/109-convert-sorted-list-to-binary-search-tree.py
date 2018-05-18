"""
  Source : https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
  Author : Alex Xu
  Date   : May 18, 2018
  Problem: Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
  For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

  Example:
  Given the sorted linked list: [-10,-3,0,5,9],
  One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

"""
 Recursive solution that beats 99.51%:
 1. Find the middle node of the list as root
 2. Find the middle node of the left sub list as root.left
 3. Find the middle node of the right sub list as root.right
"""
class Solution:
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        if head is None:
            return None
        
        if head.next is None:
            return TreeNode(head.val)
        
        pre = None
        one = head
        two = head
        while (two is not None and two.next is not None):
            pre, one, two = one, one.next, two.next.next
        pre.next = None
        
        node = TreeNode(one.val)
        node.left = self.sortedListToBST(head)
        node.right = self.sortedListToBST(one.next)
        
        return node
