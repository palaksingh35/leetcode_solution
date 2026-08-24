class Solution {
    bool isSafe(vector<vector<char>>& board, string word,int index, int x ,int y,vector<vector<bool>>& visited){
        if (x >= 0 && x < board.size() &&
            y >= 0 && y < board[0].size() &&
            visited[x][y] == false &&
            board[x][y] == word[index]) {
            
            return true;
        }
        
        return false;
    }
 bool solve(vector<vector<char>>& board, string word, int index, int x ,int y,vector<vector<bool>>& visited ){
   
  if(index == word.size()-1)
    return true;
  
  // Current cell is being used
        visited[x][y] = true; 
  //down
  int newx=x+1 ;
    int newy=y;
 if(isSafe(board,word,index+1,newx,newy,visited)){
    if(solve(board, word,index+1,newx,newy,visited))
     return true;
    
  }
  //up
   newx=x-1 ;
    newy=y;
  if(isSafe(board,word,index+1,newx,newy,visited)){
    if(solve(board, word,index+1,newx,newy,visited))
     return true;
    }
  
  //left
   newx=x ;
   newy=y-1;
if(isSafe(board,word,index+1,newx,newy,visited)){
    if(solve(board, word,index+1,newx,newy,visited))
     return true;
    }
  
  //right
   newx=x ;
   newy=y+1;
 if(isSafe(board,word,index+1,newx,newy,visited)){
    if(solve(board, word,index+1,newx,newy,visited))
     return true;
    }
  

 visited[x][y] = false;
 return false;
}

public:
    bool exist(vector<vector<char>>& board, string word) {
       int rows = board.size();
        int cols = board[0].size();
        
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        // Try every cell as starting point
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                
                if (board[i][j] == word[0]) {
                    
                    if (solve(board, word, 0, i, j, visited))
                        return true;
                }
            }
        }
        
        return false;

        
        
    }
};