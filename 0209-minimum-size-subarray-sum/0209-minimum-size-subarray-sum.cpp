class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int left = 0; 
        int right=0;        
        int sum = 0;           
        int mini = INT_MAX;  
        while(right < nums.size()){
            sum+=nums[right];
            while(sum >= target) {
            int length = right - left + 1;

                // Keep the smaller length
                mini = min(mini, length);
                sum-=nums[left];
                left++;
            }
            right++;
        }
        

        //  invalid subarray
        if(mini == INT_MAX) {
            return 0;
        }

        return mini;
    }
};