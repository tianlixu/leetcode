"""
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
"""

import math


class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        r = 0

        while x != 0:
            r = r * 10 + int(math.fmod(x, 10))
            x = self.c_divide(x, 10)

        if r > (2 ** 31 - 1) or r < -2 ** 31:
            r = 0

        return r

    def c_divide(self, a, b):
        return -(-a // b) if a < 0 else a // b
