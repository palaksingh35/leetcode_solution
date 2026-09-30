class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> arr;
         vector<string> ans;
         
         for(int i = 0; i < names.size(); i++) {
          arr.push_back({heights[i], names[i]});
          
         }
         sort(arr.rbegin(), arr.rend());
        for(auto x :arr){
            ans.push_back(x.second);
        }
        return ans;
    }
};