// name of Problem : 3Sum Closest
// leetcode link of problem : https://leetcode.com/problems/3sum-closest/
// author : Dhruv Nagar

// Brute force approch we just use 3 for and find sum closest to it
// Time = O(N^3)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int result = nums[0] + nums[1] + nums[n-1];
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n - 2; i++) {
            int lo = i + 1;
            int hi = n - 1;
            
            while(lo < hi) {
                int curSum = nums[i] + nums[lo] + nums[hi];
                if(curSum > target) {
                    hi--;
                }else lo++;
                
                if(abs(curSum - target) < abs(result - target)) {
                    result = curSum;
                }
            }
        }
        return result;
    }
};

// Time = O(N^2)
// Space = O(1)