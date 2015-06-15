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
     * Recursive solution
     */
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
            
        if (head->val == head->next->val) {
            return deleteDuplicates(head->next->next, head->val);
        } else {
            head->next = deleteDuplicates(head->next);
            return head;
        }
    }
    
    ListNode* deleteDuplicates(ListNode* head, int val) {
        if (head == nullptr)
            return nullptr;
            
        if (head->val == val)
            return deleteDuplicates(head->next, val);
        else
            return deleteDuplicates(head);
    }
    
public:
    /*
     * Iterative solution
     */
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

            // remove the node q
            q = q->next;
            delete p->next;
            p->next = q;
        }
        
        return head;
    }
};
