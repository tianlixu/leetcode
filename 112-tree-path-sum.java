/*
 Source : https://leetcode.com/problems/path-sum
 Author : Alex Xu
 Date   : Mar 16, 2015
 
 Problem:
 
 Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

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
    public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null)
            return false;

        // found a path
        if (root.val == sum && root.left == null && root.right == null)
            return ture;
        
        // try to find a path from left OR right sub tree
        return (hasPathSum(root.left, sum - root.val) || hasPathSum(root.right, sum - root.val));
    }
}


class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null) return false;
        
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        root.val = sum - root.val;
        q.add(root);
        
        while (!q.isEmpty()) {
            TreeNode node = q.poll();
            if (node.val == 0 && node.left == null && node.right == null)
                return true;
            
            if (node.left != null) {
                node.left.val = node.val - node.left.val;
                q.add(node.left);
            }
            
            if (node.right != null) {
                node.right.val = node.val - node.right.val;
                q.add(node.right);
            }
        }
        
        return false;
    }
}
