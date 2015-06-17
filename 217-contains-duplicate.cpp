/*
  Source : https://leetcode.com/problems/contains-duplicate/
  Author : Alex Xu
  Date   : June 17, 2015
  Problem: 
  Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
  Tag    : Array HashTable
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty())
            return false;
        
        std::unordered_map<int, int> ht;
        
        
        for (int& e : nums) {
            if (ht.find(e) != ht.end())
                return true;
            ht[e] = e;
        }
        
        return false;
    }

    bool containsDuplicate2(vector<int>& nums) {
        if (nums.empty())
            return false;
        
        std::unordered_map<int, int> ht;
        
        
        for (int& e : nums) {
            if (ht.find(e) != ht.end())
                break;
            ht[e] = e;
        }
        
        return ht.size() < nums.size();
    }    
};
