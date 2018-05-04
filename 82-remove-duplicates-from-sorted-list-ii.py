"""
 Source : https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
 Author : Alex Xu
 Date   : May 04, 2018
 Problem:
 Given a sorted linked list, delete all nodes that have duplicate numbers,
 leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(0)
        tail = dummy

        while head:
            if head.next and head.next.val == head.val:
                head = self.delete_duplicates_from_head(head)
            else:
                tail.next, head = head, head.next
                tail = tail.next
        tail.next = None

        return dummy.next

    def delete_duplicates_from_head(self, head):
        """
        Remove first duplicates from head
        Stops whenever it reches the one that has a different value
        """
        value, head = head.val, head.next
        while head and head.val == value:
            head = head.next

        return head
