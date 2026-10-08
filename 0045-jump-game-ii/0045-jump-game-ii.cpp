class Solution {
 
public:
    int jump(vector<int>& nums) {
        int jumps=0;
        int left=0;
        int right=0;
        while(right< nums.size()-1){
            int maxJump=0;
            for(int i=left; i<=right;i++)
        {
            maxJump= max(maxJump,i+nums[i]);
        }
        left=right+1;
        jumps++;
        right=maxJump;
        }
       
    
    return jumps;
    }
    
};