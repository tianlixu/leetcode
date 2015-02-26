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
