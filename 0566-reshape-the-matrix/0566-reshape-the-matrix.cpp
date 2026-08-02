class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
         int n =mat.size();
         int m=mat[0].size();

         vector<vector<int>>ans(r,vector<int>(c));
         if(n*m != r*c){
           return mat;
         }
         int row=0;
         int col=0;
         for(int i=0; i<n;i++){
            for(int j=0;j<m;j++){
             ans[row][col]=mat[i][j];
             col++;
             if (col == c) {
                    col = 0;
                    row++;
                }
            }
         }
            return ans;
         }
            
         
         

         
};