class Solution {
public:
   void mergeArr(vector<int>& nums,int low ,int mid,int high){
    vector<int> temp;
    
        int left=low;
        int right=mid+1;
        // merging two sorted halves
    while(left<=mid && right<=high){

     if(nums[left]<=nums[right]){

        temp.push_back(nums[left]);
        left++;
     }else{
        temp.push_back(nums[right]);
        right++;
     }

   }
   // Remaining elements of left half
   while(left<=mid){
    temp.push_back(nums[left]);
    left++;
   }
   // Remaining elements of right half
   while(right<=high){

    temp.push_back(nums[right]);

    right++;
   }
   for(int i=low; i<=high; i++){ // copying back into nums

    nums[i]=temp[i-low];
   }
   }
        void mergeSorted( vector<int>& nums,int low,int high){
            if(low>=high){ // base case
                return;
            }
             int mid=(low+high)/2;

             mergeSorted(nums,low,mid); // sort left half

             mergeSorted(nums,mid+1,high); // sort right half
             // Merge both halves
             mergeArr(nums, low, mid, high);
        }
        vector<int> sortArray(vector<int>& nums) {

        mergeSorted(nums, 0, nums.size() - 1);
        return nums;
    }
};