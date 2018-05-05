/*
  Source : https://leetcode.com/problems/merge-two-sorted-lists/
  Author : Alex Xu
  Date   : May 28, 2015
  Problem:
  Given a list, rotate the list to the right by k places, where k is non-negative.

  For example:
  Given 1->2->3->4->5->NULL and k = 2,
  return 4->5->1->2->3->NULL.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;
        
        // get length and tail
        ListNode* tail = head;
        int length = 1;
        while (tail->next != nullptr) {
            length ++;
            tail = tail->next;
        }
        
        k = k % length;
        if (k == 0)
            return head;       
        
        // calculate the steps for head to move forward
        int step = length - k - 1; // 1 for head node
        
        // make it a circle
        tail->next = head;
        
        // move head forward
        while (step-- > 0)
            head = head->next;
       
        // cut the circle 
        tail = head;
        head = head->next;
        tail->next = nullptr;
        
        return head;
    }
};

