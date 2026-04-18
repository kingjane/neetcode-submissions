class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            int maxTemp = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    maxTemp = max(maxTemp, dp[j]);
                }
            }
            dp[i] = maxTemp + 1;
        }
        for (auto n: dp) {
            cout<< n << ", " << endl;
        }
        return *max_element(dp.begin(), dp.end());
    }
};