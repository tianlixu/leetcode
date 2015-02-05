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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p1 = head;
        ListNode *p2 = head;
        
        while (n>0) {
            p2 = p2->next;
            -- n;
        }
        if (p2 == NULL) {
            head = head->next;
            return head;
        }
        
        while (p2->next != NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = p1->next->next;
        
        return head;
    }
};
