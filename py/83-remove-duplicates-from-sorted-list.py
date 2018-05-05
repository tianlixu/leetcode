"""
  Source : https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list
  Author : Alex Xu
  Date   : may 01, 2018
  Problem:
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

this solution beats 100%
class Solution:
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        
        if head is None or head.next is None:
            return head
        
        dummy = ListNode(0)
        dummy.next, tail, head = head, head, head.next
        while head:
            if head.val != tail.val:
                tail.next = head
                tail = tail.next
            head = head.next
        tail.next = None
        
        return dummy.next

# this solution beats 81%
class Solution:
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head and head.next:
            while head.next and head.val == head.next.val:
                head = head.next
            head.next = self.deleteDuplicates(head.next)
        
        return head
