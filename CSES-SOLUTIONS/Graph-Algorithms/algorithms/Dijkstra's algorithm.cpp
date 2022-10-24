class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        using ip = pair<int, int>;
        vector<vector<ip>> adj(n + 1);
        for (auto& t : times) adj[t[0]].push_back({t[1], t[2]});
        priority_queue<ip, vector<ip>, greater<ip>> pq;
        vector<int> dist(n + 1, INT_MAX);
        vector<bool> visited(n + 1, false);
        pq.push({0, k});
        dist[k] = 0;
        while (!pq.empty()) {
            auto [n_cost, node] = pq.top(); pq.pop();
            visited[node] = true;
            if (dist[node] < n_cost) continue;  // Optimization: skip node if we already find better option.
            for (auto& [next, cost] : adj[node]) {
                if (visited[next] == true) continue; // Optimization: do not re-visit nodes.
                if (dist[next] > dist[node] + cost) {
                    dist[next] = dist[node] + cost;
                    pq.push({dist[next], next});
                }
            }
        }
        int res = 0;
        for_each(dist.begin() + 1, dist.end(), [&](int d) {
            res = max(res, d);
        });
        return res == INT_MAX ? -1 : res;
    }
};
