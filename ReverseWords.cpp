/*
Source: https://oj.leetcode.com/problems/reverse-words-in-a-string/
Author: Alex Xu
Date: Jan 4, 2015

Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Clarification:
    What constitutes a word?
    A sequence of non-space characters constitutes a word.
    Could the input string contain leading or trailing spaces?
    Yes. However, your reversed string should not contain leading or trailing spaces.
    How about multiple spaces between two words?
    Reduce them to a single space in the reversed string.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        char SPACE = ' ';
        size_t posStart = string::npos;
        size_t posEnd = s.length()-1;

        std::vector<string> v;
        while ( (posStart = s.find_last_of(SPACE, posEnd)) != string::npos) {
            if (posStart != posEnd) {
                // find a word
                v.push_back(s.substr(posStart+1, posEnd-posStart));
            } // else { ignore the additional SPACEs

            // ignore the first SPACE
            if (posStart == 0)
                break;

            posEnd = posStart-1;
        }

        // find the first word
        if (posStart != 0)
            v.push_back(s.substr(0, posEnd+1));

        s.clear();
        for (int i=0; i<v.size(); ++i) {
            s += v[i];
            if (i != v.size()-1)
                s += SPACE;
        }
 
    }
    
    void reverseWord(string &word) {
        for (int i=0; i< word.length()/2; ++i) {
            std::swap(word[i], word[word.length()-1-i]);
        }
    }
};


int main()
{
    Solution s;
    string str = "     Alex         loves LeetCode and     GitHub   ";

    s.reverseWords(str);

    cout <<endl;

    /*
    string word = "buHtiG";

    cout << word << endl;
    s.reverseWord(word);
    cout << word << endl;
    */
    
    return 0;
}
