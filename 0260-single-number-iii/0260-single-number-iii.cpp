class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
         vector<int>ans;
        
      
        unordered_map<int, int> m;
         for(int x: nums){
            m[x]++;
        }
        for(auto x: m){
            if(x.second == 1){
            ans.push_back(x.first);
            }
        }
        return ans;
    }
};