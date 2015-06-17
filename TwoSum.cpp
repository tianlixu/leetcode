/*
 Source : https://oj.leetcode.com/problems/two-sum/
 Author : Alex Xu
 Date   : Jan 06, 2015
  
 Given an array of integers, find two numbers such that they add up to a specific target number.

 The function twoSum should return indices of the two numbers such that they add up to the target,
 where index1 must be less than index2.
 Please note that your returned answers (both index1 and index2) are not zero-based.

 You may assume that each input would have exactly one solution.

 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1=1, index2=2
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    // Time: O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> v;
        std::unordered_map<int, int> ht;

        for (int i=0; i<nums.size(); ++i) {
            if (ht.find(nums[i]) == ht.end()) {
                ht[target - nums[i]] = i;
            } else {
                v.push_back(ht[nums[i]] + 1);
                v.push_back(i+1);
            }
        }

        return v;        
    }

    // Time: O(n^2)
    vector<int> twoSum(vector<int> &numbers, int target) {
        std::vector<int> v;

        for (int i=0; i<numbers.size()-1; ++i) {
            for (int j=i+1; j<numbers.size(); ++j) {
                if (numbers[i] + numbers[j] == target) {
                    v.push_back(i+1);
                    v.push_back(j+1);
                }                    
            }
        }

        return v;
    }    
};

int main()
{
//    int a[] = {2, 7, 9, 13, -8, 20};
    int a[] = {3, 2, 4};
    int length = sizeof(a) / sizeof(a[0]);

    std::vector<int> v(a, a+length);
    Solution s;
    //std::vector<int> result = s.twoSum(v, 1);
    std::vector<int> result = s.twoSum2(v, 6);

    cout << "index1=" << result[0] << " Index2=" << result[1] << endl;
                       
    return 0;
}
