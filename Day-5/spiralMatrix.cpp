// name of Problem : Spiral Matrix
// leetcode link of problem : https://leetcode.com/problems/spiral-matrix/
// author : Dhruv Nagar

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        
        if(matrix.size() == 0) return ans;
        
        int rowBegin = 0;
        int rowEnd = matrix.size() - 1;
        int columnBegin = 0;
        int columnEnd = matrix[0].size() - 1;
        
        while(rowBegin <= rowEnd && columnBegin <= columnEnd) {
            
            for(int i = columnBegin; i <= columnEnd; i++) {
                ans.push_back(matrix[rowBegin][i]);
            }
            
            rowBegin++;
            
            for(int i = rowBegin; i <= rowEnd; i++) {
                ans.push_back(matrix[i][columnEnd]);
            }
            
            columnEnd--;
            
            if(rowBegin <= rowEnd) {
                for(int i = columnEnd; i >= columnBegin; i--) {
                    ans.push_back(matrix[rowEnd][i]);
                }
            }
            
            rowEnd--;
            
            if(columnBegin <= columnEnd) {
                for(int i = rowEnd; i >= rowBegin; i--) {
                    ans.push_back(matrix[i][columnBegin]);
                }
            }
            
            columnBegin++;
        }
        return ans;
    }
};

//Time = O(N^2)
// Space = O(N)