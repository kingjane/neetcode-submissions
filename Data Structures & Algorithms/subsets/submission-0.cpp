class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& curr, int n, vector<int>& nums) {
        if (n == nums.size()) {
            res.push_back(curr);
            return;
        }
        dfs(res, curr, n+1, nums);
        curr.push_back(nums[n]);
        dfs(res, curr, n+1, nums);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        dfs(res, curr, 0, nums);
        return res;
    }
};