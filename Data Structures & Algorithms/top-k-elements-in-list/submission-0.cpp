class Solution {
public:
    static bool cmp(pair<int, int>& x, pair<int, int>& y) {
        return x.second > y.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (auto n : nums) {
            count[n]++;
        }
        for (auto [n, c] : count) {
            cout << n << ", " << c << endl;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> pq(cmp);
        for (auto e : count) {
            if (pq.size() < k) {
                pq.push(e);
            } else if (pq.size() == k) {
                if (pq.top().second < e.second) {
                    pq.pop();
                    pq.push(e);
                }
            }
        }
        vector<int> res;
        while(!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        
        return res;
    }
};