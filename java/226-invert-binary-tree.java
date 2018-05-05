/*
  Source : https://leetcode.com/problems/invert-binary-tree/
  Author : Alex Xu
  Date   : June 10, 2015
  Problem:
  Invert a binary tree. That is to swap the left and right of each node.

       4
     /   \
    2     7
   /  \   / \
  1   3 6   9
  
  to
       4
     /   \
    7     2
   / \   / \
  9   6 3   1
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
public class Solution {
    /**
     * Recursive approach
     *
     * Complexity Analysis
     * Since each node in the tree is visited only once, the time complexity is O(n),
     * where n is the number of nodes in the tree. We cannot do better than that, since
     * at the very least we have to visit each node to invert it.
     *
     * Because of recursion, O(h) function calls will be placed on the stack in the worst
     * case, where h is the height of the tree. Because h c O(n), the space complexity is O(n).
     */
    public TreeNode invertTree(TreeNode root) {
        if (root == null) {
            return null;
        }
        
        TreeNode left = invertTree(root.left);
        TreeNode right = invertTree(root.right);
        root.left = right;
        root.right = left;
        
        return root;
    }


    public TreeNode invertTree(TreeNode root) {
        if (root == null) {
            return null;
        }

        // use a queue/stack/whatever to save the nodes will be inverted
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(root);

        while(!q.isEmpty()) {
            TreeNode node = q.poll();

            TreeNode left = node.left;
            node.left = node.right;
            node.right = left;

            if (node.left != null) {
                q.add(node.left);
            }
            if (node.right != null) {
                q.add(node.right);
            }
        }

        return root;
    }
}
