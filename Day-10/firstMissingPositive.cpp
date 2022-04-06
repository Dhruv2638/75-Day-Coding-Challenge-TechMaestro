// name of Problem : First Missing Positive
// leetcode link of problem : https://leetcode.com/problems/first-missing-positive/
// author : Dhruv Nagar

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i<n; i++) {
            while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] -1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        for(int i = 0; i<n; i++) {
            if(i + 1 != nums[i]) {
                return i + 1;
            }
        }
        return n + 1;
    }
};

// Time = O(N)
// Space = O(1)