class Solution {
    void solve(int n,int  opening ,int  closing,string& output,vector<string>&ans){
      
        if(opening==n && closing ==n){
            ans.push_back(output);
            return;
        }
        
           if(opening <n ){
                  output.push_back('(');
                solve(n,opening+1,closing,output,ans); 
                output.pop_back();           
        }
        if(closing <opening){
           output.push_back(')');
          solve(n,opening,closing+1,output,ans);
          output.pop_back();  
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
      string output="";
        solve(n,0,0,output,ans);
        return ans;
        
    }
};