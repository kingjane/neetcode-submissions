class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int inserted = false;
        for (auto inte : intervals) {
            if (inte[1] < newInterval[0]) {
                res.push_back(inte);
            } else if (inte[0] > newInterval[1]) {
                //插入合并后的interval，只在第一次
                if (!inserted) {
                    res.push_back(newInterval);
                    inserted = true;
                }
                res.push_back(inte);
            } else {
                //重叠interval
                newInterval[0] = min(inte[0], newInterval[0]);
                newInterval[1] = max(inte[1], newInterval[1]);
            }
        }
        if (!inserted) res.push_back(newInterval);
        return res;
    }
};