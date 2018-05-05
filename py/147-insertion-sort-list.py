"""
 Source : https://oj.leetcode.com/problems/insertion-sort-list/
 Author : Alex Xu
 Date   : Apr 30, 2015
 Problem: Sort a linked list using insertion sort.
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return None
        
        dummy = ListNode(0)
        dummy.next, head = head, head.next
        dummy.next.next = None
        
        while head:
            head = self.insert_to_sorted_list(dummy, head)
            
        return dummy.next
    
    def insert_to_sorted_list(self, dummy, node):
        current = dummy
        
        while current.next and current.next.val < node.val:
            current = current.next
        
        current.next, node.next, node = node, current.next, node.next
        
        return node
