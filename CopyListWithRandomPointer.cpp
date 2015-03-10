/*
 Source : https://leetcode.com/problems/copy-list-with-random-pointer/
 Author : Alex Xu
 Date   : March 10, 2015
 Problem: 
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 #inlcude <unordered_map>
 
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
            return NULL;
        
        RandomListNode dummy = RandomListNode(0);
        std::unordered_map<RandomListNode*, RandomListNode*> mapCopy; // map<origin, copy>
                
        // create the single linked list first without setting random pointer
        RandomListNode *p = head;
        RandomListNode *q = &dummy;
        while (p != NULL) {
            RandomListNode *node = new RandomListNode(p->label);
            q->next = node;
            
            // setting the map
            mapCopy[p] = node;
            
            p = p->next;
            q = node;
        }
        q->next = NULL;
        
        p = head;
        q = dummy.next;
        while (p != NULL) {
            q->random = mapCopy[p->random];

            p = p->next;
            q = q->next;
        }
        
        return dummy.next;
    }
};
