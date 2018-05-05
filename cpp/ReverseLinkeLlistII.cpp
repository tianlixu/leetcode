/*
 Source : https://leetcode.com/problems/reverse-linked-list-ii/
 Author : Alex Xu
 Date   : March 10, 2015
 Problem: 
 Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
         if (head == NULL || head->next == NULL || m == n)
            return head;
        // head1...tail1 -> head2....tail2 -> head3....tail3
        // head1->....->tail1  head2<-....<-tail2  head3->...->tail3
        
        
        int count = 1;
        ListNode *prev = NULL; // prev
        ListNode *curr = head; // curr
        
        while (count < m) {
            prev = curr;
            curr = curr->next;
            ++ count;
        }
        
        ListNode *tail1 = prev;
        ListNode *head2 = curr;
        
        ListNode *next = NULL; // next
        while (count <= n) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            ++ count;
        }
        
        ListNode *tail2 = prev;
        ListNode *head3 = curr;
        
        if (tail1 != NULL)
            tail1->next = tail2;
        head2->next = head3;
    
        if (m == 1)
            head = tail2;
            
        return head;
    }
};
