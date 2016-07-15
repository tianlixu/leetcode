/*
  Source : https://leetcode.com/problems/house-robber/
  Author : Alex Xu
  Date   : Jul 15, 2016
  Problem:
 
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

/*
   0   1   2   3    i   5   6
a [1] [2] [8] [13] [4] [2] [7]
           |    |   |       
        dp(i-2) |   |   
             dp(i-1)|
                    |dp(i) = max(a[i] + dp(i-2), dp(i-1))
   
1. If there is only one house, just take it: a[0]
2. If there are two houses, then take the one with more money: max(a[0], a[1])
3. If there are three houses or more, you can
   either 
       rob a[i], which means you cannot rob a[i-1], so you get: a[i] + dp(i-2)
   or
       do not rob a[i], then you get: dp(i-1)

   Finally, the maximum for dp(i) is: max(a[i] + dp(i-2), dp(i-1))
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 0;

        if (len == 1)
            return nums[0];

        if (len == 2)
            return max(nums[0], nums[1]);

        nums[1] = max(nums[0], nums[1]);
        int i;
        for (i=2; i<nums.size(); i++) {
            nums[i] = max((nums[i] + nums[i-2]), nums[i-1]);
        }

        return nums[i-1];
    }
};

