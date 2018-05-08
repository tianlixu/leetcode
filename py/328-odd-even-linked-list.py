"""
 Source : https://leetcode.com/problems/odd-even-linked-list/description/
 Author : Alex Xu
 Date   : May 08, 2018

 Problem: Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummy_1st = ListNode(0)
        tail_1st = dummy_1st
        dummy_2nd = ListNode(0)
        tail_2nd = dummy_2nd

        while head:
            tail_1st.next = head
            tail_1st = tail_1st.next
            head = head.next
            if head:
                tail_2nd.next = head
                tail_2nd = tail_2nd.next
                head = head.next

        tail_1st.next = dummy_2nd.next
        tail_2nd.next = None

        return dummy_1st.next

