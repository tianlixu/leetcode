/*
 Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/
 Author : Alex Xu
 Date   : August 08, 2017
 Problem:
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

Solution:
Greedy algorithm, Time O(n), Space O(1)
*/

public class Solution {
    public int lengthOfLongestSubstring(String s) {
        // substring s[i, j] is the answer
        int i = 0;
        int j = 0;

        int ret = 0;
        HashMap<Character, Integer> m = new HashMap<Character, Integer>();

        while (j < s.length()) {
            if (m.containsKey(s.charAt(j))) {
                i = Math.max(m.get(s.charAt(j)) + 1, i);
            }

            ret = Math.max(ret, j-i+1);
            m.put(s.charAt(j), j);

            j++;
        }

        return ret;
    }
}
