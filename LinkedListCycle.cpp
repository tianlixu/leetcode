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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return false;
        
        // pointer to step forward one step
        ListNode *one = head;
        // pointer to step forward two steps
        ListNode *two = head->next;
        
        while (one != two) {
            one = one->next;
            
            two = two->next;
            if (two == NULL)
                return false;
                
            two = two->next;
            if (two == NULL)
                return false;
        }
        
        return true;
    }
};
