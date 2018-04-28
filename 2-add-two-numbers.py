"""
  Source : https://oj.leetcode.com/problems/add-two-numbers/
  Author : Alex Xu
  Date   : April 27, 2018
  Problem:

  You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
  Output: 7 -> 0 -> 8


 l1: n1 -> n2 -> n3 -> n4 -> ... -> n
     +     +     +     +      +
 l2: m1 -> m2 -> m3 -> m4 -> ... -> mn -> ... -> m
                    +
                   extra
     ||    ||    ||    ||     ||    ||    ||     ||
     s1 -> s2 -> s3 -> s4 -> ... -> sn -> ... -> sm

"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = 0
        head = ListNode(0)
        node = head
        while l1 or l2 or carry:
            v1 = 0
            v2 = 0
            
            if l1:
                v1 = l1.val
                l1 = l1.next
            if l2:
                v2 = l2.val
                l2 = l2.next
            
            carry, val = divmod(v1 + v2 + carry, 10)
            node.next = ListNode(val)
            node = node.next
        
        return head.next
