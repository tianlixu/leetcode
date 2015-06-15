/*
 Source : https://leetcode.com/problems/intersection-of-two-linked-lists/
 Author : Alex Xu
 Date   : Feb 09, 2015
 Problem: 
 
 Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLengthOfList(headA);
        int lenB = getLengthOfList(headB);

        // move forward diff steps in the longer list
        int diff = abs(lenA - lenB);
        while (diff--)
        if (lenA > lenB)
            headA = headA->next;
        else
            headB = headB->next;
            
        return getIntersectionNodeWithEqualLength(headA, headB);
    }

    /*
     * get the intersection node in the two lists which have the same length
     */
    ListNode* getIntersectionNodeWithEqualLength(ListNode *headA, ListNode *headB) {
        while (headA != nullptr) {
            if (headA == headB)
                return headA;
            
            headA = headA->next;
            headB = headB->next;
        }
        
        return nullptr;
    }        

    /*
     * return the number of nodes in the list
     */
    int getLengthOfList(ListNode* head) {
        int length = 0;
        while (head != nullptr) {
            length ++;
            head = head->next;
        }
        
        return length;
    }
};
