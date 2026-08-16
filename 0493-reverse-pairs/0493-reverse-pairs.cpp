class Solution {
public:

    // Merge two sorted halves
    void mergeArr(vector<int>& nums, int low, int mid, int high) {

        vector<int> temp;

        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {

            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            }
            else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        // Remaining elements of left half
        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        // Remaining elements of right half
        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        // Copy back
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }


    // Count reverse pairs between two sorted halves
    int countPairs(vector<int>& nums, int low, int mid, int high) {

        int count = 0;
        int j = mid + 1;

        for (int i = low; i <= mid; i++) {

            while (j <= high && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }

            count += j - (mid + 1);
        }

        return count;
    }


    // Merge Sort + Reverse Pair counting
    int mergeSort(vector<int>& nums, int low, int high) {

        // Base case
        if (low >= high) {
            return 0;
        }

        int mid = low + (high - low) / 2;

        // Count pairs in left half
        int leftCount = mergeSort(nums, low, mid);

        // Count pairs in right half
        int rightCount = mergeSort(nums, mid + 1, high);

        // Count pairs across both halves
        int crossCount = countPairs(nums, low, mid, high);

        // Merge the two sorted halves
        mergeArr(nums, low, mid, high);

        return leftCount + rightCount + crossCount;
    }


    int reversePairs(vector<int>& nums) {

        return mergeSort(nums, 0, nums.size() - 1);
    }
};