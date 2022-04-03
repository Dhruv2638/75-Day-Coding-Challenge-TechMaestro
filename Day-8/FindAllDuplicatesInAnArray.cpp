// name of Problem : Find All Duplicates in an Array
// leetcode link of problem : https://leetcode.com/problems/find-all-duplicates-in-an-array/
// author : Dhruv Nagar

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> ans;
        
        for(int i = 0; i < n; i++) {
            int index = abs(nums[i]) - 1;
            if(nums[index] < 0) {
                ans.push_back(index + 1);
            }
            nums[index] = -nums[index];
        }
        return ans;
    }
};

// Time = O(N)
// Space = O(1)
