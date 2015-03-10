/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 #inlcude <map>
 
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
            return NULL;
        
        RandomListNode dummy = RandomListNode(0);
        std::map<RandomListNode*, int> mapOrigin;
        std::map<int, RandomListNode*> mapCopy; 
        
        // create the single linked list first without setting random pointer
        int index = 1; // index of the node in the list
        RandomListNode *p = head;
        RandomListNode *q = &dummy;
        while (p != NULL) {
            RandomListNode *node = new RandomListNode(p->label);
            q->next = node;
            
            // setting the map
            mapOrigin[p] = index;
            mapCopy[index] = node;
            
            p = p->next;
            q = node;
            ++ index;
        }
        q->next = NULL;
        
        p = head;
        q = dummy.next;
        while (p != NULL) {
            if (p->random == NULL) {
                q->random = NULL;
            } else {
                int idx = mapOrigin[p->random];
                q->random = mapCopy[idx];
            }
            p = p->next;
            q = q->next;
        }
        
        return dummy.next;
    }
};
