"""
  Source : https://oj.leetcode.com/problems/reorder-list
  Author : Alex Xu
  Date   : may 01, 2018
  Problem:
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: void Do not return anything, modify head in-place instead.
        """
        if head and head.next and head.next.next:
            # break list into two lists from the middle
            head2 = self.break_list(head)
            # revert the 2nd list
            head2 = self.revert_list(head2)
            # merge two lists
            head = self.merge_list(head, head2)
    
    
    def break_list(self, head):
        one = head # step one node
        two = head # step two nodes
        tail = None # tail of the 1st list
        
        while two and two.next:
            tail, one, two = one, one.next, two.next.next
        tail.next = None
        
        return one
    
    
    def revert_list(self, head):
        dummy = ListNode(0)
        while head:
            dummy.next, head.next, head = head, dummy.next, head.next
            
        return dummy.next
    
    
    def merge_list(self, head1, head2):
        dummy = ListNode(0)
        tail = dummy
        
        while head1 and head2:
            tail.next, head1 = head1, head1.next, 
            tail = tail.next
            tail.next, head2 = head2, head2.next
            tail = tail.next
        tail.next = head1 or head2
        
        return dummy.next
    
