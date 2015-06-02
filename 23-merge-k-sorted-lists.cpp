/*
  Source : https://leetcode.com/problems/merge-k-sorted-lists/
  Author : Alex Xu
  Date   : June 01, 2015
  Problem:
  Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

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
     * Devide and conquer, recursive
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
            
        if (lists.size() == 1) 
            return lists[0];
        
        ListNode *l1 = lists[0];
        ListNode *l2 = lists[1];
        
        // merge l1 & l2
        ListNode* head = mergeTwoLists(l1, l2);
        
        // erase[first,last) uses a supper ending pointer
        // be careful, here is begin() + 2, not begin() + 1 
        lists.erase(lists.begin(), lists.begin() + 2); 
        lists.push_back(head);
        
        return mergeKLists(lists);
    }

    /*
     * Devide and conquer, iterative
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
    
        if(n == 0)
            return nullptr;
        
        while(n >1)
        {
            int mid = (n+1)/2;
            for(int i=0; i < n/2; i++)
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            n = mid;
        }
        return lists[0];
    }    

public:    
    /*
     * iterative solution: O(n^2), causes TLE(Time Limit Exceeded)
     *
     * merge 1 and 2 to 12:    2n nodes
     * merge 12 and 3 to 123:     3n 
     * merge 123 and 4 to 1234:    4n
     * ...
     * merge 123...(k-1) and k to 1234...k:    kn
     *
     * Nodes = 2n + 3n + 4n + ... + kn = n(2+3+4+...+k) = n(k^2 + k - 2)/2
     *
     * Time = O(n*k^2)
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
            
        ListNode* head = lists[0];
        
        for (int i=1; i<lists.size(); i++) {
            head = mergeTwoLists(head, lists[i]);
        }
        
        return head;
    }

private:    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // can use any solution in @21-merge-two-sorted-lists.cpp
    }
};

