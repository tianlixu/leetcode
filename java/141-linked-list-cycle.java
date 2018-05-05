/*
  Source : https://leetcode.com/problems/linked-list-cycle/
  Author : Alex Xu
  Date   : May 30, 2015
  Problem:
  Given a linked list, determine if it has a cycle in it.

  Follow up:
  Can you solve it without using extra space?
*/
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode one = head;
        ListNode two = head;

        while(two != null && two.next != null) {
            one = one.next;
            two = two.next.next;

            if (two == one) {
                return true;
            }
        }

        return false;
    }
}
