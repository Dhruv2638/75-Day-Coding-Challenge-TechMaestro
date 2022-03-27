// name of Problem : Pascal's Triangle
// leetcode link of problem : https://leetcode.com/problems/pascals-triangle/
// author : Dhruv Nagar

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        for(int i = 0; i<numRows; i++) {
            vector<int> row;
            
            for(int j = 0; j<=i; j++) {
                if(j == 0 || j == i) {
                    row.push_back(1);
                }else{
                    row.push_back(ans[i-1][j-1] + ans[i-1][j]);
                }
            }
            ans.push_back(row);
        }
        return ans;
    }
};

// Time = O(N^2)
// Space = O(1) // Not counted space for ans and row vector