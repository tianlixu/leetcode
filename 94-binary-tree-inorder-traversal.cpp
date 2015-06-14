/*
  Source : https://leetcode.com/problems/binary-tree-inorder-traversal/
  Author : Alex Xu
  Date   : May 21, 2015
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
    /*
     * Recursive solution
     */
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> v;
        inorder(root, v);
        return v;
    }
    
private:
    void inorderTraversal(TreeNode *root, vector<int> &v) {
        if(root == nullptr)
            return ;
            
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

public:
    /*
     * Iterative solution
     *
     * Algorithm:
     * 1. make p = root
     * 2. if p != null then push left to stack, and p = p->left
     * 3. if p == null, then visit top from stack, and p = p->right
     */
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> v;                                                                           
            
        TreeNode* current = root;
        std::stack<TreeNode*> stk; // stk saves the nodes to be visited
        while (current != nullptr || !stk.empty()) {
            if (current != nullptr) {
                stk.push(current);
                current = current->left;
            } else {
                current = stk.top();
                v.push_back(current->val);
                current = current->right;
                stk.pop();
            }
        }
        
        return v;
    }

public:
/*
 * Iterative solution.
 * the uniform solution for inorder, preorder and post order
 * easy to understand.
 * I like it!
 */    
vector<int> inorderTraversal(TreeNode *root) {
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
            } else { // R->V->L to stack, LVR to visit
                // push R
                if (node->right != nullptr)
                    stk.push(make_pair(node->right, false));
                // push V
                stk.push(make_pair(node, true));
                // push L
                if (node->left != nullptr)
                    stk.push(make_pair(node->left, false));
            }
        }
        
        return v;
    }    
};
