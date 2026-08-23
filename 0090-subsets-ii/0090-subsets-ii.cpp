class Solution {
    void solve(vector<int>& nums,vector<int>& output,int index,vector<vector<int>>& ans){


    if(index ==nums.size()){
        ans.push_back(output);
        return;
    }//include
    int element=nums[index];
    output.push_back(element);
    solve(nums,output,index+1,ans);

    output.pop_back();
    
   index++;
    while(index < nums.size() && nums[index] == nums[index - 1]) {
            index++;
        }

        solve(nums, output, index, ans);
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        sort(nums.begin(), nums.end());
        solve(nums,output,0,ans);
        return ans;
    
    }
};