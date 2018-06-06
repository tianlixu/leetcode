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
 * Runtime: 51ms, beats 96.85%
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        int carry = 0;
        int sum = 0;

        while(l1 != null || l2 != null || carry != 0) {
            sum = (l1 != null ? l1.val : 0) + (l2 != null ? l2.val : 0) + carry;
            carry = sum / 10;

            ListNode node = new ListNode(sum % 10);
            tail.next = node;
            tail = tail.next;

            l1 = l1 != null ? l1.next : null;
            l2 = l2 != null ? l2.next : null;
        }

        return dummy.next;
    }
}


/*
Solution 2: Recursive, Runtime 63ms, beats 66.20%
**/
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        return addTwoNumbers(l1, l2, 0);
    }
    
    public ListNode addTwoNumbers(ListNode l1, ListNode l2, int carry) {
        if (l1 == null && l2 == null && carry == 0) {
            return null;
        }
        
        int sum = (l1 != null ? l1.val : 0) + (l2 != null ? l2.val : 0) + carry;
        carry = sum / 10;

        ListNode head = new ListNode(sum % 10);
        l1 = l1 != null ? l1.next : null;
        l2 = l2 != null ? l2.next : null;
        head.next = addTwoNumbers(l1, l2, carry);

        return head;
    }
}

/*
  Variation of Solution 2.
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        return addTwoNumbers(l1, l2, 0);
    }
    
    public ListNode addTwoNumbers(ListNode l1, ListNode l2, int carry) {
        if (l1 == null) {
            return addTwoNumbers(l2, carry);
        } 
        
        if (l2 == null) {
            return addTwoNumbers(l1, carry);
        }

        
        int sum =  l1.val + l2.val + carry;
        ListNode head = new ListNode(sum % 10);
        head.next = addTwoNumbers(l1.next, l2.next, sum / 10);

        return head;
    }
    
    public ListNode addTwoNumbers(ListNode l, int carry) {
        if (carry == 0) {
            return l;
        }
        if (l == null) {
            return new ListNode(carry);
        }
        
        int sum = l.val + carry;
        ListNode head = new ListNode(sum % 10);
        head.next = addTwoNumbers(l.next, sum / 10);
        
        return head;
    }
}
