class Solution {
    void solve(vector<int>& candidates, int target,int index,vector<int>& output,vector<vector<int>>& ans){
       sort(candidates.begin(), candidates.end());
        if(target==0){
        ans.push_back(output);
        return;
        }
        if(target <0){
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i > index && candidates[i] == candidates[i-1])// handling duplicates
              continue;
            output.push_back(candidates[i]);
            solve(candidates,target-candidates[i],i+1,output,ans);
            output.pop_back();
            
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> output;
        vector<vector<int>> ans;
        solve(candidates,target,0,output,ans);
        return ans;
        
    }
};