/**
  Source : https://leetcode.com/problems/binary-tree-inorder-traversal/
  Author : Alex Xu
  Date   : Mar 23, 2018
  Problem:
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

    Note:
    You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Hint: in-order traversal a bst would create a sorted array. 
      Similar problem #94: https://leetcode.com/problems/binary-tree-inorder-traversal/
*/



/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */


// Iterative solution
import java.util.AbstractMap;
class Solution {
    public int kthSmallest(TreeNode root, int k) {        
        // in-order traversal
        // Map.Entry is something like a tuple/pair in python                                                            
        Stack<Map.Entry<TreeNode, Boolean>> stack = new Stack();
        TreeNode node = root;
        boolean visited = false;
        Map.Entry<TreeNode, Boolean> entry = new AbstractMap.SimpleEntry(node, visited);
        stack.push(entry);

        while(!stack.empty()) {
            entry = stack.pop();
            node = entry.getKey();
            visited = entry.getValue();

            if (visited) {
                k--;
                if (k == 0) break;
            } else {
                // push in R->V->L, then visit in L-V-R          
                if (node.right != null) {                                                                                   stack.push(new AbstractMap.SimpleEntry(node.right, false));
                }
                stack.push(new AbstractMap.SimpleEntry(node, true));
                if (node.left != null) {
                    stack.push(new AbstractMap.SimpleEntry(node.left, false));
                }
            }
        }

        return node.val;
    }
}

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */


// Recursive solution
import java.util.concurrent.atomic.AtomicInteger;
class Solution {
    public int kthSmallest(TreeNode root, int k) {
        // in-order traversal
        return inorder(root, new AtomicInteger(k));
    }

    private int inorder(TreeNode root, AtomicInteger K) {
        //L
        if (root.left != null) {
            int ret = inorder(root.left, K);
            if (K.intValue() == 0) {
                return ret;
            }
        }

        // V
        K.addAndGet(-1);
        if (K.intValue() == 0) {
            return root.val;
        }

        if (root.right != null) {
            int ret = inorder(root.right, K);
            if (K.intValue() == 0) {
                return ret;
            }
        }

        // !!! should never reach here
        return 0;
    }
}
