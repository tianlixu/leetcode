/*
 Source : https://oj.leetcode.com/problems/implement-strstr/
 Author : Alex Xu
 Date   : Feb 02, 2015

 Implement strStr().
 Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

#include <iostream>
using namespace std;


class Solution {
public:
    int strStr(char *haystack, char *needle) {
        if (haystack != NULL && *needle == '\0')
            return 0;

        int i = 0;
        int j = 0;

        while (haystack[i] != '\0') {
            while (haystack[i+j] == needle[j]) {
                ++ j;

                if (needle[j] == '\0')  // find it
                    return i;

                if (haystack[i+j] == '\0') // end of haystack
                    return -1;
            }
            
            ++ i;
            j = 0;
        }

        return -1;
    }
};

int main()
{

    Solution s;

    //char *haystack = "this is a test of my hello world.";
    //char *needle = "test of";
    //char *needle = "this";
    //char *needle = "thisgoo";

    /*
      Input:"", ""
      Output:-1
      Expected:0
    */
    //char *haystack = "";
    //char * needle = "";

    /*
      Input:"a", ""
      Output:-1
      Expected:0
    */
    char *haystack = "a";
    char * needle = "";
    int pos = s.strStr(haystack, needle);
    cout << "pos=" << pos << endl;

    return 0;
}
