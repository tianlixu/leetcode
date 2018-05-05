/*
  Source : https://leetcode.com/problems/linked-list-cycle-ii/
  Author : Alex Xu
  Date   : May 30, 2015
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
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return nullptr;
        
        // pointer to step forward one step
        ListNode *one = head;
        // pointer to step forward two steps
        ListNode *two = head;
        
        while (true) {
            if (two == nullptr || two->next == nullptr)
                return nullptr;
            
            two = two->next->next;
            one = one->next;
            
            if (two == one)
                break;
        }
            
        one = head;
        while (one != two ) {
            one = one->next;
            two = two->next;
        }
        
        return one; // or return two
    }
};
