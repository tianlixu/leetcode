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

/*
 * a group id identified by a unique key, how to get/generate that key? hash!
 * The problems now becomes how to has a string.
 *
 * use prime number multiplication
 * Note: This solution will fail for large inputs
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

// sorted strings as the key
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> ret = new ArrayList<List<String>>();
        HashMap<String, List<String>> m = new HashMap<>();

        for (String s : strs) {
            char[] a = s.toCharArray();
            Arrays.sort(a);
            String k = String.valueOf(a);

            if (!m.containsKey(k)) {
                List<String> l = new ArrayList<String>();
                l.add(s);
                m.put(k, l);
                ret.add(l);
            } else {
                List<String> l = m.get(k);
                l.add(s);
            }
        }

        return ret;
    }
}
