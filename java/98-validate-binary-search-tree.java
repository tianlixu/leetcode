/**
  Source : https://leetcode.com/problems/binary-tree-inorder-traversal/
  Author : Alex Xu
  Date   : Mar 23, 2018
  Problem:
    Given a binary tree, determine if it is a valid binary search tree (BST).

    Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
        Both the left and right subtrees must also be binary search trees.
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
    public boolean isValidBST(TreeNode root) {
        // follow with problem #94
        List<Integer> values = inorderTraversal(root);
        return isSorted(values);
    }

    private List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> list = new LinkedList<>();
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

    private boolean isSorted(List<Integer> list) {
        if (list == null) return true;

        for (int i=0; i<list.size()-1; i++) {
            if (list.get(i) >= list.get(i+1)) {
                return false;
            }
        }

        return true;
    }
}
