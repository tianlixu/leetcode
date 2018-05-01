/*
  Source : https://oj.leetcode.com/problems/reorder-list
  Author : Alex Xu
  Date   : may 01, 2018
  Problem:

*/
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */


/*
 * The recursive solution is quite straightforward
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
