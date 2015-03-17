/*
 Source : https://leetcode.com/problems/binary-tree-inorder-traversal/
 Author : Alex Xu
 Date   : Mar 16, 2015
 
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
    // recursive solution
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> v;
        inorder(root, v);
        return v;
    }
    
    void inorder(TreeNode *root, vector<int> &v)
    {
        if(root == nullptr)
           return ;
          
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    
};
