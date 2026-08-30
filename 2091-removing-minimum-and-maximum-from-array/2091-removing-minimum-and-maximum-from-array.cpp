class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        
         auto mini = min_element(nums.begin(), nums.end());
         auto maxi = max_element(nums.begin(), nums.end());
         int minIndex = mini - nums.begin();
         int maxIndex = maxi - nums.begin();
         int  left  = max(minIndex, maxIndex) + 1;

        int right = nums.size() - min(minIndex, maxIndex);

         int both  = min(minIndex, maxIndex) + 1
                   + nums.size() - max(minIndex, maxIndex);


                   return min({left, right, both});
        
      
        
    }
};