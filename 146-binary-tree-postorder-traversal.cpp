/*
 Source : https://leetcode.com/problems/binary-tree-postorder-traversal/
 Author : Alex Xu
 Date   : May 21, 2015
 Problem:

Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

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
    vector<int> postorderTraversal(TreeNode* root) {
        // left -> right -> root
        vector<int> v;
        if (root == nullptr)
            return v;
        
        postorderTraversal(root, v);
        return v;
    }
private:    
    void postorderTraversal(TreeNode* root, vector<int> &v) {
        if (root == nullptr)
            return;
            
        postorderTraversal(root->left, v);
        postorderTraversal(root->right, v);
        v.push_back(root->val);
    }

public:
    /*
     * Iterative solution
     * Refer to #146 for preorderTraversal, if push left then right, we get: VRL
     * But what we need is LRV, so just need one more stack to fix it.
     */
    vector<int> postorderTraversal2(TreeNode* root) {
        // left -> right -> root
        vector<int> v;
        if (root == nullptr)
            return v;
        
        std::stack<TreeNode*> stk;
        std::stack<int> valStk;
        stk.push(root);
        // get VRL first
        while (!stk.empty()) {
            TreeNode* current = stk.top();
            valStk.push(current->val);
            stk.pop();
            
            if (current->left != nullptr)
                stk.push(current->left);
            if (current->right != nullptr)
                stk.push(current->right);
        }

        // VRL -> LRV
        while (!valStk.empty()) {
            v.push_back(valStk.top());
            valStk.pop();
        }
        
        return v;
    }

/*
 * Iterative solution
 * uniform soution for inorder, preorder and postorder
 * easy to under stand
 * I like it.
 */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> v;
        
        if (root == nullptr)
            return v;
        
        std::stack<std::pair<TreeNode*, bool> > stk;
        stk.push(make_pair(root, false));
        TreeNode* node = nullptr;
        bool visited = false;
        
        while(!stk.empty()) {
            node = stk.top().first;
            visited = stk.top().second;
            stk.pop();
            
            if (visited) {
                v.push_back(node->val);
            } else { // V->R->L to stack, LRV to visit
                // push V
                stk.push(make_pair(node, true));     
                // push R
                if (node->right != nullptr)
                    stk.push(make_pair(node->right, false));                 
                // push L
                if (node->left != nullptr)
                    stk.push(make_pair(node->left, false));            
            }
        }
        
        return v;
    }    
};

