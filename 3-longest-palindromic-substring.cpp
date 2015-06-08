/*
  Source : https://leetcode.com/problems/longest-palindromic-substring/
  Author : Alex Xu
  Date   : June 08, 2015
  Problem:
  Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

  abccba
  abcdcba
*/

#include <iostream>
#include <string>

using namespace std;


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



/*
 * Brutal force, for each possible substring
 * Time: O(n^3)
 * will cause TLE in leetcode
 */
public:
    string longestPalindrome2(string s) {
        if (s.length() <= 1)
            return s;
            
        string longestStr;
        for (int i=0; i<s.length(); i++) {
            for (int j=i; j<s.length(); j++) {
                string sub = s.substr(i, j-i+1);
                if (isPalindrome(sub) && (sub.length() > longestStr.length())
                    )
                        longestStr = sub;
            }
        }
        
        return longestStr;
    }
    
private:
    bool isPalindrome(string s) {
        int low = 0;
        int high = s.length() - 1;
        
        while (s[low] == s[high]) {
            if (low == high || low+1 == high)
                return true;
                
            low ++;
            high --;
        }
        
        return false;
    }    
};

int main()
{
    string str = "lcnvoknqgejxbfhijmxglisfzjwbtvhodwummdqeggzfczmetrdnoetmcydwddmtubcqmdjwnpzdqcdhplxtezctvgnpobnnscrmeqkwgiedhzsvskrxwfyklynkplbgefjbyhlgmkkfpwngdkvwmbdskvagkcfsidrdgwgmnqjtdbtltzwxaokrvbxqqqhljszmefsyewwggylpugmdmemvcnlugipqdjnriythsanfdxpvbatsnatmlusspqizgknabhnqayeuzflkuysqyhfxojhfponsndytvjpbzlbfzjhmwoxcbwvhnvnzwmkhjxvuszgtqhctbqsxnasnhrusodeqmzrlcsrafghbqjpyklaaqximcjmpsxpzbyxqvpexytrhwhmrkuybtvqhwxdqhsnbecpfiudaqpzsvfaywvkhargputojdxonvlprzwvrjlmvqmrlftzbytqdusgeupuofhgonqoyffhmartpcbgybshllnjaapaixdbbljvjomdrrgfeqhwffcknmcqbhvulwiwmsxntropqzefwboozphjectnudtvzzlcmeruszqxvjgikcpfclnrayokxsqxpicfkvaerljmxchwcmxhtbwitsexfqowsflgzzeynuzhtzdaixhjtnielbablmckqzcccalpuyahwowqpcskjencokprybrpmpdnswslpunohafvminfolekdleusuaeiatdqsoatputmymqvxjqpikumgmxaxidlrlfmrhpkzmnxjtvdnopcgsiedvtfkltvplfcfflmwyqffktsmpezbxlnjegdlrcubwqvhxdammpkwkycrqtegepyxtohspeasrdtinjhbesilsvffnzznltsspjwuogdyzvanalohmzrywdwqqcukjceothydlgtocukc";

    Solution s;

    cout << s.longestPalindrome1(str) << endl;
    cout << s.longestPalindrome2(str) << endl;
    
    return 0;
}
