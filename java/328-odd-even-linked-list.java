/**
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
    public ListNode oddEvenList(ListNode head) {
        ListNode dummy_1st = new ListNode(0);
        ListNode tail_1st = dummy_1st;
        ListNode dummy_2nd = new ListNode(0);
        ListNode tail_2nd = dummy_2nd;

        while(head != null) {
            tail_1st.next = head;
            tail_1st = tail_1st.next;
            head = head.next;
            if (head != null) {
                tail_2nd.next = head;
                tail_2nd = tail_2nd.next;
                head = head.next;
            }
        }
        tail_1st.next = dummy_2nd.next;
        tail_2nd.next = null;

        return dummy_1st.next;
    }
}
