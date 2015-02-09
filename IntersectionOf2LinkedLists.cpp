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
        int lenA = 0;
        int lenB = 0;
        ListNode *pA = headA;
        ListNode *pB = headB;
        
        // get length of A
        while (pA != NULL) {
            ++ lenA;
            pA = pA->next;
        }
        // get length of B
        while (pB != NULL) {
            ++ lenB;
            pB = pB->next;
        }
        
        // reset PA, PB
        pA = headA;
        pB = headB;
        // suppose len(pA) always >= len(pB)
        if (lenA < lenB) {
            std::swap(lenA, lenB);
            std::swap(pA, pB);
        }
        
        // move forward pA: (lenA -lenB) steps
        int diff = lenA - lenB;
        while (diff--)
            pA = pA->next;
        
        for(int i=0; i<lenB && pA != NULL; ++i) {
            if (pA == pB && pA != NULL)
                return pA;
            pA = pA->next;
            pB = pB->next;
        }
        
        return NULL;
    }
};
