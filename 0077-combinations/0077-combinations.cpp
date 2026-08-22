class Solution{
    private: void solve(int n,int k ,int index, vector<int>& output, vector<vector<int>>&ans){
        if(output.size()==k){
            ans.push_back(output);
            return;
        }
        for(int i= index ; i <=n ; i++){
            output.push_back(i);

         solve(n, k, i + 1, output, ans);

          output.pop_back();


        }
        
    }


    
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(n,k,1,output,ans);
        return ans;
    }
};