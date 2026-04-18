class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int pp = 0, p = 0;
        int curr = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            curr = max(nums[i] + pp, p);
            pp = p;
            p = curr; 
        }
        pp = 0, p = 0;
        int curr1 = 0;
        for (int i = 1; i < nums.size(); i++) {
            curr1 = max(nums[i] + pp, p);
            pp = p;
            p = curr1;
        }
        curr = max (curr, curr1);
        return curr;
    }
};