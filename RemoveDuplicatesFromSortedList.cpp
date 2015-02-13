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
        
        ListNode *p = head;
        ListNode *q = p->next;
        
        while (q != NULL) {
            if (p->val != q->val) {
                p = p->next;
                q = q->next;
                continue;
            }
            
            q = q->next;
            delete p->next;
            p->next = q;
        }
        
        return head;
    }
};
