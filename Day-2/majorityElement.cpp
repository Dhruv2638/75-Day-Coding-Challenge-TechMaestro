// name of Problem : Majority Element
// leetcode link of problem : https://leetcode.com/problems/majority-element/
// author : Dhruv Nagar

// Brute-force 

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i<n; i++) {
            int count = 1;
            for(int j = i + 1; j<n; j++) {
                if(nums[i] == nums[j]) count++;
            }
            
            if(count > n/2) return nums[i];
        }
        return -1;
    }
};

// Time = O(N^2)
// Space = O(1)


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mElement = nums[n/2];
        
        int f = 0;
        for(int i=0; i<n; i++) if(nums[i] == mElement) f++;
        if(f > n/2) return mElement;
        else return -1;
    }
};

// Time = O(NlogN)
// Space = O(1)

// Moore Voting Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int res = 0;
        int n = nums.size();
        for(int i = 1; i<n; i++) {
            if(nums[res] == nums[i]) {
                count++;
            }else {
                count--;
            }
            
            if(count == 0) {
                res = i;
                count = 1;
            }
        }
        return nums[res];
    }
};

// Time = O(N)
// Space = O(1)