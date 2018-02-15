/*
  Source : https://leetcode.com/problems/valid-anagram/description/
  Author : Alex Xu
  Date   : August 09, 2017
  Problem:
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/

public class Solution {
    public boolean isAnagram(String s, String t) {
        char[] alphabetS = getAlphabet(s);
        char[] alphabetT = getAlphabet(t);
        
        return Arrays.equals(alphabetS, alphabetT);
    }
    
    public char[] getAlphabet(String s) {
        char[] alphabet = new char[26];
        
        for (int i=0; i<s.length(); i++) {
            ++ alphabet[s.charAt(i) - 'a'];
        }
        
        return alphabet;
    }

    /**
     *
     * Solution 2 with only one HashMap:
     * key is the s[i]/t[i]
     * value: for s[i], ++1; for t[i], --1
     * 
     * if all values are 0, then return true; otherwise return false
     * 
     */
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }

        HashMap<Character, Integer> m = new HashMap<Character, Integer>();

        for (int i=0; i<s.length(); i++) {
            char sChar = s.charAt(i);
            char tChar = t.charAt(i);

            if (m.get(sChar) == null) {
                m.put(sChar, 1); // default 1
            } else {
                m.put(sChar, m.get(sChar) + 1);
            }

            if (m.get(tChar) == null) {
                m.put(tChar, -1); // default -1
            } else {
                m.put(tChar, m.get(tChar) - 1);
            }
        }

        for (Map.Entry<Character, Integer> entry : m.entrySet()) {
            if (entry.getValue() != 0) {
                return false;
            }
        }
        return true;
    }
}

