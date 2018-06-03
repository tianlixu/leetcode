/*
  Source : https://leetcode.com/problems/minimum-window-substring/description/
  Author : Alex Xu
  Date   : August 23, 2017
  Problem:
  Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

  For example,
  S = "ADOBECODEBANC"
  T = "ABC"
  Minimum window is "BANC".

  S = "aba"
  T = "aa"
  Minimum window is "aba".

  S = "a"
  T = "aa"
  Minimum window is "".

  Note:
  If there is no such window in S that covers all characters in T, return the empty string "".

  If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

*/

/*
 * sliding window 
 */
class Solution {
    public String minWindow(String s, String t) {
        String ret = "";
        int len = Integer.MAX_VALUE;

        HashMap<Character, Integer> m = new HashMap<>();
        for (char c : t.toCharArray()) {
            // count the number of appearance of each char
            if (m.containsKey(c)) {
                m.put(c, m.get(c) + 1);
            } else {
                m.put(c, 1);
            }
        }


        // sliding window
        int left = 0;
        int right = 0;

        // condition for a solution, count == m.size()
        int count = 0;

        while (right < s.length()) {
            char c = s.charAt(right);
            if (m.containsKey(c)) {
                m.put(c, m.get(c) - 1);
                if (m.get(c) == 0) {
                    count ++;
                }
            }

            while(count == m.size()) { // find a solution
                if (right - left + 1 < len) {
                    len = right - left + 1;
                    /*
                     * public String substring(int beginIndex, int endIndex)
                     * Returns a new string that is a substring of this string.
                     * The sbstring begins at the specified beginIndex and extends
                     * to the character at index endIndex - 1. Thus the length of
                     * the substring is endIndex-beginIndex.
                     *
                     * Parameters:
                     * beginIndex - the beginning index, inclusive.
                     * endIndex - the ending index, exclusive.
                     */
                    ret = s.substring(left, right + 1);
                }

                c = s.charAt(left);
                if (m.containsKey(c)) {
                    if (m.get(c) == 0) {
                        count --;
                    }
                    m.put(c, m.get(c) + 1);
                }

                // for each loop, shrink window bye one char from left
                left ++;
            }

            // for each loop, increase window by one char
            right ++;
        }

        return ret;
    }
}
