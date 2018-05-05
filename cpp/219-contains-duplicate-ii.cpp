/*
  Source : https://leetcode.com/problems/contains-duplicate-ii/
  Author : Alex Xu
  Date   : June 17, 2015
  Problem: 
  Given an array of integers and an integer k, find out whether there there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
  Tag    : Array HashTable
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
          if (nums.empty())
              return false;
              
        std::unordered_map<int, int> ht;
        
        for (int i=0; i<nums.size(); ++i) {
            auto got = ht.find(nums[i]);
            if (got == ht.end()) {
                ht[nums[i]] = i;
                continue;
            }
            
            if (i - got->second <= k)
                return true;
            else 
                ht[nums[i]] = i; // need to update the last occurance
        }
        
        return false;
    }
};
