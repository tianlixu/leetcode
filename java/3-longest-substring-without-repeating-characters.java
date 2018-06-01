/*
 Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/
 Author : Alex Xu
 Date   : August 08, 2017
 Problem:
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

Solution:
sliding window, Time O(n), Space O(1)
Tag: sliding window, hash
*/

public class Solution {
    public int lengthOfLongestSubstring(String s) {
        // substring s[i, j] is the answer, and ret is its length "ret = j-i+1"
        int i = 0;
        int j = 0;
        int ret = 0;

        // HashMap saves a character(key) and its index
        HashMap<Character, Integer> m = new HashMap<>();

        while (j < s.length()) {
            if (m.containsKey(s.charAt(j))) {
                /* If s[j] has a duplicate in the range [i,j) with index j' :
                 *     j' = m.get(s.charAt(j))
                 * skip all the elements in the range [i,j'] and move i to j'+1 directly.
                 * i and j moves from left to right, will never move back.
                 */
                i = Math.max(m.get(s.charAt(j)) + 1, i);
            }

            ret = Math.max(ret, j-i+1);
            m.put(s.charAt(j), j);
            j++;
        }

        return ret;
    }
}
