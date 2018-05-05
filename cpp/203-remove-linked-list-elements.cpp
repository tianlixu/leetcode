/*
  Source : https://leetcode.com/problems/merge-two-sorted-lists/
  Author : Alex Xu
  Date   : May 28, 2015
  Problem:
  Remove all elements from a linked list of integers that have value val.

  Example
  Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
  Return: 1 --> 2 --> 3 --> 4 --> 5
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
    /// recursive solution
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
            return nullptr;
        
        if (head->val == val) {
            // ignore head, and remove from the rest(head->next)
            return removeElements(head->next, val);
        } else {
            // keep the head, and remove from the rest(head->next, and reconstruct head->next)
            head->next = removeElements(head->next, val);
            return head;
        }
    }
    
    /// iterative solution
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
            return nullptr;
        
        // move head to the first node whose value is not val
        while (head->val == val) {
            head = head->next;
            if (head == nullptr) // to the end, then return nullptr
                return nullptr;
        }
        
        ListNode* pre = head;
        ListNode* cur = pre->next;
        /*
         *  1  ->   2   -> 3 -> ... ->nullptr
         *  |pre    |cur
         */
        while (cur != nullptr) {
            if (cur->val == val)
                pre->next = cur->next;
            else
                pre = cur;

            cur = cur->next;
        }
        
        return head;
    }
};
