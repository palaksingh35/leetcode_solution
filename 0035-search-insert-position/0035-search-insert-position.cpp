class Solution {
public:
    int searchInsert(vector<int>& nums,int s, int e,  int target) {
        if(s>e){
            return s;
        }
        int mid =s+(e-s)/2;
        if(nums[mid]== target){
            return mid;
        }
        if(target<nums[mid]){
          return  searchInsert( nums, s, mid-1, target) ;
        }else{
             return searchInsert( nums, mid+1,e, target) ;
        }
    }
        int searchInsert(vector<int>& nums, int target) {
        return searchInsert(nums, 0, nums.size() - 1, target);

    
    }
};