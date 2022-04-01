// name of Problem : Jump Game II
// leetcode link of problem : https://leetcode.com/problems/jump-game-ii/
// author : Dhruv Nagar


class Solution {
public:
    int solve(int start, vector<int> &nums, vector<int> &dp) {
        if(start >= nums.size() - 1) {
            return 0;
        }
        if(dp[start] != -1) return dp[start];
        int minSteps = 1e8;
        for(int i = start + 1; i <= start + nums[start]; i++) {
            minSteps = min(minSteps, 1 + solve(i, nums, dp));
        }
        
        return dp[start] = minSteps;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(0, nums, dp);   
    }
};

// Time = O(N * k)
// Space = O(N)

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        int jumps = 0, currEnd = 0, nextEnd = 0;
        
        for(int i = 0; i < n - 1; i++) {
            nextEnd = max(nextEnd, i + nums[i]);
            
            if(i == currEnd) {
                jumps++;
                currEnd = nextEnd;
            }
        }
        return jumps;
    }
};

// Time = O(N)
// Space = O(1 )