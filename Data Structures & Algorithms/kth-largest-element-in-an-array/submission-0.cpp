class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //维护size为k的最小堆
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto n : nums) {
            if (pq.size() < k) {
                pq.push(n);
            } else if (pq.size() == k) {
                if (n > pq.top()) {
                    pq.pop();
                    pq.push(n);
                }
            }
        }
        return pq.top();
    }
};