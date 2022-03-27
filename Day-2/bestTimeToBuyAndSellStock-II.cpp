// name of Problem : Best Time to Buy and Sell Stock II
// leetcode link of problem : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// author : Dhruv Nagar

// DP With Memoization

class Solution {
public:
    long solve(int index, int buy, vector<int> &values, int n, vector<vector<long>> &dp)     {
        if(index == n) return 0;
        long profit = 0;
        if(dp[index][buy] != -1) return dp[index][buy];
        if(buy) {
            profit = max(-values[index] + solve(index+1, 0, values, n, dp), 
                        0 + solve(index+1, 1, values, n, dp));
        }else {
            profit = max(values[index] + solve(index+1, 1, values, n, dp),
                        0 + solve(index+1, 0, values, n, dp));
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>> dp(n, vector<long> (2, -1));
        
        return solve(0, 1, prices, n, dp);
    }
};

// Time = O(2^N)
// Space = O(N)


// Optimized Approch

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        
        for(int i=1; i<prices.size(); i++)  {
            if(prices[i] > prices[i-1]) {
                profit += prices[i] - prices[i-1];
            }
        }
        return profit;
    }
};

// Time = O(N)
// Space = O(1)