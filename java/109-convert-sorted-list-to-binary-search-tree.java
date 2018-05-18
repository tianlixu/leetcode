/**
  Source : https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
  Author : Alex Xu
  Date   : May 18, 2018
  Problem: Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
  For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

  Example:
  Given the sorted linked list: [-10,-3,0,5,9],
  One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
*/
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

/**
 * Recursive solution that beats 99.51%:
 * 1. Find the middle node of the list as root
 * 2. Find the middle node of the left sub list as root.left
 * 3. Find the middle node of the right sub list as root.right
 */
class Solution {
    public TreeNode sortedListToBST(ListNode head) {
        if (head == null) {
            return null;    
        }
        if (head.next == null) {
            return new TreeNode(head.val);
        }
        
        ListNode one = head;
        ListNode two = head;
        ListNode pre = null;
        while(two != null && two.next != null) {
            pre = one;
            one = one.next;
            two = two.next.next;
        }
        pre.next = null;
        
        TreeNode node = new TreeNode(one.val);        
        node.left = sortedListToBST(head);        
        node.right = sortedListToBST(one.next);
        
        return node;
    }
}
