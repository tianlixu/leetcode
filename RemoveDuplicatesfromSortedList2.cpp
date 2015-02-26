/*
 Source : https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
 Author : Alex Xu
 Date   : Feb 26, 2015
 Problem:
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
    ListNode *deleteDuplicates(ListNode *head) {
        // recursive solution
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *p = head->next;
        while (p != NULL && head->val == p->val) {
            p = p->next;
        }
        
        if (head->next != p){ // 1(h), 1, 2(p)
            head = deleteDuplicates(p); // reset head
        } else { // 1(h), 2(p), 3
            head->next = deleteDuplicates(p); // relink head->next
        }

        return head;
    }

/*
Solution 2:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        
        ListNode *p = newHead;  // previous
        ListNode *c = p->next;  // current
        
        while (c->next != NULL) { 
            if (c->val != c->next->val) { 
                if (p->next == c) { // 1, 2, 3, 4, 5
                    p = c;
                } else {
                    p->next = c->next; // 1, 2, 3, 3, 3, 4
                }
            }
            
            c = c->next;
        }
        
        if (p->next != c)
            p->next = c->next;
        
        return  newHead->next;   
    }
*/
};

int main()
{
    Solution s;

    ListNode head(1);
    ListNode n1(3);
    ListNode n2(2);
    ListNode n3(2);
    head.next = &n1;
    n1.next = &n2;
    n2.next = &n3;

    printList(&head);
    ListNode *newHead = s.deleteDuplicates(&head);
    printList(newHead);

    return 0;
}
