"""
  Source : https://oj.leetcode.com/problems/sort-list/
  Author : Alex Xu
  Date   : Apr 30, 2018
  Problem:
  Sort a linked list in O(n log n) time using constant space complexity.

  Solution: MergeSort list.
  Note recursion is not using constant space, will enhance it later!
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        
        l1, l2 = self.break_list(head)
        l1 = self.sortList(l1)
        l2 = self.sortList(l2)
        return self.merge_sorted_list(l1, l2)
        
    def break_list(self, head):      
        pre, slow, fast = None, head, head
        
        while fast and fast.next:
            pre, slow, fast = slow, slow.next, fast.next.next
        pre.next = None
        
        return (head, slow)
    
    def merge_sorted_list(self, l1, l2):
        dummy = ListNode(0)
        tail = dummy
    
        while l1 and l2:
            if l1.val < l2.val:
                tail.next, tail, l1 = l1, l1, l1.next
            else:
                tail.next, tail, l2 = l2, l2, l2.next
        tail.next = l1 or l2
    
        return dummy.next
