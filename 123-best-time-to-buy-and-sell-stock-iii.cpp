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


/*
https://discuss.leetcode.com/topic/50933/8ms-c-solution-o-n-time-o-1-space
https://discuss.leetcode.com/topic/41049/clear-c-solution/3
https://discuss.leetcode.com/topic/39751/my-explanation-for-o-n-solution

First assume that we have no money, so buy1 means that we have to borrow money from others, we want to borrow less so that we have to make our balance as max as we can(because this is negative).

    sell1 means we decide to sell the stock, after selling it we have price[i] money and we have to give back the money we owed, so we have price[i] - |buy1| = prices[i ] + buy1, we want to make this max.

    buy2 means we want to buy another stock, we already have sell1 money, so after buying stock2 we have buy2 = sell1 - price[i] money left, we want more money left, so we make it max

    sell2 means we want to sell stock2, we can have price[i] money after selling it, and we have buy2 money left before, so sell2 = buy2 + prices[i], we make this max.

    So sell2 is the most money we can have.

    Hope it is helpful and welcome quesions!

public int maxProfit(int[] prices) {
    int sell1 = 0, sell2 = 0, buy1 = Integer.MIN_VALUE, buy2 = Integer.MIN_VALUE;
    for (int i = 0; i < prices.length; i++) {
        buy1 = Math.max(buy1, -prices[i]);
        sell1 = Math.max(sell1, buy1 + prices[i]);
        buy2 = Math.max(buy2, sell1 - prices[i]);
        sell2 = Math.max(sell2, buy2 + prices[i]);
    }
    return sell2;
}
*/
