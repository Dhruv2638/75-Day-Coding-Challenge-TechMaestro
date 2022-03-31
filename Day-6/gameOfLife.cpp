// name of Problem : Game of Life
// leetcode link of problem : https://leetcode.com/problems/game-of-life/
// author : Dhruv Nagar

class Solution {
public:
   int countLive(int i, int j, vector<vector<int>>& board){
        if(i==-1 || j==-1 || i==board.size() || j == board[0].size() || board[i][j]==0){
            return 0;
        }
        else {
            return 1;
        }        
         
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> Newboard(board.size(), vector<int> (board[0].size(), 0));
        
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                int sum = countLive(i-1, j, board) + countLive(i-1, j-1, board) + countLive(i-1, j+1, board) + countLive(i, j-1, board) + countLive(i, j+1, board) + countLive(i+1, j-1, board) + countLive(i+1, j, board) + countLive(i+1, j+1, board);
                if(board[i][j]==1){
                    if(sum==2 || sum==3){
                        Newboard[i][j] = 1;
                    }
                }
                else{
                     if(sum==3){
                        Newboard[i][j] = 1;
                    }
                }
            }
        }
         for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
               board[i][j] = Newboard[i][j];
            }
         }
       
    }
};

// Time = O(N^2)
// Space = O(1)