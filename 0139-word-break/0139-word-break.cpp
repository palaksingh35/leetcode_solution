class Solution {
   bool solve(string s, int start, vector<string>& wordDict,vector<int>& dp){
    
    if(start == s.size()){
        return true;
    }
    if(dp[start] != -1){
        return dp[start];
    }


    for(int end = start; end < s.size(); end++){

        string word = s.substr(start, end - start + 1);

        for(int j = 0; j < wordDict.size(); j++){

            if(word == wordDict[j]){

                if(solve(s, end + 1, wordDict,dp)){
                  return dp[start] = true;
                }

            }
        }
    }

   
    return dp[start] = false;
}
public:
    bool wordBreak(string s, vector<string>& wordDict) {
         vector<int> dp(s.size(), -1);
     return solve(s,0,wordDict ,dp);
    }
};