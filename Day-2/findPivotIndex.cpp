// name of Problem : Find Pivot Index
// leetcode link of problem : https://leetcode.com/problems/find-pivot-index/
// author : Dhruv Nagar

// Brute-force

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftsum, rightsum;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {    

            /* get left sum */
            leftsum = 0;
            for (int j = 0; j < i; j++)
                leftsum += nums[j];

            /* get right sum */
            rightsum = 0;
            for (int j = i + 1; j < n; j++)
                rightsum += nums[j];

            if (leftsum == rightsum)
                return i;
        }

        return -1;
    } 
};

// Time = O(N^2)
// Space = O(1)

class Solution {
public:
    int pivotIndex(vector<int>& arr) {
        int totalSum = 0;
        int n = arr.size();
        for(int i=0; i<n; i++) {
            totalSum += arr[i];
        }
        int leftSum = 0;
        for(int i=0; i<n; i++) {
            if(leftSum == totalSum - arr[i]) {
                return i;
            }else{
                leftSum += arr[i];
                totalSum -= arr[i];
            }
        }
        return -1;
    }
};

// Time = O(N)
// Space = O(1)