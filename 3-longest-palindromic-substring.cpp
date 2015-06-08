/*
  Source : https://leetcode.com/problems/longest-palindromic-substring/
  Author : Alex Xu
  Date   : June 08, 2015
  Problem:
  Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

  abccba
  abcdcba
*/

class Solution {
public:
    /*
     * Brutal force: a[i] (or a[i] a[i+1]) is in the middle of the palindromic string
     * Time: O(n^2)
     */
    string longestPalindrome1(string s) {
        if (s.length() <= 1)
            return s;
            
        string longestStr;
        
        for (int mid=0; mid<s.length()-1; mid++) {
            string pstr = longestPalindromeAt(s, mid, mid+1);
            if (pstr.length() > longestStr.length())
                longestStr = pstr;
                
            pstr = longestPalindromeAt(s, mid);
            if (pstr.length() > longestStr.length())
                longestStr = pstr;
        }
        
        return longestStr;
    }

private:
    // abc cba
    string longestPalindromeAt(string &s, int left, int right) {
        int low = left;
        int high = right;
        
        while (low >= 0 && high < s.size() && s[low] == s[high]) {
            low --;
            high ++;
        }
        
        // (low, high), not [low, high]
        return s.substr(low + 1 , high - low - 1);
    }
    
    // abc d cba
    string longestPalindromeAt(string &s, int pos) {
        int low = pos - 1;
        int high = pos + 1;
        
        while (low >= 0 && high < s.size() && s[low] == s[high]) {
            low --;
            high ++;
        }
        
        // (low, high), not [low, high]
        return s.substr(low + 1 , high - low - 1);
    }    
};
