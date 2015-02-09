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
    void reorderList(ListNode *head) {
        if (head == NULL)
            return;
        
        // find tail
        ListNode *pA = head;
        int length = 1;
        while(pA->next != NULL) {
            pA = pA->next;
            ++ length;
        }
        
        // only 1 or 2 nodes, just return
        if (length <= 2)
            return;
            
        // get the first node pos(0 based) of the 2nd half
        int pos = length/2 + length%2;
        ListNode *pB = head;
        // get the head of 2nd half
        while(pos > 1) {
            pB = pB->next;
            -- pos;
        }
        ListNode *tail = pB;
        pB = pB->next;
        tail->next = NULL;
            
        pA = head;
        pB = reverseList(pB);
        while (pB != NULL) {
            ListNode *nodeB = pB->next;
            pB->next = pA->next;
            pA->next = pB;
            pA = pB->next;
            pB = nodeB;
        }
    }
private:
    ListNode* reverseList(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
            
        ListNode *prev = NULL;
        ListNode *next = head->next;
        while (1) {
            head->next = prev;
            if (next == NULL)
                break;
            prev = head;
            head = next;
            next = next->next;
        }
        
        return head;
    }
};
