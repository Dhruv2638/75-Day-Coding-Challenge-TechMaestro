// name of Problem : Subsets
// leetcode link of problem : https://leetcode.com/problems/subsets/
// author : Dhruv Nagar

class Solution {
public:
    void findSubsets(vector<int> &nums, int index, vector<vector<int>> &ans, vector<int> ds) {
        if(index >= nums.size()) {
            ans.push_back(ds);
            return;
        }
        
        // Exclude
        findSubsets(nums, index + 1, ans, ds);
        
        // include
        ds.push_back(nums[index]);
        findSubsets(nums, index + 1, ans, ds);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int i = 0;
        findSubsets(nums, i, ans, ds);
        
        return ans;
    }
};

// Time = O(2^N)
// Space = O(N)