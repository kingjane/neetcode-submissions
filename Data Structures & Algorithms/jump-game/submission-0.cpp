class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int m = 0;
        for (int i  = 0; i <= m; i++) {
            m = max (m, i + nums[i]);
            if (m >= n -1) return true;
        }
        return false;
    }
};