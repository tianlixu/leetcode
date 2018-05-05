/*
  Source : https://leetcode.com/problems/reverse-linked-list/
  Author : Alex Xu
  Date   : May 28, 2015
  Problem:
  Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

  You may assume that the array is non-empty and the majority element always exist in the array.
*/

class Solution {
public:
    int majorityElement1(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[(nums.size()/2)];
    }
    
    int majorityElement2(vector<int>& nums) {
        unordered_map<int, int> m;
        
        for (int i=0; i<nums.size(); i++) 
            m[nums[i]] = ++m[nums[i]];
        
        for ( auto it = m.begin(); it != m.end(); ++it ) {
            if (it->second > nums.size()/2)
                return it->first;
        }
    }

    /* other good solutions posted on leetcode, check it out */
};

