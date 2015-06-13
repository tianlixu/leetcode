/*
  Source : https://leetcode.com/problems/path-sum-ii/
  Author : Alex Xu
  Date   : Mar 16, 2015
 
  Problem:
  Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

  For example:
  Given the below binary tree and sum = 22,
   5
  / \
  4   8
  /   / \
  11  13  4
  /  \    / \
  7    2  5   1
  return
  [
  [5,4,11,2],
  [5,8,4,5]
  ]
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > pathV;
        
        if (root == nullptr)
            return pathV;
            
        // find a path
        if (root->left == nullptr && root->right == nullptr && root->val == sum) {
            // create a new path and insert current leaf node into the path
            vector<int> path;
            path.insert(path.begin(), root->val);
            
            // insert the current path into the path vector
            pathV.insert(pathV.begin(), path);
            return pathV;
        }
        
        // find the left paths
        vector<vector<int> > leftPathV = pathSum(root->left, sum - root->val);
        if (!leftPathV.empty()) {
            // insert current node into all the paths of the left sub-tree
            for (auto&& aPath : leftPathV)
                aPath.insert(aPath.begin(), root->val);
        }
        
        // find the right paths
        vector<vector<int> > rightPathV = pathSum(root->right, sum - root->val);
        if (!rightPathV.empty()) {
            // insert current node into all the paths of the left sub-tree
            for (auto&& aPath : rightPathV) 
                aPath.insert(aPath.begin(), root->val);
        }
        
        // merge left and right paths
        leftPathV.insert(leftPathV.end(), rightPathV.begin(), rightPathV.end());

        return leftPathV;
    }
};
