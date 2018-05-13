/**
  Source : https://leetcode.com/problems/flatten-binary-tree-to-linked-list
  Author : Alex Xu
  Date   : May 09, 2018
  Problem: Given a binary tree, flatten it to a linked list in-place.
  
  For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
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
 * Recursive solution
 */
class Solution {
    public void flatten(TreeNode root) {
        flatten_helper(root);
    }

    /**
     * return the last node
     */
    private TreeNode flatten_helper(TreeNode root) {
        if (root == null) {
            return null;
        }
        if (root.left == null && root.right == null) {
            return root;
        }

        TreeNode left = root.left;
        TreeNode right = root.right;
        TreeNode tail= null;

        if (left != null) {
            tail = flatten_helper(left);
            root.right = left;
            root.left = null;
        }

        if (tail != null) {
            tail.right = right;
            tail.left = null;
        }

        if (right != null) {
            tail = flatten_helper(right);
        }

        return tail;
    }
}

/**
 * Non-recursive solution with stack
 */
class Solution {
    public void flatten(TreeNode root) {
        Stack<TreeNode> stack = new Stack();
        
        TreeNode node = root;
        while (node != null) {
            if (node.left != null) {
                if (node.right != null) {
                    stack.push(node.right);
                }
                node.right = node.left;
                node.left = null;
            } else {
                if (node.right == null && !stack.empty()) {
                  node.right = stack.pop();
                }
            }
            node = node.right; 
        }
    }
}


/**
 * cut the current.right and link it to current.left.right_most
 * Non-recursive, O(1) space
 */
class Solution {
    public void flatten(TreeNode root) {
        TreeNode current = root;
        while (current != null) {
            if (current.left != null) {
                TreeNode right_most = current.left;
                while (right_most.right != null) {
                    right_most = right_most.right;
                }
                right_most.right = current.right;
                current.right = current.left;
                current.left = null;
            } 
            current = current.right; 
        }    
    }
}
