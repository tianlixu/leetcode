/*
 Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/
 Author : Alex Xu
 Date   : May 06, 2015
 Problem:
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

Solution:
Greedy algorithm, Time O(n), Space O(1)
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // hash table saves <character, index-of-character>
        std::unordered_map<char,int>  m;
        // length of the longest substring
        int length = 0;
        // the index of the first charcater for current substring
        int start = 0;
        int i=0;        
        
        while (i < s.length()) {
            if (m.find(s[i]) != m.end() && m[s[i]] >= start) {
                /*
                  a b c d e c f g
                  ^   ^     ^
                  |   |m[c] |i
                  |start
                 */
                start = m[s[i]] + 1;
            } else {
                length = max(length, i-start+1);
            }
            
            m[s[i]] = i;
            i++;
        }
        
        return length;
    }

    int lengthOfLongestSubstring2(string s) {
        // array to save the position for a given character, just like what a hash table does.
        int m[128];
        memset(m,-1,128*sizeof(int));
        
        // length of the longest substring
        int length = 0;
        // the index of the first charcater for current substring
        int start = 0;
        int i=0;        
        
        while (i < s.length()) {
            if (m[s[i]] >= start) {
                /*
                  a b c d e c f g
                  ^   ^     ^
                  |   |m[c] |i
                  |start
                 */
                start = m[s[i]] + 1;
            } else {
                length = max(length, i-start+1);
            }
            
            m[s[i]] = i;
            i++;
        }
        
        return length;
    }
};
