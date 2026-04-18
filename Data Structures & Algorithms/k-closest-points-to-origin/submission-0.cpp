class Solution {
public:
    void heapify(vector<pair<int, int>> &maxHeap, int start, int k) {
        int child = start * 2 + 1;
        while (child < k) {
            if (child + 1 < k && maxHeap[child + 1].second > maxHeap[child].second) {
                child++;
            }
            if (maxHeap[start].second < maxHeap[child].second) {
                swap(maxHeap[start], maxHeap[child]);
                start = child;
                child = child * 2 + 1;               
            } else
                break;           
        }
    }
    void buildHeap(vector<pair<int, int>> &maxHeap, int k) {
        for (int i = (k/2 -1); i >= 0; i--) {
            heapify(maxHeap, i, k);
        }
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, int>> maxHeap;
        for (int i = 0; i< k; i++) {
            maxHeap.emplace_back(i, points[i][0] * points[i][0] + points[i][1] * points[i][1]);
        }
        buildHeap(maxHeap, k);
        for (int i = k; i < points.size(); i++) {
            int temp = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if (temp < maxHeap[0].second) {
                maxHeap[0] = pair(i, temp);
                heapify(maxHeap, 0, k);
            }
        }
        vector<vector<int>> result;
        for (int i = 0; i< k; i++) {
            result.push_back(points[maxHeap[i].first]);
        }
        return result;
    }
};