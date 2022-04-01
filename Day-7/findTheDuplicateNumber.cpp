// name of Problem : Find the Duplicate Number
// leetcode link of problem : https://leetcode.com/problems/find-the-duplicate-number/
// author : Dhruv Nagar

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> count(nums.size(), 0);
        int n = nums.size();
        for(int i=0; i<n; i++) {
            count[nums[i]]++;
        }
        
        for(int i=0; i<n; i++) {
            if(count[i] >= 2){
                return i;
            }
        }
        return 0;
    }
};

// Time = O(N)
// Space = O(N)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(fast != slow);
        
        fast = nums[0];
        
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

// Time = O(N)
// Space = O(1)