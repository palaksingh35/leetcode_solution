class Solution {
    void solve(vector<int>& candidates, int target,int index, vector<int>& output,vector<vector<int>>& ans ){
     if( target==0){
        ans.push_back(output);
        return;
     }
     if(target < 0){
        return;
     }
     for(int i=index;i<candidates.size();i++){
        
            output.push_back(candidates[i]);
          solve(candidates,target-candidates[i],i,output,ans);
          output.pop_back();


        
     }


    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    
        vector<int> output;
        vector<vector<int>> ans;
        solve(candidates,target,0,output,ans);
        return ans;
        
    }
};