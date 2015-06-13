/*
  Source : https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
  Author : Alex Xu
  Date   : Mar 16, 2015
 
  Problem:
  Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

  For example:
  Given binary tree {3,9,20,#,#,15,7},
     3
    / \
   9  20
     /  \
    15   7
  return its bottom-up level order traversal as:
  [
      [15,7],
      [9,20],
      [3]
  ]

  the same solution as @BinaryTreeLevelOrderTraversal.cpp
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
        vector<vector<int>> vec;
        
        if (root == nullptr)
            return vec;
            
        std::queue<TreeNode *> thisQ;
        std::queue<TreeNode *> nextQ;
        
        thisQ.push(root);
        levelOrder(thisQ, nextQ, vec);
        
        return vec;
    }
    
    void levelOrder(std::queue<TreeNode *>& thisQ, std::queue<TreeNode *>& nextQ, vector<vector<int> >& vec) {
        // values of this levle
        vector<int> v;

        while(!thisQ.empty()) {
            TreeNode* node = thisQ.front();
            
            v.push_back(node->val);
            
            if (node->left != nullptr)
                nextQ.push(node->left);
            if (node->right != nullptr)
                nextQ.push(node->right);
                
            thisQ.pop();
        }
        vec.insert(vec.begin(), v);        

        // get the values of next level if it is not empty
        if (!nextQ.empty())
            levelOrder(nextQ, thisQ, vec);
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
