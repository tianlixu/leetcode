/*
  Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
  Author : Alex Xu
  Date   : Jul 28, 2016
  Problem:
  Say you have an array for which the ith element is the price of a given stock on day i.
  Design an algorithm to find the maximum profit. You may complete at most two transactions.
  Note:
  You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

/* 
 Using solution from 53: get the maximum subarray, the following solution
 is functionally correct but fails with Time Limit Exceeded.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
            
        vector<int> profit(prices.size(), 0);
        for(int i=1; i<prices.size(); i++) {
            profit[i] = prices[i] - prices[i-1];
        }
        
        return helper(profit);
    }
    
    int helper(vector<int>& profit) {
        int maxSum = INT_MIN;
        for (int i=0; i<=profit.size()-1; i++) {
            vector<int> vecA(profit.begin(), profit.begin()+i);
            vector<int> vecB(profit.begin()+i+1, profit.end());
            
            maxSum = max(maxSum, maxSubArray(vecA) + maxSubArray(vecB));
        }
        
        return maxSum;
    }
    
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;                                      
        int f = 0;                                                 
        for (int i=0; i<nums.size(); i++) {                                                           f = std::max(f + nums[i], nums[i]);                                                       
            maxSum = std::max(f, maxSum);
        }                                                                                                                               
        return maxSum == INT_MIN ? 0 : maxSum;                                                                  
    }               
};

