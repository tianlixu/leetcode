/*
 Source : https://leetcode.com/problems/balanced-binary-tree/
 Author : Alex Xu
 Date   : Jan 09, 2015
 Problem:
 
 Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
    bool isBalanced(TreeNode *root) {
        return depth(root) >= 0;
    }
    
    // return the height of 'root' if 'root' is a balanced tree, otherwise return -1.
    int depth(TreeNode *root) {
        if (root == nullptr)
            return 0;
            
        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);
        
        if (leftDepth < 0 || rightDepth < 0 || abs(leftDepth - rightDepth) > 1)
            return -1; // trim
            
        return max(leftDepth, rightDepth) + 1;
    }
};
