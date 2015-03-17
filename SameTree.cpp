/*
 Source : https://leetcode.com/problems/same-tree/
 Author : Alex Xu
 Date   : Mar 16, 2015
 
 Problem:
 Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr)
            return true;
            
        if (p == nullptr || q == nullptr)
            return false;
        
        // val1 = val2, left1 = left2, right1 = rith2
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
