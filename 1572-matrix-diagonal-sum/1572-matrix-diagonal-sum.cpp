class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int sum=0;
        // first diagonal
        for(int i=0; i<n; i++){
            sum=sum+mat[i][i];
        }
        // second diagonal
        int col=n-1;
        for(int i=0;i<n;i++){
            sum=sum+mat[i][col];
            col--;
        }
        // now removing duplicate element
        if(n%2==1){
            sum=sum-mat[n/2][n/2];
        }
        return sum; 
    }
};