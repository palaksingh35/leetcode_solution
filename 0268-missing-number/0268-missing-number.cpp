class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i <= n; i++) {

            bool found = false;

            for(int j = 0; j < n; j++) {

                if(nums[j] == i) {
                    found = true;
                    break;
                }
            }

            if(found == false) {
                return i;
            }
        }

        return -1;
    }
};