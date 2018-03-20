/*
  Source : https://leetcode.com/problems/binary-tree-inorder-traversal/
  Author : Alex Xu
  Date   : May 21, 2015
  Problem:

  Given a binary tree, return the inorder traversal of its nodes' values.

  For example:
  Given binary tree {1,#,2,3},
  1
   \
   2
  /
  3
  return [1,3,2].

  Note: Recursive solution is trivial, could you do it iteratively?
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
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> list = new LinkedList<Integer>();
        inorder(root, list);
        return list;
    }

    private void inorder(TreeNode root, List<Integer> values) {
        if (root == null) {
            return;
        }

        // L-V-R
        inorder(root.left, values);
        values.add(root.val);
        inorder(root.right, values);
    }
}
