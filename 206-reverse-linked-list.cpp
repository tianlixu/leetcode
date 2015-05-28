/*
 Source : https://leetcode.com/problems/reverse-linked-list/
 Author : Alex Xu
 Date   : May 28, 2015
 Problem:
 Reverse a singly linked list.

 Hint:
 A linked list can be reversed either iteratively or recursively. Could you implement both?
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
            
        ListNode* pre = nullptr;
        ListNode* next = nullptr;
        do {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        } while (head != nullptr);
        
        return pre;
    }
};
