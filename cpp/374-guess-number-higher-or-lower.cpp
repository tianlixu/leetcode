/*
  Source : https://leetcode.com/problems/guess-number-higher-or-lower/
  Author : Alex Xu
  Date   : Jul 13, 2016
  Problem:

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
Example:
n = 10, I pick 6.

Return 6.

*/
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        return helper(1, n);
    }
    
    int helper(int n1, int n2) {
        int m = n1 + (n2 - n1)/2; // (n1+n2)/2 may overflow
        
        int ret = guess(m);
        if (ret == 0)
            return m;
        else if (ret == -1)
            return helper(n1, m-1);
        else
            return helper(m+1, n2);
    }
};

