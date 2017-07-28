/*
  Source : https://oj.leetcode.com/problems/add-two-numbers/
  Author : Alex Xu
  Date   : Jan 10, 2015
  Problem:

  You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
  Output: 7 -> 0 -> 8

  BTW: this is the worst example ever!!!! Because 243+564 = 342+465.
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
 * l1: n1 -> n2 -> n3 -> n4 -> ... -> n
 *     +     +     +     +      +
 * l2: m1 -> m2 -> m3 -> m4 -> ... -> mn -> ... -> m
 *                    +
 *                   extra
 *     ||    ||    ||    ||     ||    ||    ||     ||
 *     s1 -> s2 -> s3 -> s4 -> ... -> sn -> ... -> sm
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode headNode = new ListNode(0);
        ListNode p = headNode;
        int extra = 0;
        int sum = 0;

        while(l1 != null || l2 != null || extra != 0) {
            sum = (l1 != null ? l1.val : 0) + (l2 != null ? l2.val : 0) + extra;
            extra = sum / 10;

            ListNode n = new ListNode(sum%10);
            p.next =n;
            p = p.next;

            l1 = l1 != null ? l1.next : null;
            l2 = l2 != null ? l2.next : null;
        }

        return headNode.next;

    }
}
