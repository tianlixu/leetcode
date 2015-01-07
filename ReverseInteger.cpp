/*
 Source : https://oj.leetcode.com/problems/two-sum/
 Author : Alex Xu
 Date   : Jan 07, 2015

  Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Update (2014-11-10):
Test cases had been added to test the overflow behavior.
 */

#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long r = 0;

        while (x) {
            r = r*10 + x%10;
            x /= 10;
        }

        if (abs(r) > pow(2, 31))
            r = 0;
        
        return r;
    }
};

int main()
{
    Solution s;

    int num = 123;
    int r = s.reverse(num);
    cout << "r=" << r <<endl;
  
    num = -456;
    r = s.reverse(num);
    cout << "r=" << r <<endl;


    num = 1534236469;
    r = s.reverse(num);
    cout << "r=" << r <<endl;

    num = 3;
    r = s.reverse(num);
    cout << "r=" << r <<endl;

    num = -3;
    r = s.reverse(num);
    cout << "r=" << r <<endl;

	return 0;
}
