class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adja(n+1);
        for (auto t : times) {
            adja[t[0]].emplace_back(t[1], t[2]);
        }

        int inf = INT_MAX / 2;
        vector<int> dist(n+1, inf);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, k);
        while(!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
            if (d > dist[node]) {
                continue;
            }
            for (auto adj : adja[node]) {
                if (dist[node] + adj.second < dist[adj.first]) {
                    dist[adj.first] = dist[node] + adj.second ;
                    pq.emplace(dist[adj.first], adj.first);
                }
            }
        }
        for (int i = 1; i<= n; i++) {
            cout<<i<<": " << dist[i] << endl;
        }
        int maxDist = *max_element(dist.begin()+1, dist.end());
        return maxDist == inf ? -1 : maxDist;
    }
};