class Solution {
public:
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    if (nums1.size() > nums2.size())
    return findMedianSortedArrays(nums2, nums1);
        int m =nums1.size();
        int n=nums2.size();
        int start=0;
        int end=nums1.size();
        int total = m+ n;
        int left =(total+1)/2;

           while(start <= end) {
           // Partition of nums1
            int i = (start + end) / 2;

            // Partition of nums2
            int j = left - i;
        
         int leftA  = (i == 0) ? INT_MIN : nums1[i - 1];
         int rightA = (i == m) ? INT_MAX : nums1[i];

        int leftB  = (j == 0) ? INT_MIN : nums2[j - 1];
          int rightB = (j == n) ? INT_MAX : nums2[j];
         //  checking Correct partition
            if (leftA <= rightB && leftB <= rightA) {

                //  for Odd
                if (total % 2 != 0)
                    return max(leftA, leftB);

                //  for Even
                return (max(leftA, leftB) +
                        min(rightA, rightB)) / 2.0;
            }
             else if (leftA > rightB) {
                end = i - 1;
            }
            else {
                start = i + 1;
            }
        
        }
        return 0;


    }
};