// name of Problem : Subarray Sum Equals K
// leetcode link of problem : https://leetcode.com/problems/subarray-sum-equals-k/
// author : Dhruv Nagar

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0) return 0;
        
        unordered_map<int, int> mpp;
        int curSum = 0;
        int i = 0, count = 0;
        
        while(i < n) {
            curSum += nums[i];
            
            if(curSum == k) count++;
            
            if(mpp.find(curSum - k) != mpp.end()) {
                count += mpp[curSum-k];
            }
            mpp[curSum]++;
            i++;
        }
        return count;
    }
};

// Time = O(N)
// Space = O(N)
