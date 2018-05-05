"""
 Source : https://leetcode.com/problems/remove-nth-node-from-end-of-list/ 
 Author : Alex Xu
 Date   : May 04, 2018
 Problem:
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
"""
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        # sliding window
        left = head
        right = head
        
        # initialize window
        while n > 0:
            right, n = right.next, n-1
        # right reaches the end
        if not right:
            head = head.next
        
        else:
            # moving window
            while right.next:
                left, right = left.next, right.next
            #remove node pointed by left
            left.next = left.next.next
        
        return head

