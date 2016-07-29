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
        for (int i=0; i<nums.size(); i++) {  
            f = std::max(f + nums[i], nums[i]);                                                       
            maxSum = std::max(f, maxSum);
        }                                                                                                                               
        return maxSum == INT_MIN ? 0 : maxSum;                                                                      }               
};

/*
  From a financial point of view, you should guarantee that you have the maximum money left in your pocket at any moment.
  As an investor, the more money left, the happier you are.

  For each Transaction, you Buy it(spend money price[i]: your current money - prices[i])
  and then you Sell it(earn money price[i]: your current money + prices[i])

  The profit after B1:  0 - price[i]
  The profit after S1: B1 + price[i]
  The profit after B2: S1 - price[i]
  The profit after S2: B2 + price[i]

  So, max(B2) is the solution for this problem.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int s1 = 0;       // the money you have after s1
        int s2 = 0;       // the money you have after s2
        int b1 = INT_MIN; // the money you have after b1
        int b2 = INT_MIN; // the money you have after b2

        for (int price : prices) {
            b1 = max(b1, 0  - price);
            s1 = max(s1, b1 + price);
            b2 = max(b2, s1 - price);
            s2 = max(s2, b2 + price);
        }
        return s2;
    }
};
