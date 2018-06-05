/*
 Source : https://leetcode.com/problems/merge-k-sorted-lists/
 Author : Alex Xu
 Date   : June 04, 2018
 Problem: Merge k sorted linked lists and return it as one sorted list.
 Analyze and describe its complexity.
 Example:
  Input:
  [
      1->4->5,
      1->3->4,
      2->6
  ]
  Output: 1->1->2->3->4->4->5->6
*/

/*
Solution 1: 15ms, beats 84.38%
1. Traverse all the linked lists and collect the values of the nodes into an array.
2. Sort and iterate over this array to get the proper value of nodes. (quick sort, NlogN)
3. Create a new sorted linked list and extend it with the new nodes.


Complexity Analysis

Time complexity : O(Nlog N) where N is the total number of nodes.
    - Collecting all the values costs O(N) time.
    - A stable sorting algorithm costs O(Nlog N) time.
    - Iterating for creating the linked list costs O(N) time.
Space complexity : O(N).
    - Sorting cost O(N) space (depends on the algorithm you choose).
    - Creating a new linked list costs O(N) space.
**/
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        /// count total number of nodes in the k lists
        int N = 0;
        for (ListNode l : lists) {
            N += getLength(l);
        }
        
        /// create an array to save all the N nodes
        int[] nodes = new int[N];
        int index = 0;
        for (ListNode l : lists) {
            while (l != null) {
                nodes[index] = l.val;
                index ++;
                l = l.next;
            }
        }
        
        /// sort the array nodes
        Arrays.sort(nodes);
        
        /// create the list for N nodes
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        for(int v : nodes) {
            tail.next = new ListNode(v);
            tail = tail.next;
        }
        
        return dummy.next;
    }
    
    private int getLength(ListNode list) {
        int length = 0;
        while (list != null) {
            length ++;
            list = list.next;
        }
        
        return length;
    }
}


/*
Solution 2: Accepted, but poor runtime: 436 ms, beats 0%?
Algorithm:
    - Compare every k nodes (head of every linked list) and get the node with the smallest value.
    - Extend the final sorted linked list with the selected nodes.

Complexity Analysis:
Time complexity : O(kN) where k is the number of linked lists.
    - Almost every selection of node in final linked costs O(k) (k-1 times comparison).
    - There are N nodes in the final linked list.
Space complexity :
    - O(n) Creating a new linked list costs O(n) space.
    - O(1) It's not hard to apply in-place method - connect selected nodes instead of creating new nodes to fill the new linked list. (it's O(1) in the following implementation)
**/
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        int miniIndex = -1;
        
        while (true) {
            for (int i=0; i< lists.length; i++) {
                if (lists[i] == null) {
                    continue;
                }

                if(miniIndex == -1) {
                    miniIndex = i;
                    continue;
                }

                if (lists[miniIndex].val > lists[i].val) {
                    miniIndex = i;
                }
            }
            
            if (miniIndex == -1) {
                break;
            }
            
            tail.next = lists[miniIndex];
            tail = tail.next;
            lists[miniIndex] = lists[miniIndex].next;
            miniIndex = -1;
        }
        
        
        return dummy.next;
    }
}


/*
Solution 3: 
 continue with solution 2: Runtime 83ms, beats 7.91%
 1. for the 1st comparison of the heads nodes of the k lists, we can sore them out, so we get
   1.1 the smallest node, and
   1.2 a sorted k-1 nodes

 2. for the next N-1 comparison, use insert sort, Time is O(logk)

Complexity Analysis

Time complexity : O(Nlog k) where k is the number of linked lists.
    - The comparison cost will be reduced to O(logk) for every pop and insertion to priority queue. 
      But finding the node with the smallest value just costs O(1) time.
    - There are N nodes in the final linked list.
Space complexity :
    - O(n) Creating a new linked list costs O(n) space.
    - O(k) The code above present applies in-place method which cost O(1) space. And the priority queue (often implemented with heaps) costs O(k) space (it's far less than N in most situations).


Note that: the following declaration of pq has runtime 21ms and beats 57%?! All the remaining part is the same.

        PriorityQueue<ListNode> queue= new PriorityQueue<ListNode>(lists.length,new Comparator<ListNode>(){
            @Override
            public int compare(ListNode o1,ListNode o2){
                if (o1.val<o2.val)
                    return -1;
                else if (o1.val==o2.val)
                    return 0;
                else 
                    return 1;
            }
        });
 */
import java.util.PriorityQueue;

class Solution {   
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }
      
        // create priority queue and add the head nodes of the k lists to pq
        PriorityQueue<ListNode> pq = new PriorityQueue<>(lists.length, (l1, l2) -> l1.val - l2.val);
        for (ListNode l : lists) {
            if (l != null) {
                pq.add(l);
            }
        }
        
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        while (!pq.isEmpty()) {
            ListNode node = pq.poll(); // get the smallest and link it to tail
            tail.next = node;
            tail = tail.next;
            if (node.next != null) {
                pq.add(node.next); // add smallest.next to pq
            }
        }
        tail.next = null;
        
        return dummy.next;
    }
}

