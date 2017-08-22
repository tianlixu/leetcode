/*
  Source : https://leetcode.com/problems/group-anagrams/description/
  Author : Alex Xu
  Date   : August 21, 2017
  Problem:
  Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.

*/

    class Solution {
        public List<List<String>> groupAnagrams(String[] strs) {
            // https://primes.utm.edu/lists/small/1000.txt
            int[] prime = {
                2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
                31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 
                73, 79, 83, 89, 97, 101
            };
        
            List<List<String>> ret = new ArrayList<List<String>>();
            HashMap<Integer, List<String>> m = new HashMap<>();
        
            for (String s : strs) {
                int key = 1;
                for (char c : s.toCharArray()) {
                    key *= prime[c - 'a'];    
                }
            
                List<String> l = null;
                if (!m.containsKey(key)) {
                    l = new ArrayList<String>();
                    m.put(key, l);
                    ret.add(l);                    
                } else {
                    l = m.get(key);
                }
            
                l.add(s);
            }
        
            return ret;
        }
    }