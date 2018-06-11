/*
  Source : https://oj.leetcode.com/problems/palindrome-linked-list
  Author : Alex Xu
  Date   : Jun 11, 2018
  Problem: Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?

*/

// refer to #143
// break list into two lists using one/two pointers to step forward and find the middle node
// reverse the fist node during the find process
// compare the two lists
