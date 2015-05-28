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
    /// iterative solution
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return;
            
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

    /// Recursive solution
    ListNode* reverseList(ListNode* head) {
        // Exit condition
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* next = head->next;
        ListNode* newHead = reverseList(next);
        // Statement
        next->next = head;
        head->next = nullptr;
        
        return newHead;
    }
    
    /// solution with a stack, costing more space, Time: O(n), Space: O(n)
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return nullptr;

        // push nodes to a stack
        std::stack<ListNode*> stk;
        while (head != nullptr) {
            stk.push(head);
            head = head->next;
        }

        /// puop nodes to recreate the linked list
        head = stk.top();
        stk.pop();
        
        ListNode* p = head;
        while (!stk.empty()) {
            ListNode* node = stk.top();
            p->next = node;
            p = node;
            stk.pop();
        }
        p->next = nullptr;
        
        return head;
    }
};
