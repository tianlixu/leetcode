/*
  Source : https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
  Author : Alex Xu
  Date   : August 16, 2017
  Problem:
  Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

  Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

  The order of output does not matter.

  Example 1:

  Input:
  s: "cbaebabacd" p: "abc"

  Output:
  [0, 6]

  Explanation:
  The substring with start index = 0 is "cba", which is an anagram of "abc".
  The substring with start index = 6 is "bac", which is an anagram of "abc".
  Example 2:

  Input:
  s: "abab" p: "ab"

  Output:
  [0, 1, 2]

  Explanation:
  The substring with start index = 0 is "ab", which is an anagram of "ab".
  The substring with start index = 1 is "ba", which is an anagram of "ab".
  The substring with start index = 2 is "ab", which is an anagram of "ab".

*/

public class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> ret = new ArrayList<>();
        if (s == null || p == null || s.length() == 0 || p.length() == 0 || s.length() < p.length()) {
            return ret;
        }

        // hash array
        int[] h = new int[256];
        for (char c : p.toCharArray()) {
            h[c] ++;
        }

        // sliding window [left, right]
        int left = 0;
        int right = 0;
        int count = 0;

        while (right < s.length()) {
            // move one char into the window from right, decrease its value by one
            h[s.charAt(right)] --;
            if (h[s.charAt(right)] >= 0) {
                // if this char still belongs to 'p'
                count ++;
            }

            // find a solution
            if (count == p.length()) {
                ret.add(left);
            }

            // if window is full, window.size = p.length, move one char out of the window from left
            if (right - left == p.length() - 1) {
                if (h[s.charAt(left)] >= 0) {
                    // if this char belongs to 'p'
                    count --;
                }

                // recover the hash value
                h[s.charAt(left)] ++;
                // adjust window, moving one char forward from left
                left ++;
            }

            // adjust window, moving one char forward from right
            right ++;
        }

        return ret;
    }
}

// sliding window with hashmap
public class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> ret = new ArrayList<>();
        if (s == null || p == null || s.length() == 0 || p.length() == 0 || s.length() < p.length()) {
            return ret;
        }

        // hash maps, Key: character, Value: counter of its appearance
        HashMap<Character, Integer> m = new HashMap<Character, Integer>();
        for (char c : p.toCharArray()) {
            if (m.containsKey(c)) {
                m.put(c, m.get(c) + 1);
            } else {
                m.put(c, 1);
            }
        }

        // sliding window [left, right]
        int left = 0;
        int right = 0;
        int count = 0;

        while (right < s.length()) {
            // move one char into the window from right
            char c = s.charAt(right);
            if (m.containsKey(c)) {
                // decrease its value by one
                m.put(c, m.get(c) - 1);
                // if this char still belongs to 'p'
                if (m.get(c) >= 0) {
                    count ++;
                }
            }

            if (count == p.length()) {
                ret.add(left);
            }

            // if window is full, window.size = p.length, move one char out of the window from left
            if (right - left == p.length() - 1) {
                c = s.charAt(left);
                if (m.containsKey(c)) {
                    // if this char belongs to 'p'
                    if (m.get(c) >= 0) {
                        count --;
                    }
                    // recover the hash value
                    m.put(c, m.get(c) + 1);
                }

                // adjust window, moving one char forward from left
                left ++;
            }

            // adjust window, moving one char forward from right
            right ++;
        }

        return ret;
    }
}
