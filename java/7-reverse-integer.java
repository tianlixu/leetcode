/*
 Source : https://oj.leetcode.com/problems/reverse-integer/
 Author : Alex Xu
 Date   : Jan 07, 2015

 Problem: Given a 32-bit signed integer, reverse digits of an integer.

 Example 1:

 Input: 123
 Output: 321
 Example 2:

 Input: -123
 Output: -321
 Example 3:

 Input: 120
 Output: 21
 Note:
 Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

class Solution {
    public int reverse(int x) {
        int result = 0;

        while (x != 0)
            {
                int tail = x % 10;
                int newResult = result * 10 + tail;
                // reversing the above operation should give you the previous number else over flow
                if ((newResult - tail) / 10 != result) { return 0; }
                result = newResult;
                x = x / 10;
            }

        return result;
    } 
}
