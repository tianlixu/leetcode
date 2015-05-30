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
    // Time： O(n)
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return false;
        
        // pointer to step forward one step
        ListNode *one = head;
        // pointer to step forward two steps
        ListNode *two = head;
        
        while (two != nullptr) {
            two = two->next;
            if (two == nullptr)
                return false;
            
            two = two->next;
            if (two == nullptr)
                return false;
            
            one = one->next;
            
            if (two == one)
                return true;
        }
        
        return false;
    }
    
    // Time: O(n)
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

    // Time: O(n^2)
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return false;
        
        ListNode* p1 = head->next;
        while (p1 != nullptr) {
            ListNode* p2 = head;
            while (p2 != nullptr) {
                if (p2 == p1->next)
                    return true;                
                if (p2 == p1)
                    break;
                p2 = p2->next;
            }
            p1 = p1->next;
        }
        
        return false;
    }
};
