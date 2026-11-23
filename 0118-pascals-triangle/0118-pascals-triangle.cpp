class Solution {
   
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
          vector<int> prev;
         vector<int> curr;
         
        for(int i=0; i< numRows;i++){
            
            for(int j=0; j<=i;j++){
               if(j==0 || j==i)
                {
                    curr.push_back(1);
                } else{
                curr.push_back(prev[j-1] + prev[j]);
              
                }
            }
            ans.push_back(curr);
             prev = curr;
               curr.clear();
        }


    
       
        return ans;
    }
};