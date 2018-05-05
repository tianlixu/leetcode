/*
  Source : https://oj.leetcode.com/problems/sort-list/
  Author : Alex Xu
  Date   : Mar 04, 2015
  Problem:
  Sort a linked list in O(n log n) time using constant space complexity.

  Solution: MergeSort list.
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
    /*
     * Merge Sort:
     * 1) break the current list into two lists: L and R
     * 2) sort L, and sort R
     * 3) merge L and R
     */
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode * middle = getMiddleNode(head);
        ListNode * headR = NULL;
        if (middle != NULL) {
            headR = middle->next;
            middle->next = NULL;
        }

        ListNode *headL = sortList(head);
        headR = sortList(headR);
        head = merge(headL, headR);

        return head;
    }


    /*
      @ 21-merge-two-sorted-lists.cpp for more solutions to merge two sorted lists
    */
    ListNode *merge(ListNode *headL, ListNode *headR) {
        if (headL == NULL)
            return headR;
        if (headR == NULL)
            return headL;

        if (headL->val > headR->val)
            std::swap(headL, headR);

        ListNode *head = headL; // make headL the head
        headL = headL->next;

        ListNode *current = head;
        // link left list (headL) and right list(headR) to head
        while (true) {
            if (headL == NULL) {
                current->next = headR;
                break;
            }

            if (headR == NULL) {
                current->next = headL;
                break;
            }
            if (headL->val <= headR->val) {
                current->next = headL;
                current = headL;
                headL = headL->next;
            } else {
                current->next = headR;
                current = headR;
                headR = headR->next;
            }
        }

        return head;
    }

    ListNode *getMiddleNode(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
            
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next; // step 1
            fast = fast->next->next;
        }

        return slow;
    }
};
