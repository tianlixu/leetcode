/*
  Source : https://leetcode.com/problems/maximum-product-subarray/
  Author : Alex Xu
  Date   : Jul 28, 2016
  Problem:
  Find the contiguous subarray within an array (containing at least one number) which has the largest product.

  For example, given the array [2,3,-2,4],
  the contiguous subarray [2,3] has the largest product = 6.

  Tag: DP
  Solution: 
  dpmax(n) = max(dpmax(n-1)*n, dpmin(n-1)*n, n)
  dpmin(n) = min(dpmax(n-1)*n, dpmin(n-1)*n, n)
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty())
            return 0;

        int lmin=nums[0]; // local min up to here
        int lmax=nums[0]; // local max up to here
        int gmax=nums[0]; // global max

        for( int i=1;i<nums.size();i++) {
            int t1 = nums[i]*lmax;
            int t2 = nums[i]*lmin;

            lmax = max( max(t1,t2), nums[i] );
            lmin = min( min(t1,t2), nums[i]);
            gmax =max(gmax, lmax);
        }

        return gmax;
    }
};
