/*
 Source : https://leetcode.com/problems/binary-tree-inorder-traversal/
 Author : Alex Xu
 Date   : Mar 16, 2015
 
 Problem:
 Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // solution 1: recursive
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr)
            return true;
        
        return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr)
            return true;
        
        if (left != nullptr && right != nullptr && left->val == right->val)
            return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
        else
            return false;
    }
    
    // solution 2: inOrder visit
    // solution 2: optimized inorder visit, visit level by level and break if necessary.
    
    // solution 3: Iterative
};
