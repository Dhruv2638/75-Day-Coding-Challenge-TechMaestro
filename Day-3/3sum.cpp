// name of Problem : 3sum
// leetcode link of problem : https://leetcode.com/problems/3sum/
// author : Dhruv Nagar

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int ind = 0, left = 1, right = nums.size() - 1;

        for (ind = 0; ind < (int)(nums.size()) - 2; ind++)
        {
            if ((ind == 0) || (ind > 0 && nums[ind] != nums[ind - 1]))
            {
                left = ind + 1, right = (int)(nums.size()) - 1;
                int a = 0 - (nums[ind]);
                while (left < right)
                {
                    if (nums[left] + nums[right] == a)
                    {
                        vector<int> vec;
                        vec.push_back(nums[ind]);
                        vec.push_back(nums[left]);
                        vec.push_back(nums[right]);
                        ans.push_back(vec);

                        while (left < right && (nums[left] == nums[left + 1]))
                            left++;
                        while (left < right && (nums[right] == nums[right - 1]))
                            right--;

                        left++, right--;
                    }
                    else if (nums[left] + nums[right] < a)
                    {
                        ++left;
                    }
                    else
                    {
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};

// Time = O(N^2)
// Space = O(N)