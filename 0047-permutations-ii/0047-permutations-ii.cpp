class Solution {
    void solve(vector<int>& nums , int index , vector<vector<int>>& ans){
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        } 
        set<int> used;
        for(int i=index;i <nums.size();i++){
            if(used.count(nums[i])) {
        continue;
    }

           used.insert(nums[i]); 
         swap(nums[index],nums[i]);
         solve(nums,index+1,ans);
         swap(nums[index],nums[i]);
            }
        
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums,0,ans);
        return ans;
    }
};