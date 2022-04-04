// name of Problem : K-diff Pairs in an Array
// leetcode link of problem : https://leetcode.com/problems/k-diff-pairs-in-an-array/
// author : Dhruv Nagar

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int cnt = 0;
        map<int, int> count;
        
        for(int i = 0; i<nums.size(); i++) {
            count[nums[i]]++;
        }
        
        for(auto ele : count) {
            if(k != 0) {
                int num = ele.first + k;
                if(count.find(num) != count.end()) {
                    cnt++;
                }
            }else {
                if(count[ele.first] >= 2) cnt++;
            }
        }
        return cnt;
    }
};

// Time = O(N)
// Space = O(N)