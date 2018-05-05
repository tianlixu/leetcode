/*
  Source : https://leetcode.com/problems/house-robber-ii/
  Author : Alex Xu
  Date   : Jul 28, 2016
  Problem:
 
  After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

  Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

/*
  Tag: DP
  Solution:
  Continue with 198-house-robber, the solution for this problem is quite straightforward:

  Since you cannot rob both the first and the last house because they are neighbours, just create two seperate vectors, one excluding the first house, and the other  excluding the last house. The best solution generates from these two vectors using the original solution for 198.

  1, 2, 3, 4,...,n
  A: if you rob 1, then you cannot rob n, it becomes problem 198 to find solution for 1, 2,..., n-1
  B: if you do not rob 1, then, it becomes problem 198 to find solution for  2,..., n
  The max(A, B) becomes the final solution for this problem.
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

        vector<int> numsA(nums.begin() + 1, nums.end());
        vector<int> numsB(nums.begin(), nums.end()-1);

        return max(rob1(numsA), rob1(numsB));
    }

    int rob1(vector<int>& nums) {
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
