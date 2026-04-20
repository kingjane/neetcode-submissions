class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l+r+1) / 2;
            if (mid == 0 || nums[mid-1] > nums[mid]) 
                return nums[mid];
            if (nums[r] >= nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return nums[l];
    }
};