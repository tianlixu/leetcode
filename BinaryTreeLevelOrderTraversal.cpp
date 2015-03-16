/*
 Source : https://leetcode.com/problems/binary-tree-level-order-traversal/
 Author : Alex Xu
 Date   : Mar 16, 2015
 
 Problem:
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/


#include <iostream>
#include <queue>
#include <vector>
#include <math.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printTree(TreeNode *root) {
    if (root == nullptr)
        return;
    
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
    
    cout << endl;
}

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > nodesV;
        
        if (root == nullptr)
            return nodesV;
        
        std::queue<TreeNode *> parentQ;
        std::queue<TreeNode *> childQ;
        
        std::queue<TreeNode *> *pQ = &parentQ;
        std::queue<TreeNode *> *cQ = &childQ;
        pQ->push(root);

            
    visit: // visit current level
        vector<int> v;
        while(!pQ->empty()) {
            TreeNode *node = pQ->front();
            
            v.push_back(node->val);
            
            if (node->left != nullptr)
                cQ->push(node->left);
            if (node->right != nullptr)
                cQ->push(node->right);
            
            pQ->pop();
        }
        nodesV.push_back(v);

        // if child level is not empty then visit child nodes
        if (!cQ->empty()) {
            std::swap(pQ, cQ);
            goto visit;
        }
        
        return nodesV;
    }
};


int main()
{
    
    Solution s;
    
    TreeNode root(1);
    TreeNode n1(2);
    root.left = &n1;
    
    s.levelOrder(&root);
    
    printTree(&root);
    
    return 0;
}
