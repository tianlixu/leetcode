/*
  Source : https://leetcode.com/problems/linked-list-cycle-ii/
  Author : Alex Xu
  Date   : July 31, 2017
  Problem:
  Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

  Follow up:
  Can you solve it without using extra space?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


/*
*                     /-->--C----\
*                    /            \
 * A-------->-------B             |
 *                   \            /
 *                    \----<-----/
 * meet at C
 * Distance: A->B: x
 * Distance: B->C: y
 * Circle: B->C->B: c
 *
 * then:
 *       the distance for one: x+y
 *       the distance for two: x + k*c + y      // k = 1, 2, 3.....
 *
 *       2*(x+y) = x + k*c + y
 *  ==>  x + y = k*c
 *  ==>  x = k*c - y
 *
 * Conclusion: if p1 moves(one step each time) from A to B,
 *             and p2 moves(one step each time) x steps from C,
 *             then p1 will meet p2 at B. 
 */
class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode one = head;
        ListNode two = head;

        while(true) {
            if (two == null || two.next == null) {
                return null;
            }

            one = one.next;
            two = two.next.next; // step forward two steps

            if (two == one) {
                break;
            }
        }

        one = head;
        while (one != two ) {
            one = one.next;
            two = two.next; // step forward one step
        }

        return one; // or return two
    }
};
