/*
 Source : https://oj.leetcode.com/problems/string-to-integer-atoi/
 Author : Alex Xu
 Date   : Jan 08, 2015
 Problem:

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

spoilers alert... click to show requirements for atoi.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        /// discard whitespaces 
        while (*str == ' ') 
            ++str;

        /// check the sign
        int sign = 1;
        if (*str == '-') {
            sign = -1;
            ++str;
        }
        else if (*str == '+') {
            ++str;
        }
        
        long n = 0;
        while('0' <= *str && *str <= '9') {
            n = n*10 + *str - '0';
            if (n > INT_MAX)
                return sign == 1 ? INT_MAX : INT_MIN;
            ++str;
        }

        return n*sign;
    }
};

int main()
{
    Solution s;

    const char* str1 = "1";
    cout << s.atoi(str1) <<endl;

    const char* str2 = "123";
    cout << s.atoi(str2) <<endl;

    const char* str3 = "-123";
    cout << s.atoi(str3) <<endl;

    const char* str4 = "   1234";
    cout << s.atoi(str4) <<endl;

    const char* str5 = "  -1234abc";
    cout << s.atoi(str5) <<endl;

    const char* str6 = "9646324351";
    cout << s.atoi(str6) <<endl;

    /// Input: "2147483648"
    /// Expected:2147483647
    const char* str7 = "2147483648";
    cout << s.atoi(str7) <<endl;

    ///Input:"9223372036854775809"
    ///Expected:2147483647
    const char* str8 = "9223372036854775809";
    cout << s.atoi(str8) <<endl;

	return 0;
}
