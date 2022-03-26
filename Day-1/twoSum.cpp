// name of Problem : Two Sum
// leetcode link of problem : https://leetcode.com/problems/two-sum/
// author : Dhruv Nagar


// brute-force Approch
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        
        for(int i=0; i<nums.size()-1; i++) {
            for(int j=i+1; j<nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
    }
};
// Time = O(n^2)
// Space = O(1)

// Hashmap Approch

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> val;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            int value = target - nums[i];
            if(val.find(value) != val.end()) {
                ans.emplace_back(i);
                ans.emplace_back(val[value]);
            }else {
                val[nums[i]] = i;
            }
        }
        return ans;
    }
};

// Time = O(n)
// Space = O(n)