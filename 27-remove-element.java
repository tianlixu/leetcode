/*
 Source : https://oj.leetcode.com/problems/remove-element/
 Author : Alex Xu
 Date   : Feb 05, 2015

 Given an array and a value, remove all instances of that value in place and return the new length.

 The order of elements can be changed. It doesn't matter what you leave beyond the new length.

 A[m] +-+-+-+-+   +-+-+-+
      | | | | |...| | | |
      +-+-+-+-+   +-+-+-+
       ^               ^
       |head           |tail

*/

class Solution {
    public int removeElement(int[] nums, int val) {
        int head = 0;
        int tail = nums.length - 1;

        while (head <= tail) {
            if (nums[head] == val) {
                nums[head] = nums[tail]; // overwrite [head] with [tail]
                tail --;
                continue; // retest [head] since it's a new value copied from [tail]
            }
            head ++;
        }

        return tail + 1;
    }
}
