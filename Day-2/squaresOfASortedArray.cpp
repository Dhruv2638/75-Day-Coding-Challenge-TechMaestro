// name of Problem : Squares of a Sorted Array
// leetcode link of problem : https://leetcode.com/problems/squares-of-a-sorted-array/
// author : Dhruv Nagar


// Brute-force
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i<n; i++) {
            nums[i] = nums[i] * nums[i];
        }
        
        sort(nums.begin(), nums.end());
        return nums;
    }
};

// Time = O(NlogN)
// Space = O(1)

// Optimized
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        int lo = 0;
        int hi = n - 1, res = n - 1;
        
        while(lo <= hi) {
            if(abs(nums[lo]) < abs(nums[hi])) {
                ans[res--] = nums[hi] * nums[hi];
                hi--;
            }else {
                ans[res--] = nums[lo] * nums[lo];
                lo++;
            }
        }
        return ans;
    }
};

// Time = O(N)
// Space = O(1)