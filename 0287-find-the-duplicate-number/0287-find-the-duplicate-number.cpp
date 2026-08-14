class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       

        vector<int> freq(nums.size(), 0);

        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;

            if(freq[nums[i]] > 1) {
                return nums[i];
            }
        }

        return -1;
    }
};
        
       
    
