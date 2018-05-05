/*
  Source : https://leetcode.com/problems/longest-common-prefix/
  Author : Alex Xu
  Date   : June 16, 2015
  Problem: 
  Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        
        if (strs.empty())
            return result;
        
        string &s0 = strs[0];
        
        int minLen = s0.size();
        for (int i=1; i<strs.size(); i++) {
            minLen = strs[i].size() < minLen ? strs[i].size() : minLen;
        }
        
        if (minLen == 0)
            return result;

        int pos = 0;        
        while (true) {
            char ch = s0[pos];
            
            int i=1;
            while (i < strs.size()) {
                string s = strs[i];
                if (ch != s[pos])
                    break;
                i++;
            }
        
            // Not reached the last string in strs[]
            if (i != strs.size())
                break;
            
            pos++;
            if (pos == minLen)
                break;
        }
        
        return s0.substr(0, pos);
    }
};
