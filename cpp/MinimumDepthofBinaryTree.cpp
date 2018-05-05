/*
 Source : https://leetcode.com/problems/minimum-depth-of-binary-tree/
 Author : Alex Xu
 Date   : Mar 11, 2015
 Problem:
 Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    int minDepth(TreeNode *root) {
        if (root == NULL)
            return 0;
            
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);
        
        if (leftDepth == 0)
            return rightDepth + 1;
        else if (rightDepth == 0)
            return leftDepth + 1;
        else return min(leftDepth, rightDepth) + 1;
    }
};
