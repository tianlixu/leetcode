/*
 Source : https://oj.leetcode.com/problems/insertion-sort-list/
 Author : Alex Xu
 Date   : Feb 26, 2015
 Problem: Sort a linked list using insertion sort.
*/

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *head) {
    while (head != NULL) {
        cout << head->val << "->";
        head = head->next;
    }
    cout <<"null" << endl;
}

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        /// recursive solution
        if (head == NULL || head->next == NULL)
            return head;

        /// 3,   1, 5, 2, 4
        head->next = insertionSortList(head->next);

        ListNode *p = NULL; // previous
        ListNode *c = head->next; // current
        /// 3, 1, 2(p), 4(c), 5
        while (c != NULL && c->val < head->val) {
            p = c;
            c = c->next;
        }
        if (p != NULL) {// need sort
            ListNode *newHead = head->next;
            head->next = p->next;
            p->next = head;
            head = newHead;
        }

        return head;
    }
};

int main()
{
    Solution s;

    ListNode head(2);
    ListNode n1(1);
    ListNode n2(4);
    ListNode n3(3);
    head.next = &n1;
    n1.next = &n2;
    n2.next = &n3;

    printList(&head);
    ListNode *newHead = s.insertionSortList(&head);
    printList(newHead);

    return 0;
}
