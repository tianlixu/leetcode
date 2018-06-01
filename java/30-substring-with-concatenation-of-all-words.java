/*
  Source : https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
  Author : Alex Xu
  Date   : August 24, 2017
  Problem:
  You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

  For example, given:
  s: "barfoothefoobarman"
  words: ["foo", "bar"]

  You should return the indices: [0,9].
  (order does not matter).

*/

class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> ret = new ArrayList<>();

        if (s == null || s.isEmpty() || words == null || words.length == 0) {
            return ret;
        }

        int size = 0; // fixed window size for each try
        HashMap<String, Integer> m = new HashMap<>();
        for (String word : words) {
            if (word == null || word.isEmpty()) {
                continue;
            }

            if (!m.containsKey(word)) {
                m.put(word, 1);
            } else {
                m.put(word, m.get(word) + 1);
            }

            size += word.length();
        }

        if (size == 0 || s.length() < size) {
            return ret;
        }

        // sliding window, fixed size
        int left = 0;

        int length = words[0].length(); // word length
        while (s.length() - left >= size) {
            HashMap<String, Integer> m2 = new HashMap<>(m);

            for (int i=0; i<words.length; i++) {
                String aWord = s.substring(left + i*length, left + (i+1)*length);
                if (!m2.containsKey(aWord)) {
                    break;
                }

                if (m2.get(aWord) <= 0) {
                    break;
                }

                m2.put(aWord, m2.get(aWord) - 1);
                if (i + 1 == words.length) { // find a solution
                    ret.add(left);
                }
            }

            left ++;
        }

        return ret;
    }
}

