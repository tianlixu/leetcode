/*
  Source : https://oj.leetcode.com/problems/palindrome-linked-list
  Author : Alex Xu
  Date   : Jun 11, 2018
  Problem: Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?

*/

/* 
 Solution: Runtime 1ms, beats 99.77%, Time: O(n), Space: O(1)
 break list into two lists using one/two pointers to step forward and find the middle node
 reverse the fist node during the find process
 compare the two lists
 refer to #143
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
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) {
            return true;
        }
        
        ListNode one = head;
        ListNode two = head;
        ListNode dummy = new ListNode(0);
        
        while (true) {
            // move two first because head(one) is modified in the next section
            two = two.next.next;
            
            ListNode oneNext = one.next;
            one.next = dummy.next;
            dummy.next = one;
            one = oneNext;
            
            if (two == null) { // even number of nodes, one is now the head of 2nd list
                break;
            }
            
            if (two.next == null) { // odd number of nodes, one is now the middle node, one.next is the head of 2nd list
                one = one.next;
                break;
            }
        }
        
        two = dummy.next;
        // two is the 1st half list, which has alread been reverted
        // one is the 2nd half list, one and two have the same length
        while (one != null) {
            if (one.val != two.val) {
                return false;
            }
            one = one.next;
            two = two.next;
        }
        
        return true;
    }
}
