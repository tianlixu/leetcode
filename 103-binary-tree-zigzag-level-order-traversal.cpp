/*
 Source : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
 Author : Alex Xu
 Date   : May 22, 2015
 Problem:
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]


    ---->
    <----
    ---->
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        
        if (root == nullptr)
            return v;
        
        bool isLeftToRight = true;
        std::stack<TreeNode*> thisLevel;
        std::stack<TreeNode*> nextLevel;
        
        thisLevel.push(root);
        while (!thisLevel.empty()) {
            vector<int> levelV;
            
            while (!thisLevel.empty()) {
                TreeNode* node = thisLevel.top();
                levelV.push_back(node->val);
                
                if (isLeftToRight) {
                    if (node->left != nullptr)
                        nextLevel.push(node->left);
                    if (node->right != nullptr)
                        nextLevel.push(node->right);
                } else {
                    if (node->right != nullptr)
                        nextLevel.push(node->right);
                    if (node->left != nullptr)
                        nextLevel.push(node->left);
                }
                
                thisLevel.pop();
            }
            
            v.push_back(levelV);
            isLeftToRight = !isLeftToRight;
            std::swap(thisLevel, nextLevel);
        }
        
        return v;
    }
};
