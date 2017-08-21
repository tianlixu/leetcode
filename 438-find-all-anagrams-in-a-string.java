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

            int[] h = new int[256];
            for (char c : p.toCharArray()) {
                h[c] ++;
            }

            int left = 0;
            int right = 0;
            int count = 0;
            while (right < s.length()) {
                h[s.charAt(right)] --;
                if (h[s.charAt(right)] >= 0) {
                    count ++;
                }
                right ++;

                if (count == p.length()) {
                    ret.add(left);
                }

                if (right - left == p.length()) {
                    if (h[s.charAt(left)] >= 0) {
                        count --;
                    }

                    h[s.charAt(left)] ++;
                    left ++;
                }
            }

            return ret;
        }
    }

    public class Solution {
        public List<Integer> findAnagrams(String s, String p) {
            // Key: character, Value: counter of its appearance
            HashMap<Character, Integer> m = new HashMap<Character, Integer>();

            for (int i=0; i< p.length(); i++) {
                if (m.containsKey(p.charAt(i))) {
                    m.put(p.charAt(i), m.get(p.charAt(j)) + 1);
                } else {
                    m.put(p.charAt(i), 1);
                }
            }

            HashMap<Character, Integer> m2 = new HashMap<Character, Integer>();
            m2.putAll(m);

            for (int i=0, int j=0; j<s.length(); j++) {
                if (! m2.containsKey(s.charAt(j))) {
                    continue;
                }

                int v = m2.get(s.charAt(j));
                if (v == 0) {
                    ++i;
                }
                
            }
        }
    }
