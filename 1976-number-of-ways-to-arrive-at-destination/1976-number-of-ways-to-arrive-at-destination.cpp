class Solution {
public:
    int countPaths(int n, vector<vector<int>>& elist) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto it : elist) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> dist(n, LLONG_MAX);

        vector<int> ways(n, 0);

        priority_queue<
            pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        const int MOD = 1e9 + 7;

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while (!pq.empty()) {

            long long cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (cost > dist[node])
                continue;

            for (auto it : adj[node]) {

                int next = it.first;
                long long newCost = cost + it.second;

                if (newCost < dist[next]) {

                    dist[next] = newCost;
                    ways[next] = ways[node];
                    pq.push({newCost, next});
                }

                else if (newCost == dist[next]) {

                    ways[next] = (ways[next] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};