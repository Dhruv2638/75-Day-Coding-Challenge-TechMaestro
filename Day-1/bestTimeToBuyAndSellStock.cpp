// name of Problem : Best Time to Buy and Sell Stock
// leetcode link of problem : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// author : Dhruv Nagar

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int miniTillI = prices[0];
        
        for(int i=1; i<prices.size(); i++) {
            int cost = prices[i] - miniTillI;
            profit = max(profit, cost);
            miniTillI = min(miniTillI, prices[i]);
        }
        return profit;
    }
};

// Time = O(n)
// space = O(1)
