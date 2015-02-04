/*
 Source : https://oj.leetcode.com/problems/length-of-last-word/
 Author : Alex Xu
 Date   : Feb 04, 2015

 Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

 If the last word does not exist, return 0.

 Note: A word is defined as a character sequence consists of non-space characters only.

 For example, 
 Given s = "Hello World",
 return 5.

 My Comment:
   Is this a leetcode problem about ALGRORITHM????? apoc!!!!
*/

#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (s == NULL || *s == '\0')
            return 0;
        
        int lenOfString = strlen(s);
        while (s[lenOfString-1] == ' ')
            -- lenOfString;
        
        int lenOfWorld = 0;
        while (s[lenOfString - lenOfWorld - 1] != ' ' &&  lenOfWorld < lenOfString) {
            ++ lenOfWorld;
        }

        return lenOfWorld;
    }
};


int main()
{
    Solution s;

    //const char *str = "Hi world";
    //const char *str = "Hi";
    //const char *str = "hi ";
    //const char *str = " hi ";
    const char *str = " hi";
    
    cout << s.lengthOfLastWord(str) << endl;
    
    return 0;
}
