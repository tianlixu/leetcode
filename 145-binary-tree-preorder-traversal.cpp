/*
 Source : https://leetcode.com/problems/binary-tree-postorder-traversal/
 Author : Alex Xu
 Date   : May 21, 2015
 Problem:

Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /*
     * Recusive solution
     */
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        preorderTraversal(root, v);
        return v;
    }

private:
    void preorderTraversal(TreeNode* root, vector<int> &v) {
        if (root == nullptr)
            return;
        
        v.push_back(root->val);
        preorderTraversal(root->left, v);
        preorderTraversal(root->right, v);
    }
    
public: 
    vector<int> preorderTraversal(TreeNode* root) {
        // root -> left -> right
        vector<int> v;
        
        if (root == nullptr)
            return v;
        
        std::stack<TreeNode*> stk;
        stk.push(root);
        
        while (!stk.empty()) {
            TreeNode* current = stk.top();
            v.push_back(current->val);
            stk.pop(); //This calls the removed element's destructor.
            
            // push right, then left
            if (current->right != nullptr)
                stk.push(current->right);
            if (current->left)
                stk.push(current->left);
        }
        
        return v;
    }
};

