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
};
