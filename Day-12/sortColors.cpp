// name of Problem : Sort Colors
// leetcode link of problem : https://leetcode.com/problems/sort-colors/
// author : Dhruv Nagar

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return;
        
        int start = 0;
        int end = nums.size() - 1;
        int current = 0;
        
        while(start < end && current <= end) {
            if(nums[current] == 0) {
                nums[current] = nums[start];
                nums[start] = 0;
                current++;
                start++;
            } else if(nums[current] == 2)  {
                nums[current] = nums[end];
                nums[end] = 2;
                end--;
            }else current++;
        }
    }
};

// Time = O(N)
// Space = O(1)