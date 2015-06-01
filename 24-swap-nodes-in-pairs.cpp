/*
  Source : https://leetcode.com/problems/swap-nodes-in-pairs/
  Author : Alex Xu
  Date   : June 01, 2015
  Problem:
  Given a linked list, swap every two adjacent nodes and return its head.

  For example,
  Given 1->2->3->4, you should return the list as 2->1->4->3.

  Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    /* solution with two linked list: the odd list and the even list
     */
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        // get the odd and even list
        ListNode* odd = head;
        ListNode* even = odd->next;
        ListNode* pOdd = odd;
        ListNode* pEven = even;
        while (pEven != nullptr) {
            pOdd->next = pEven->next;
            pOdd = pOdd->next;
            if (pOdd == nullptr)
                break;
            
            pEven->next = pOdd->next;
            pEven = pEven->next;
        }
        if (pOdd == nullptr)
            pEven->next = nullptr;
        if (pEven == nullptr)
            pOdd->next = nullptr;

        // construct linked list with even and odd lists
        ListNode dummyNode(-1);
        ListNode* p = &dummyNode;
        while (even != nullptr) {
            p->next = even;
            p = p->next;
            even = even->next;
            
            p->next = odd;
            p = p->next;
            odd = odd->next;
        }
        // note that the last node of odd can be NOT nullptr
        if (odd != nullptr) {
            p->next = odd;
            p = p->next;
            p->next = nullptr;
        }
        
        return dummyNode.next;
    }
};
