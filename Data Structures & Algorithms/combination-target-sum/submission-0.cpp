class Solution {
public:
    vector<vector<int>> res;
    vector<int> set;
    void dfs(int idx, int sum, vector<int>& candi, int target) {
        if (sum == target) {
            res.push_back(set);
            return;
        }
        else if (sum > target) {
            return;
        }
        if (idx == candi.size()) return;
        dfs(idx+1, sum, candi, target);
        sum += candi[idx];
        set.push_back(candi[idx]);
        dfs(idx, sum, candi, target);
        sum -= candi[idx];
        set.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {       
        dfs(0, 0, candidates, target);
        return res;
    }
};