class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,int src, int dst, int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        dist[src][0] = 0;
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto [cost, node, edges] = pq.top();
            pq.pop();

            if (node == dst)
                return cost;

            if (edges == k + 1)
                continue;

            for (auto [next, price] : adj[node]) {
                int newCost = cost + price;

                if (newCost < dist[next][edges + 1]) {
                    dist[next][edges + 1] = newCost;
                    pq.push({newCost, next, edges + 1});
                }
            }
        }
        return -1;
    }
};