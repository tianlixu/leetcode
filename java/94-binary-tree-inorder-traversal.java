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
}


/**
 * Iterative solution, which can be applied to in-order, pre-order and post-order traversal
 */
import java.util.AbstractMap;

class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> list = new LinkedList<>();

        if (root != null) {
            // Map.Entry is something like a tuple/pair in python
            Stack<Map.Entry<TreeNode, Boolean>> stack = new Stack();
            TreeNode node = root;
            boolean visited = false;
            Map.Entry<TreeNode, Boolean> entry = new AbstractMap.SimpleEntry(node, visited);
            stack.push(entry);

            while(!stack.empty()) {
                entry = stack.pop();
                node = entry.getKey();
                visited = entry.getValue();

                if (visited) {
                    list.add(node.val);
                } else {
                    // push in R->V->L, then visit in L-V-R
                    if (node.right != null) {
                        stack.push(new AbstractMap.SimpleEntry(node.right, false));
                    }
                    stack.push(new AbstractMap.SimpleEntry(node, true));
                    if (node.left != null) {
                        stack.push(new AbstractMap.SimpleEntry(node.left, false));
                    }
                }
            }
        }

        return list;
    }
}

// Yet another solution for in-order
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> list = new LinkedList<Integer>();
        if (root != null) {
            Stack<TreeNode> stack = new Stack();
            TreeNode current = root;

            while (current != null || !stack.empty()) {
                if (current!= null) {
                    stack.push(current);   // push current root to stack
                    current = current.left; // move on to its left child
                } else {
                    current = stack.pop(); // pop root
                    list.add(current.val); // visit root
                    current = current.right; // move on to its right child
                }
            }
        }

        return list;
    }
}
