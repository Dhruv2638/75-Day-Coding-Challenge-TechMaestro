// name of Problem : Best Time to Buy and Sell Stock III
// leetcode link of problem : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// author : Dhruv Nagar

class Solution {
public:
    int f(int index, int buy, int cap, vector<int> &prices, int n, vector<vector<vector<int>>> &dp) {
        if(cap == 0 || index == n){
            return 0;
        }
        // int max_profit = 0;
    	if(dp[index][buy][cap] != -1) return dp[index][buy][cap];
        if(buy == 1) {
            return dp[index][buy][cap] = max(-prices[index] + f(index + 1, 0, cap, prices, n, dp), 0 + f(index + 1, 1, cap, prices, n, dp));
        }
        return dp[index][buy][cap] = max(prices[index] + f(index + 1, 1, cap - 1, prices, n, dp), 0 + f(index + 1, 0, cap, prices, n, dp));
        
}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
        return f(0, 1, 2, prices, n, dp);
    }
};

// Time = O(N*2*3)
// Space = O(N*2*3)