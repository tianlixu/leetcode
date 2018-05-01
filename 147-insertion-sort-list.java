/*
 Source : https://oj.leetcode.com/problems/insertion-sort-list/
 Author : Alex Xu
 Date   : May 01, 2018
 Problem: Sort a linked list using insertion sort.
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

class Solution {
    public ListNode insertionSortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        // using a dummy node makes insertion much easier
        ListNode dummy = new ListNode(0);
        // head.next, the next node in the original list to be processed
        ListNode next = null;
        
        while(head != null) {
            // save head.next since head will be relinked during insertion
            next = head.next;
            dummy.next = insertNodeToSortList(dummy, head);
            head = next;
        }
        
        return dummy.next;
    }
    
    public ListNode insertNodeToSortList(ListNode dummy, ListNode node) {
        ListNode current = dummy;
        
        while (current.next != null && current.next.val < node.val) {
            current = current.next;
        }
        
        node.next = current.next;
        current.next = node;

        return dummy.next;
    }
}


class Solution2 {
    public ListNode insertionSortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        
        // the list starting with head.next is now sorted
        // this is not in the order as descriped in the problem
        // but it resloves the problem.
        head.next = insertionSortList(head.next);
        
        // move head to the proper position
         return moveHeadNode(head);
    }
    
    public ListNode moveHeadNode(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        
        if (head.val < head.next.val) {
            return head;
        }
        
        ListNode next = head.next;
        head.next = next.next;
        next.next = moveHeadNode(head);
        
        return next;
    }
}
