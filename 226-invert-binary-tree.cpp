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
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // Recursive solution
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        
        invertTree(root->left);
        invertTree(root->right);
        
        std::swap(root->left, root->right);
        
        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        
        std::stack<TreeNode*> stk;
        stk.push(root);
        
        while (!stk.empty()) {
            TreeNode *node = stk.top();
            stk.pop();
            
            std::swap(node->left, node->right);
            if (node->left != nullptr)
                stk.push(node->left);
            if (node->right != nullptr)
                stk.push(node->right);
        }
        
        return root;
    }    
};
