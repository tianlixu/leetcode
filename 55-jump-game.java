/*
  Source : https://leetcode.com/problems/jump-game/
  Author : Alex Xu
  Date   : Jul 19, 2016
  Problem:

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

  Tag: Greedy

  Solution:
  From back to front, record the number of steps needed to jump to the closet bucket which is reachable to the last bucket.

     0    1     2      3    4   5
  +-----+-----+-----+-----+---+---+
  |  2  | 4   | 3   | 0   | 0 | 0 |
  +-----+-----+-----+-----+---+---+
                |      i=3
                |      steps=2, nums[3]=0, you cannot reach the end from this bucket, move on to i=2
                |
                i=2
                steps=3, nums[2]=3, meaning that you can reach the end from this bucket, reset and move on to i=1
                as long as nums[2] can reach the end, the problem becomes if we can reach nums[2] from the begining.
                ==> find the asnswer for array[0,...,2]
*/

public class Solution {
    public boolean canJump(int[] nums) {
        // move to the last element
        int i = nums.length - 1;
        int steps = 0;

        while (i > 0) {
            // move back one element
            i--;
            steps++;

            if (nums[i] >= steps) // can reach the end from nums[i]
                steps = 0; // reset
        }

        return nums[i] >= steps;
    }
}
