/*
  Source : https://leetcode.com/problems/word-pattern/
  Author : Alex Xu
  Date   : Oct 07, 2015
  Problem:
  Given a pattern and a string str, find if str follows the same pattern.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
patterncontains only lowercase alphabetical letters, and str contains words separated by a single space. Each word in str contains only lowercase alphabetical letters.
Both pattern and str do not have leading or trailing spaces.
Each letter in pattern must map to a word with length that is at least 1.
*/

class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        str = str.split()

        if len(pattern) != len(str) :
            return False

        dict = {}
        for (p, s) in zip(pattern, str):
            if p in dict and dict[p] != s:
                    return False # key exists but with different value
            if p not in dict and s in dict.values():
                    return False # key does not exist but value already exists
            dict[p] = s

        return True
