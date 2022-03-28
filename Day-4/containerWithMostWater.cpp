// name of Problem : Container With Most Water
// leetcode link of problem : https://leetcode.com/problems/container-with-most-water/
// author : Dhruv Nagar

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int i = 0, j = height.size()-1;
        
        while(i < j) {
            maxArea = max(maxArea, min(height[i], height[j]) * (j-i));
            if(height[i] < height[j]) {
                i++;
            }else j--;
        }
        return maxArea;
    }
};

// Time = O(N)
// Space = O(1)