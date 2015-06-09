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
     * Manacher’s Algorithm
     *
     * http://articles.leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
     *
     * Time: O(n) solution
     */

    
    /*
     * Enum: a[i] (or a[i] a[i+1]) is in the middle of the palindromic string
     * Time: O(n^2), Space: O(1)
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


public:
    /*
     * Dynamic Programming
     *
     * f(i,j) indicates whether a[i....j] is palindrome or not
     *          |- true                        , i=j
     * f(i,j) = |- a[i]=a[j]                   , j = i+1
     *          |- a[i]=a[j] && f(i+1, j-1)    , j>i+1
     * 
     * Time: O(n^2), Space: O(n^2)
     */
    string longestPalindrome3(string s) {
        int low = 0;
        int high = 0;
        
        const int N = s.length();
        bool f[N][N];

        for (int i=0; i<N; i++) {
            f[i][i] = true;

            /*
             * !!! NOT: for (int j=i; j<N; j++)
             * eg:
             * f(0,3) = (a[0]==a[3] && f(1, 2))
             * Note that f(1,2) has not been set yet.
             */
            for (int j=0; j<i; j++) {
                /*
                if (i == j) {
                    f[j][i] = true;
                } else if (i == j+1) {
                    f[j][i] = (s[i] == s[j]);
                } else {
                    f[j][i] = f[j+1][i-1] && (s[i] == s[j]);
                }
                * --> Refactor to:*/
                f[j][i] = (s[i] == s[j]) && (f[j+1][i-1] || i == j+1);                

                if (f[j][i] && (i - j > high - low)) {
                    low = j;
                    high = i;
                }
            }
        }

        return s.substr(low, high - low + 1);
    }
};

int main()
{
    string str = "lcnvoknqgejxbfhijmxglisfzjwbtvhodwummdqeggzfczmetrdnoetmcydwddmtubcqmdjwnpzdqcdhplxtezctvgnpobnnscrmeqkwgiedhzsvskrxwfyklynkplbgefjbyhlgmkkfpwngdkvwmbdskvagkcfsidrdgwgmnqjtdbtltzwxaokrvbxqqqhljszmefsyewwggylpugmdmemvcnlugipqdjnriythsanfdxpvbatsnatmlusspqizgknabhnqayeuzflkuysqyhfxojhfponsndytvjpbzlbfzjhmwoxcbwvhnvnzwmkhjxvuszgtqhctbqsxnasnhrusodeqmzrlcsrafghbqjpyklaaqximcjmpsxpzbyxqvpexytrhwhmrkuybtvqhwxdqhsnbecpfiudaqpzsvfaywvkhargputojdxonvlprzwvrjlmvqmrlftzbytqdusgeupuofhgonqoyffhmartpcbgybshllnjaapaixdbbljvjomdrrgfeqhwffcknmcqbhvulwiwmsxntropqzefwboozphjectnudtvzzlcmeruszqxvjgikcpfclnrayokxsqxpicfkvaerljmxchwcmxhtbwitsexfqowsflgzzeynuzhtzdaixhjtnielbablmckqzcccalpuyahwowqpcskjencokprybrpmpdnswslpunohafvminfolekdleusuaeiatdqsoatputmymqvxjqpikumgmxaxidlrlfmrhpkzmnxjtvdnopcgsiedvtfkltvplfcfflmwyqffktsmpezbxlnjegdlrcubwqvhxdammpkwkycrqtegepyxtohspeasrdtinjhbesilsvffnzznltsspjwuogdyzvanalohmzrywdwqqcukjceothydlgtocukc";

    Solution s;

    cout << s.longestPalindrome1(str) << endl;
    cout << s.longestPalindrome2(str) << endl;
    cout << s.longestPalindrome3(str) << endl;

    return 0;
}
