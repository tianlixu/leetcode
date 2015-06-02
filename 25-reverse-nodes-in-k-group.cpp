/*
  Source : https://leetcode.com/problems/reverse-nodes-in-k-group/
  Author : Alex Xu
  Date   : June 01, 2015
  Problem:
  Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

  If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

  You may not alter the values in the nodes, only nodes itself may be changed.

  Only constant memory is allowed.

  For example,
  Given this linked list: 1->2->3->4->5

  For k = 2, you should return: 2->1->4->3->5

  For k = 3, you should return: 3->2->1->4->5
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0 || k == 1) 
            return head;
        
        ListNode* first = head;
        ListNode* last = head;
        ListNode* tail = nullptr;
        ListNode* nextFirst = nullptr;
        
        int count = 0;
        while (last != nullptr) {
            count ++;
            if (count % k == 0) {
                nextFirst = last->next;
                ListNode* newHead = reverse(first, last);
                
                if (tail != nullptr)
                    tail->next = last;
                tail = first;
                
                if (count == k)
                    head =newHead;
                    
                last = nextFirst;
                first = last;
            } else {
                last = last->next;
            }
        }

        return head;
    }
    
    ListNode* reverse(ListNode* head, ListNode* tail) {
        while (head != tail) {
            ListNode* next = head->next;
            head->next = tail->next;
            tail->next = head;
            
            head = next;
        }
        
        return tail;
    }
};
