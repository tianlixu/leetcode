/**
  Source : https://leetcode.com/problems/unique-binary-search-trees-ii/description/
  Author : Alex Xu
  Date   : May 27, 2018
  Problem: Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
    public List<TreeNode> generateTrees(int n) {
        if (n <= 0) {
            return new LinkedList<>();
        }
        return generateTrees(1, n);
    }
    
    public List<TreeNode> generateTrees(int n1, int n2) {
        List<TreeNode> root_list = new LinkedList<>();
        
        if (n1 > n2) {
            root_list.add(null);
        } else if (n1 == n2) {
            TreeNode root = new TreeNode(n1);
            root_list.add(root);
        } else {
            for (int n = n1; n <= n2; n++) {
                List<TreeNode> left_list = generateTrees(n1, n-1);
                List<TreeNode> right_list = generateTrees(n+1, n2);
                
                for (TreeNode left : left_list) {
                    for (TreeNode right : right_list) {
                        TreeNode root = new TreeNode(n);
                        root.left = left;
                        root.right = right;                       
                        root_list.add(root);
                    }
                }
            }
        }
        
        return root_list;
    }
}
