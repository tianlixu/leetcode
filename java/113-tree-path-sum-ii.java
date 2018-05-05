/*
  Source : https://leetcode.com/problems/path-sum-ii/
  Author : Alex Xu
  Date   : Mar 16, 2015
 
  Problem:
  Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

  For example:
  Given the below binary tree and sum = 22,
   5
  / \
  4   8
  /   / \
  11  13  4
  /  \    / \
  7    2  5   1
  return
  [
  [5,4,11,2],
  [5,8,4,5]
  ]
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
    public List<List<Integer>> pathSum(TreeNode root, int sum) {      
        if (root == null) {
            List<List<Integer>> paths = new LinkedList<List<Integer>>();    
            return paths;
        }
        
        if (root.left == null && root.right == null && root.val == sum) {
            // found a path, then create a path and return it
            List<Integer> path = new LinkedList<Integer>();
            path.add(root.val);
            List<List<Integer>> paths = new LinkedList<List<Integer>>();            
            paths.add(path);
            
            return paths;
        }
        
        List<List<Integer>> leftPaths = pathSum(root.left, sum - root.val);
        List<List<Integer>> rightPaths = pathSum(root.right, sum - root.val);
        leftPaths.addAll(rightPaths);
        
        for (List<Integer> path : leftPaths) {
            path.add(0, root.val);
        }
        
        return leftPaths;
    }
}

/**
 * 
 *
 */
class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> paths = new LinkedList<List<Integer>>();  
        List<Integer> path = new LinkedList<Integer>();
        dfs(root, sum, paths, path);
        return paths;    
    }
    
    public void dfs(TreeNode root, int sum, List<List<Integer>> paths, List<Integer> path) {
        if (root == null)
            return;
        
        path.add(root.val);
        if (root.left == null && root.right == null) {
            if (sum == root.val) {
                // found a path, then add it             
                paths.add(path);
            }
        } else {
            List<Integer> copyPath = new LinkedList<Integer>();
            copyPath.addAll(path);
   
            // find path from left
            dfs(root.left, sum - root.val, paths, path);
            // find path from right
            dfs(root.right, sum - root.val, paths, copyPath);                
        }
    }
}
