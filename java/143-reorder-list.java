/*
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
*/
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */


/**
 * runtime: 4ms, beat 96.2%
 * A very good solution for runtime
 * Time O(n), Space O(1)
 */
class Solution {
    public void reorderList(ListNode head) {       
        if (head == null || head.next == null || head.next.next == null) {
            return;
        }
        
        // break list into two
        ListNode head2 = breakList(head);
                
        // revert the 2nd list
        head2 = revertList(head2);
        
        // merge the two lists
        head = mergeLists(head, head2);
    }

    // break list into two lists from middle and return the 2nd one
    public ListNode breakList(ListNode head) {
        ListNode one = head;
        ListNode two = head;
        ListNode pre = null;
        
        while (two != null && two.next != null) {
            pre = one;
            one = one.next;
            two = two.next.next;
        }        
        pre.next = null;
        
        return one;
    }

    // l0 -> l1 -> ... -> ln ==> ln -> ln-1 -> ... -> l1 -> l0, refer to problem #206
    public ListNode revertList(ListNode head) {
        ListNode dummy = new ListNode(0);
        ListNode next = null;
        
        while(head != null) {
            next = head.next;
            head.next = dummy.next;
            dummy.next = head;
            head = next;
        }
        
        return dummy.next;
    }
    
    public ListNode mergeLists(ListNode h1, ListNode h2) {
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        
        while (h1 != null && h2 != null) {
            tail.next = h1;
            h1 = h1.next;
            tail = tail.next;
            
            tail.next = h2;
            h2 = h2.next;
            tail = tail.next;
        }
        
        tail.next = (h1 == null) ? h2 : h1;
        
        return dummy.next;
    }
}

/*
 * The recursive solution is quite straightforward, but runtime is very long: 893ms!!!
 */
class Solution {
    public void reorderList(ListNode head) {       
        recursiveReorderList(head);
    }
    
    public ListNode recursiveReorderList(ListNode head) {
        if (head == null || head.next == null || head.next.next == null) {
            return head;
        }
        
        ListNode tail = cutTailNode(head);
        tail.next = recursiveReorderList(head.next);
        head.next = tail;
        
        return head;
    }
    
    public ListNode cutTailNode(ListNode head) {
        ListNode tail = head;
        ListNode pre = null;
        
        while (tail.next != null) {
            pre = tail;
            tail = tail.next;
        }        
        pre.next = null;
        
        return tail;
    }
}
