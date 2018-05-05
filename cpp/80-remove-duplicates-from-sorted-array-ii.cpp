#include <iostream>
using namespace std;

/*
  Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
  Author : Alex Xu
  Date   : June 18, 2015
  Problem:

  Follow up for "Remove Duplicates":
  What if duplicates are allowed at most twice?

  For example,
  Given sorted array nums = [1,1,1,2,2,3],

  Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

  Tag : Array TwoPointers
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return removeDuplicates(nums, 2);
    }
    
    int removeDuplicates(vector<int>& nums, int keep) {
        if (nums.empty())
            return 0;
            
        if (nums.size() < keep)
            return nums.size();
            
        int cursor = keep;
        for (int i=keep; i< nums.size(); ++i) {
            if (nums[i] != nums[cursor - keep])
                nums[cursor++] = nums[i];
        }
        
        return cursor;
    }
};

int rmvDup(int a[], unsigned int len, int keep)
{
    if (len <= keep) {
        return len;
    }
        
    int cursor = keep;
    for (int i=keep; i<len; i++) {
        if (a[i] != a[cursor - keep]) {
            a[cursor++] = a[i];
        }
    }

    return cursor;
}
