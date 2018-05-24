/**
  Source : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
  Author : Alex Xu
  Date   : May 24, 2018
  Problem: Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
*/


// Runtime 1ms, beats 100%. Really?!
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        return sortedArrayToBST(nums, 0, nums.length - 1);
    }
    
    public TreeNode sortedArrayToBST(int[] nums, int start, int end) {
        TreeNode root;
        
        if (start == end) {
            root = new TreeNode(nums[start]);
        } else if (end > start) {
            int middle_index = (start + end + 1) / 2;
            root = new TreeNode(nums[middle_index]);
            root.left = sortedArrayToBST(nums, start, middle_index - 1);
            root.right = sortedArrayToBST(nums, middle_index + 1, end);
        } else {
            root = null;
        }
        
        return root;
    }
}
