/*
  Source : https://leetcode.com/problems/partition-list/
  Author : Alex Xu
  Date   : May 29, 2015
  Problem:
  Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

  You should preserve the original relative order of the nodes in each of the two partitions.

  For example,
  Given 1->4->3->2->5->2 and x = 3,
  return 1->2->2->4->3->5.
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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* dummyLeft = new ListNode(-1);
        ListNode* dummyRight = new ListNode(-1);
        ListNode* left = dummyLeft;
        ListNode* right = dummyRight;

        // partiate into two list(Left and Right)
        while (head != nullptr) {
            if (head->val < x) {
                left->next = head;
                left = left->next;
            } else {
                right->next = head;
                right = right->next;
            }
            head = head->next;
        }

        // link Left and Right
        left->next = dummyRight->next;
        right->next = nullptr;
        head = dummyLeft->next;
        
        return head;
    }
};
