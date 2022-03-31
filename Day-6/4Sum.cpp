// name of Problem : 4Sum
// leetcode link of problem : https://leetcode.com/problems/4sum/
// author : Dhruv Nagar

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        // observations
        sort(nums.begin(), nums.end());
        // a + b + c + d = target
        // b + c + d = target - a
        // for every a i will find threesum for that
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int l = j + 1;
                int h = n - 1;
                
                int sum = target - (nums[i] + nums[j]);
                
                while(l < h) {
                    if(nums[l] + nums[h] == sum) {
                        vector<int> level;
                        level.push_back(nums[i]);
                        level.push_back(nums[j]);
                        level.push_back(nums[l]);
                        level.push_back(nums[h]);
                        
                        ans.push_back(level);
                        
                        while(l < h && nums[l] == nums[l+1]) l++;
                        while(l < h && nums[h] == nums[h-1]) h--;
                        
                        l++;
                        h--;
                    }else if(nums[l] + nums[h] < sum) {
                        l++;
                    }else h--;
                }
                while(j +1 < n && nums[j] == nums[j+1]) j++;
            }
            while(i + 1 < n && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};

// Time = O(N^3)
// Space = O(1) // Not counted ans vector in space