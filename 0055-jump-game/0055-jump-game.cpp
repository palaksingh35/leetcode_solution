class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthestReach=0;
        for(int i =0;i <nums.size();i++){
          if(i > farthestReach)
          return false;
          farthestReach= max(farthestReach,i+nums[i]);
         }
         return true;
    }
};