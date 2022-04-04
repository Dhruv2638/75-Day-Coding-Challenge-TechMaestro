// name of Problem : Jump Game
// leetcode link of problem : https://leetcode.com/problems/jump-game/
// author : Dhruv Nagar

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        int lastGoodIndex = nums.size() - 1;
        
        for(int i = n - 2; i>=0; i--) {
            if(i + nums[i] >= lastGoodIndex) {
                lastGoodIndex = i; 
            }
        }
        return lastGoodIndex == 0;
    }
};

// Time = O(N)
// Space = O(1)