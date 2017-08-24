class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> ret = new ArrayList<Integer>();
        
        int counter = 0;
        
        // hashmap <char, counter>
        HashMap<Character, Integer> m = new HashMap<Character, Integer>();
        for (String word : words) {
            for (char c : word.toCharArray()) {
                if (!m.containsKey(c)) {
                    m.put(c, 1);
                } else {
                    m.put(c, m.get(c) + 1);
                }
            }
            
            counter += word.length();
        }
        
        // sliding window
        int left = 0;
        int right = 0;
        
        // condition for a solution
        int count = 0;
        
        while (right < s.length()) {
            char c = s.charAt(right);
            if (m.containsKey(c)) {
                m.put(c, m.get(c) - 1);
                if (m.get(c) >= 0) {
                    count ++;
                }
            }
            
            if (count == counter) {
                ret.add(left);
            }
            
            if (right - left + 1 == counter) {
                c = s.charAt(left);
                if (m.containsKey(c)) {
                    if (m.get(c) >= 0) {
                        count --;
                    }
                    m.put(c, m.get(c) + 1);
                }
                left ++;
            }
            
            right ++;
        }
        
        return ret;
    }
}
